//
// Movement.cpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sun Jun 18 15:29:28 2017 akram abd-ali
// Last update Sun Jun 18 16:20:47 2017 akram abd-ali
//

#include <vector3d.h>
#include "Movement.hpp"

indie::system::Movement::Movement()
{
  auto key = engine::eventManager().
    subscribe(event::GO_UP, &indie::system::Movement::goUp, this);
  _subKeys[event::GO_UP] = key;
  key = engine::eventManager().
    subscribe(event::GO_DOWN, &indie::system::Movement::goDown, this);
  _subKeys[event::GO_DOWN] = key;
  key = engine::eventManager().
    subscribe(event::GO_LEFT, &indie::system::Movement::goLeft, this);
  _subKeys[event::GO_LEFT] = key;
  key = engine::eventManager().
    subscribe(event::GO_RIGHT, &indie::system::Movement::goRight, this);
  _subKeys[event::GO_RIGHT] = key;
}

indie::system::Movement::~Movement()
{
  // for (auto const& it : _subKeys)
  //   engine::eventManager().unsubscribe(it.first, it.second);
}


void	indie::system::Movement::goLeft(ecs::Entity entity)
{
  auto& speeds = engine::entityManager().getAllComponents<indie::component::Speed>();

  for (auto& it : speeds)
    {
      auto id = it.first;
      auto const& speed = it.second;
      auto const& move = engine::entityManager().getComponent<indie::component::Movement>(id);
      if (!move)
	continue ;
      auto& transform = engine::entityManager().getComponent<indie::component::Transform>(id);
      if (!transform)
	continue ;
      transform->position.X += (move->value * speed->value);
    }
}

void	indie::system::Movement::goRight(ecs::Entity entity)
{
  auto& speeds = engine::entityManager().getAllComponents<indie::component::Speed>();

  for (auto& it : speeds)
    {
      auto id = it.first;
      auto const& speed = it.second;
      auto const& move = engine::entityManager().getComponent<indie::component::Movement>(id);
      if (!move)
	continue ;
      auto& transform = engine::entityManager().getComponent<indie::component::Transform>(id);
      if (!transform)
	continue ;
      transform->position.X -= (move->value * speed->value);
    }
}

void	indie::system::Movement::goUp(ecs::Entity entity)
{
  auto& speeds = engine::entityManager().getAllComponents<indie::component::Speed>();

  for (auto& it : speeds)
    {
      auto id = it.first;
      auto const& speed = it.second;
      auto const& move = engine::entityManager().getComponent<indie::component::Movement>(id);
      if (!move)
	continue ;
      auto& transform = engine::entityManager().getComponent<indie::component::Transform>(id);
      if (!transform)
	continue ;
      transform->position.Y += (move->value * speed->value);
    }
}

void	indie::system::Movement::goDown(ecs::Entity entity)
{
  auto& speeds = engine::entityManager().getAllComponents<indie::component::Speed>();

  for (auto& it : speeds)
    {
      auto id = it.first;
      auto const& speed = it.second;
      auto const& move = engine::entityManager().getComponent<indie::component::Movement>(id);
      if (!move)
	continue ;
      auto& transform = engine::entityManager().getComponent<indie::component::Transform>(id);
      if (!transform)
	continue ;
      transform->position.Y -= (move->value * speed->value);
    }
}


void	indie::system::Movement::update()
{
  
}

ecs::SysType	indie::system::Movement::type() const
{
  return (system::MOVEMENT);
}

ecs::ISystem	*indie::system::Movement::create()
{
  return new Movement;
}
