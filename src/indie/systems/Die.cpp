//
// Die.cpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Tue Jun 20 19:29:34 2017 akram abd-ali
// Last update Wed Jun 21 17:21:05 2017 akram abd-ali
//

#include "Die.hpp"

void	indie::system::Die::killPlayer(ecs::Entity entity)
{
  auto& lifes = engine::entityManager().getComponent<component::LifeNumber>(entity);
  auto& render = engine::entityManager().getComponent<component::Renderer3d>(entity);
  if (!lifes)
    return ;
  if (lifes->value)
    {
      if (render && render->mesh)
	render->mesh->setVisible(false);
      lifes->value -= 1;
      component::Timer  timez(3000, event::SET_HP);
      engine::entityManager().removeComponent<component::HP>(entity);
      engine::entityManager().addComponent(entity, timez, true);
      engine::eventManager().emit(event::RESPAWN, entity);
    }
  else
    {
      engine::eventManager().emit(event::REMOVE_SKEL, entity);
      if (render && render->mesh)
	gfx::sceneManager()->addToDeletionQueue(render->mesh);
      engine::entityManager().removeEntity(entity);
    }
}

void	indie::system::Die::crateToBonus(ecs::Entity entity)
{
  auto const	&player = indie::engine::entityManager().getComponent<component::BombInfo>(entity);
  auto		&crate = indie::engine::entityManager().getComponent<component::TagCrate>(entity);
  if (player)
    {
      killPlayer(entity);
      return ;
    }
  if (!crate)
    return ;
  engine::eventManager().emit(event::REMOVE_SKEL, entity);
  auto& render = engine::entityManager().getComponent<component::Renderer3d>(entity);
  if (render && render->mesh)
    render->mesh->setVisible(false);
  engine::eventManager().emit(event::CREATE_BONUS, entity);
  if (render && render->mesh)
    gfx::sceneManager()->addToDeletionQueue(render->mesh);
  engine::entityManager().removeEntity(entity);
}

indie::system::Die::Die()
{
  auto key = engine::eventManager().
    subscribe(event::HIT, &indie::system::Die::crateToBonus, this);
  _eventKeys[event::HIT] = key;
}

void	indie::system::Die::update()
{
  
}

ecs::SysType	indie::system::Die::type() const
{
  return (system::DIE);
}

ecs::ISystem	*indie::system::Die::create()
{
  return new Die;
}
