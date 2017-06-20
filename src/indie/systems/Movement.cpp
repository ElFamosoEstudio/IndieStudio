//
// Movement.cpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Sun Jun 18 15:29:28 2017 akram abd-ali
// Last update Tue Jun 20 02:45:03 2017 akram abd-ali
//

#include <vector3d.h>
#include "Movement.hpp"

indie::system::Movement::Movement()
{
  auto key = engine::eventManager().
    subscribe(event::GO_UP, &indie::system::Movement::goUp, this);
  _eventKeys[event::GO_UP] = key;
  key = engine::eventManager().
    subscribe(event::GO_DOWN, &indie::system::Movement::goDown, this);
  _eventKeys[event::GO_DOWN] = key;
  key = engine::eventManager().
    subscribe(event::GO_LEFT, &indie::system::Movement::goLeft, this);
  _eventKeys[event::GO_LEFT] = key;
  key = engine::eventManager().
    subscribe(event::GO_RIGHT, &indie::system::Movement::goRight, this);
  _eventKeys[event::GO_RIGHT] = key;
}

indie::system::Movement::~Movement()
{
}

void	indie::system::Movement::goLeft(ecs::Entity entity)
{
  auto const& it = _movements.find(entity);
  if (it == _movements.end())
    _movements[entity] = {false, false, false, false};
  _movements[entity][LEFT] = true;
}

void	indie::system::Movement::goRight(ecs::Entity entity)
{
  auto const& it = _movements.find(entity);
  if (it == _movements.end())
    _movements[entity] = {false, false, false, false};
  _movements[entity][RIGHT] = true;
}

void	indie::system::Movement::goUp(ecs::Entity entity)
{
  auto const& it = _movements.find(entity);
  if (it == _movements.end())
    _movements[entity] = {false, false, false, false};
  _movements[entity][UP] = true;
}

void	indie::system::Movement::goDown(ecs::Entity entity)
{
  auto const& it = _movements.find(entity);
  if (it == _movements.end())
    _movements[entity] = {false, false, false, false};
  _movements[entity][DOWN] = true;
}


void	indie::system::Movement::update()
{
  for (auto& it : _movements)
    {
      auto id = it.first;
      auto const& speed = engine::entityManager().getComponent<indie::component::Speed>(id);;
      auto const& move = engine::entityManager().getComponent<indie::component::Movement>(id);
      auto& transform = engine::entityManager().getComponent<indie::component::Transform>(id);
      auto reset = [&]() {
	for (int i = 0; i < 4; ++i)
	  {
	    it.second[i] = false;
	  }
      };
      if (!transform || !speed || !move)
	{
	  reset();
	  continue ;
	}
      int three = 0;
      float len = ((move->value * speed->value) * 2);
      float sqlen = 0.707 * len;
      for (int i = 0; i < 4; ++i)
	{
	  if (it.second[i] == true)
	    three++;
	}
      if ((three >= 3) || (it.second[UP] && it.second[DOWN]) || (it.second[LEFT] && it.second[RIGHT]))
	{
	  reset();
	  continue ;
	}
      bool done = false;
      if ((it.second[UP]) && (it.second[LEFT]))
	{
	  done = true;
	  transform->position.Y += sqlen;
	  transform->position.X += sqlen;
	  transform->rotation.Z = 45;
	}
      else if ((it.second[UP]) && (it.second[RIGHT]))
	{
	  done = true;
	  transform->position.Y += sqlen;
	  transform->position.X -= sqlen;
	  transform->rotation.Z = 315;
	}
      else if ((it.second[DOWN]) && (it.second[LEFT]))
	{
	  done = true;
	  transform->position.Y -= sqlen;
	  transform->position.X += sqlen;
	  transform->rotation.Z = 135;
	}
      else if ((it.second[DOWN]) && (it.second[RIGHT]))
	{
	  done = true;
	  transform->position.Y -= sqlen;
	  transform->position.X -= sqlen;
	  transform->rotation.Z = 225;
	}
      if (done == false)
	{
	  if (it.second[UP])
	    {
	      transform->position.Y += len;
	      transform->rotation.Z = 0;
	    }
	  else if (it.second[DOWN])
	    {
	      transform->position.Y -= len;
	      transform->rotation.Z = 180;
	    }
	  else if (it.second[LEFT])
	    {
	      transform->position.X += len;
	      transform->rotation.Z = 90;
	    }
	  else if (it.second[RIGHT])
	    {
	      transform->position.X -= len;
	      transform->rotation.Z = 270;
	    }
	}
      reset();
    }
}

ecs::SysType	indie::system::Movement::type() const
{
  return (system::MOVEMENT);
}

ecs::ISystem	*indie::system::Movement::create()
{
  return new Movement;
}
