//
// Explosion.cpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sun Jun 18 06:01:58 2017 akram abd-ali
// Last update Sun Jun 18 15:02:04 2017 akram abd-ali
//

#include "indie.hpp"
#include "Explosion.hpp"
#include "Bomb.hpp"
#include <vector3d.h>

void	indie::system::Explosion::spreadExplosion(ecs::Entity entity)
{
  auto		&ent = indie::engine::entityManager();
  auto& damage = engine::entityManager().getComponent<component::Damage>(entity);
  auto&	spreadable = engine::entityManager().getComponent<component::Spreadable>(entity);
  auto& transform = engine::entityManager().getComponent<component::Transform>(entity);
  auto& playerId = engine::entityManager().getComponent<component::PlayerId>(entity);

  if ((!damage)
      || (!playerId)
      || (!transform)
      || (!spreadable)
      || (spreadable->range == 0)
      || (spreadable->propagationMask == 0))
    {
      removeExplosion(entity);
      return ;
    }

  uint8_t dir = 0;
  for (uint8_t i = 1; i < 8; ++i)
    {
      if ((1 << (i - 1)) & spreadable->propagationMask)
	{
	  component::Transform trans(transform->position.X,
				     transform->position.Y,
				     transform->position.Z);
	  dir = 1 << (i - 1);
	  Bomb::set3DPropagationPos(trans, dir);
	  auto id = engine::entityManager()
	    .create(entity::EXPLOSION,
		    component::Damage(damage->value),
		    component::Transform(trans.position.X,
					 trans.position.Y,
					 trans.position.Z),
		    component::Spreadable((spreadable->range - 1),
					  dir),
		    component::PlayerId(playerId->id),
		    component::Timer(50, event::SPREAD_EXPLOSION));
	  engine::eventManager().emit(event::SPREAD_EXPLOSION, id);
	}
    }
  ent.addComponentEmplace<component::Timer>(entity, 300, event::EXPLOSION_RM);
}

void	indie::system::Explosion::removeExplosion(ecs::Entity entity)
{
  auto& render = engine::entityManager().getComponent<component::Renderer3d>(entity);
  if (render && render->mesh)
    gfx::sceneManager()->addToDeletionQueue(render->mesh);
  engine::entityManager().removeEntity(entity);
}

indie::system::Explosion::Explosion()
{
  auto key = engine::eventManager().subscribe(event::SPREAD_EXPLOSION,
					      &indie::system::Explosion::spreadExplosion,
					      this);
  _subKeys[event::SPREAD_EXPLOSION] = key;
  key = engine::eventManager().subscribe(event::EXPLOSION_RM,
					 &indie::system::Explosion::removeExplosion,
					 this);
  _subKeys[event::EXPLOSION_RM] = key;
}

indie::system::Explosion::~Explosion()
{
  // for (auto const& it : _subKeys)
  //   engine::eventManager().unsubscribe(it.first, it.second);
}

void	indie::system::Explosion::update() {

}

ecs::SysType	indie::system::Explosion::type() const
{
  return (system::EXPLOSION);
}

ecs::ISystem	*indie::system::Explosion::create()
{
  return new Explosion;
}
