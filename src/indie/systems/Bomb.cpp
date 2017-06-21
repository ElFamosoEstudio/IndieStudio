//
// Bomb.cpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Sat Jun 17 02:28:47 2017 akram abd-ali
// Last update Wed Jun 21 18:49:21 2017 akram abd-ali
//

#include "Bomb.hpp"
#include "Timer.hpp"
#include <vector3d.h>

void indie::system::Bomb::set3DPropagationPos(component::Transform& trans, uint8_t spread)
{
  switch (spread)
    {
    case 1:
      trans.position.X += 1;
      trans.position.Y += 1;
      break;
    case 2:
      trans.position.Y += 1;
      break;
    case 4:
      trans.position.X -= 1;
      trans.position.Y += 1;
      break;
    case 8:
      trans.position.X += 1;
      break;
    case 16:
      trans.position.X -= 1;
      break;
    case 32:
      trans.position.X += 1;
      trans.position.Y -= 1;
      break;
    case 64:
      trans.position.Y -= 1;
      break;
    case 128:
      trans.position.X -= 1;
      trans.position.Y -= 1;
      break;
    default:
      break;
    }
}

void	indie::system::Bomb::dropBomb(ecs::Entity entity)
{
  auto&	bombInfos = engine::entityManager().getAllComponents<component::BombInfo>();

  for (auto& it : bombInfos)
    {
      auto id = it.first;
      if (id == entity)
	{
	  auto& bomb = it.second;
	  if (bomb->count > 0)
	    {
	      auto &remote = engine::entityManager().getComponent<component::RemoteExplosion>(id);
	      auto &playerId = engine::entityManager().getComponent<component::PlayerId>(id);
	      auto &transform = engine::entityManager().getComponent<component::Transform>(id);
	      if (!transform || !playerId)
		continue ;
	      component::Transform t;
	      t.scale.X = 0.33;
	      t.scale.Y = 0.33;
	      t.scale.Z = 0.33;
	      t.position.X = transform->position.X;
	      t.position.Y = transform->position.Y;
	      t.position.Z = transform->position.Z;
	      if (!remote)
		{
		  auto id = engine::entityManager()
		    .create(entity::BOMB,
			    component::Transform(t),
			    component::Spreadable(bomb->range,
						  bomb->propagationMask),
			    component::PowerInfo(bomb->power),
			    component::PlayerId(playerId->id),
			    component::Timer(2500, event::DETONATE_BOMB));
		  engine::eventManager().emit(event::BOMB_DROPPED, id);
		}
	      else
		{
		  auto id = engine::entityManager()
		    .create(entity::BOMB,
			    component::Transform(t),
			    component::Spreadable(bomb->range,
						  bomb->propagationMask),
			    component::PowerInfo(bomb->power),
			    component::PlayerId(playerId->id),
			    component::Timer(200, event::COL_ADD_ELEM));
		  engine::eventManager().emit(event::BOMB_DROPPED, id);
		}
	      bomb->count -= 1;
	    }
	}
    }
}

void	indie::system::Bomb::preExplode(ecs::Entity entity)
{
  engine::eventManager().emit(event::COL_ADD_ELEM, entity);
  engine::entityManager().addComponentEmplace<component::Timer>(entity, 2800, event::DETONATE_BOMB);
}

void	indie::system::Bomb::explode(ecs::Entity entity)
{
  auto&	powerInfo = engine::entityManager().getComponent<component::PowerInfo>(entity);
  auto&	spreadable = engine::entityManager().getComponent<component::Spreadable>(entity);
  auto& transform = engine::entityManager().getComponent<component::Transform>(entity);
  auto& playerId = engine::entityManager().getComponent<component::PlayerId>(entity);
  if ((!powerInfo)
      || (!playerId)
      || (!transform)
      || (!spreadable)
      || (spreadable->range == 0)
      || (spreadable->propagationMask == 0))
    {
      removeBomb(entity);
      return ;
    }
  
  uint8_t dir = 0;
  for (uint8_t i = 0; i < 8; ++i)
    {
      if ((i == 0)
	  || ((1 << (i - 1)) & spreadable->propagationMask))
	{
	  component::Transform t;
	  t.scale.X = 0.25;
	  t.scale.Y = 0.25;
	  t.scale.Z = 0.25;
	  t.position.X = transform->position.X;
	  t.position.Y = transform->position.Y;
	  t.position.Z = transform->position.Z;
	  if (i != 0)
	    {
	      dir = 1 << (i - 1);
	      set3DPropagationPos(t, dir);
	    }
	  auto id = engine::entityManager()
	    .create(entity::EXPLOSION,
		    component::Damage(powerInfo->power),
		    component::Transform(t),
		    component::Spreadable((spreadable->range - 1),
					  dir),
		    component::PlayerId(playerId->id),
		    component::Timer(50, event::SPREAD_EXPLOSION));
	  engine::eventManager().emit(event::CHECK_DAMAGE, id);
	}
    }
  removeBomb(entity);
}

void	indie::system::Bomb::removeBomb(ecs::Entity entity)
{
  auto&	pId = engine::entityManager().getComponent<component::PlayerId>(entity);
  if (pId)
    {
      auto&	bombInfos = engine::entityManager().getAllComponents<component::BombInfo>();

      for (auto& it : bombInfos)
	{
	  auto id = it.first;
	  auto&	pIdB = engine::entityManager().getComponent<component::PlayerId>(id);
	  if (!pIdB)
	    continue ;
	  if (pIdB->id == pId->id)
	    {
	      auto& bomb = it.second;
	      bomb->count += 1;
	    }
	}
    }
  engine::eventManager().emit(event::REMOVE_SKEL, entity);
  auto& render = engine::entityManager().getComponent<component::Renderer3d>(entity);
  if (render && render->mesh)
    gfx::sceneManager()->addToDeletionQueue(render->mesh);
  engine::entityManager().removeEntity(entity);
}

indie::system::Bomb::Bomb()
{
  auto key = engine::eventManager().subscribe(event::DROP_BOMB, &indie::system::Bomb::dropBomb, this);
  _eventKeys[event::DROP_BOMB] = key;
  key = engine::eventManager().subscribe(event::DROP_BOMB_ERR, &indie::system::Bomb::removeBomb, this);
  _eventKeys[event::DROP_BOMB_ERR] = key;
  key = engine::eventManager().subscribe(event::DETONATE_BOMB, &indie::system::Bomb::explode, this);
  _eventKeys[event::DETONATE_BOMB] = key;
}

indie::system::Bomb::~Bomb()
{
}

void	indie::system::Bomb::update() {

}

ecs::SysType	indie::system::Bomb::type() const
{
  return (system::BOMB);
}

ecs::ISystem	*indie::system::Bomb::create()
{
  return new Bomb;
}
