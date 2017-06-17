//
// Bomb.cpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 02:28:47 2017 akram abd-ali
// Last update Sun Jun 18 01:06:36 2017 akram abd-ali
//

#include "Bomb.hpp"
#include "Spreadable.hpp"
#include "indie.hpp"
# include <vector3d.h>

void	indie::system::Bomb::dropBomb(ecs::Entity entity)
{
  auto&	bombInfos = engine::entityManager().getAllComponents<component::BombInfo>();

  for (auto& it : bombInfos)
    {
      auto id = it.first;
      auto& bomb = it.second;
      // auto &timer = engine::entityManager().getComponent<component::RemoteExplosion>(id);
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
  // auto& 2dPos = engine::entityManager().getComponent<component::2DPos>(entity);

  if ((!powerInfo)
      || (!playerId)
      || (!transform)
      || (!spreadable)
      // || (!2dPos)
      || (spreadable->range == 0)
      || (spreadable->propagationMask == 0))
    {
      removeBomb(entity);
      return ;
    }
  for (uint8_t i = 0; i < 8; ++i)
    {
      if ((i == 0)
	  || ((1 << i) & spreadable->propagationMask))
	{
	  engine::entityManager()
	    .create(entity::EXPLOSION,
		    component::Damage(powerInfo->power),
		    component::Transform(transform->position.X,
					 transform->position.Y,
					 transform->position.Z),
		    component::Spreadable(bomb->range,
					  bomb->propagationMask),
		    component::PlayerId(playerId->id),
		    component::Timer(3000, event::DETONATE_BOMB));
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
  for (auto const& it : _subKeys)
    engine::eventManager().unsubscribe(it.first, it.second);
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
