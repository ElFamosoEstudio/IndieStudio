//
// Bomb.cpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 02:28:47 2017 akram abd-ali
// Last update Sun Jun 18 16:33:25 2017 akram abd-ali
//

#include "indie.hpp"
# include <vector3d.h>

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
      auto& bomb = it.second;
      if (bomb->count > 0)
	{
	  auto &remote = engine::entityManager().getComponent<component::RemoteExplosion>(id);
	  auto &playerId = engine::entityManager().getComponent<component::PlayerId>(id);
	  auto &transform = engine::entityManager().getComponent<component::Transform>(id);
	  if (!transform || !playerId)
	    continue ;
	  if (!remote)
	    {
	      engine::entityManager()
		.create(entity::BOMB,
			component::Transform(transform->position.X,
					     transform->position.Y,
					     transform->position.Z),
			component::Spreadable(bomb->range,
					      bomb->propagationMask),
			component::PowerInfo(bomb->power),
			component::PlayerId(playerId->id),
			component::Timer(3000, event::DETONATE_BOMB));
	    }
	  else
	    {
	      engine::entityManager()
		.create(entity::BOMB,
			component::Transform(transform->position.X,
					     transform->position.Y,
					     transform->position.Z),
			component::Spreadable(bomb->range,
					      bomb->propagationMask),
			component::PowerInfo(bomb->power),
			component::PlayerId(playerId->id));
	    }
	  bomb->count -= 1;
	}
    }
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
	  component::Transform trans(transform->position.X,
				     transform->position.Y,
				     transform->position.Z);
	  if (i != 0)
	    {
	      dir = 1 << (i - 1);
	      set3DPropagationPos(trans, dir);
	    }
	  auto id = engine::entityManager()
	    .create(entity::EXPLOSION,
		    component::Damage(powerInfo->power),
		    component::Transform(trans.position.X,
					 trans.position.Y,
					 trans.position.Z),
		    component::Spreadable((spreadable->range - 1),
					  dir),
		    component::PlayerId(playerId->id),
		    component::Timer(50, event::NO_DAMAGE));
	  engine::eventManager().emit(event::NO_DAMAGE, id);
	}
    }
}

void	indie::system::Bomb::removeBomb(ecs::Entity entity)
{
  auto&	bombInfo = engine::entityManager().getComponent<component::BombInfo>(entity);
  if (bombInfo)
    bombInfo->count += 1;
  auto& render = engine::entityManager().getComponent<component::Renderer3d>(entity);
  if (render && render->mesh)
    gfx::sceneManager()->addToDeletionQueue(render->mesh);
  engine::entityManager().removeEntity(entity);
}

indie::system::Bomb::Bomb()
{
  auto key = engine::eventManager().subscribe(event::DROP_BOMB, &indie::system::Bomb::dropBomb, this);
  _subKeys[event::DROP_BOMB] = key;
  key = engine::eventManager().subscribe(event::DROP_BOMB_ERR, &indie::system::Bomb::removeBomb, this);
  _subKeys[event::DROP_BOMB_ERR] = key;
}

indie::system::Bomb::~Bomb()
{
  // for (auto const& it : _subKeys)
  //   engine::eventManager().unsubscribe(it.first, it.second);
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
