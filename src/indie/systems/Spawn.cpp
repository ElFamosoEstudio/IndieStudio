//
// Spawn.cpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Sun Jun 18 20:21:40 2017 akram abd-ali
// Last update Tue Jun 20 22:57:34 2017 Noam Silvy
//

#include "Keycodes.h"
#include "Spawn.hpp"

void	indie::system::Spawn::respawn(ecs::Entity entity)
{

}

indie::system::Spawn::Spawn()
{
  auto key = engine::eventManager().
    subscribe(event::DIE, &indie::system::Spawn::respawn, this);
  _eventKeys[event::DIE] = key;
    component::Transform t;
  t.scale.X = 0.25;
  t.scale.Y = 0.25;
  t.scale.Z = 0.25;
  auto id = indie::engine::entityManager().create(indie::entity::PLAYER,
						  component::PlayerId(1),
						  t);
  indie::engine::entityManager().addComponent(id, t, true);
  component::KeyMaps mapStack;
  component::KeyMap  keys({{event::GO_RIGHT,
	  {InputState::DOWN,
	      {irr::KEY_RIGHT}}},
	    {event::GO_LEFT,
		{InputState::DOWN,
		    {irr::KEY_LEFT}}},
	  {event::GO_UP,
	      {InputState::DOWN,
		  {irr::KEY_UP}}},
	    {event::GO_DOWN,
		{InputState::DOWN,
		    {irr::KEY_DOWN}}},
	      {event::DROP_BOMB,
		  {InputState::PRESSED,
		      {irr::KEY_SPACE}}}});
  mapStack.id = indie::component::KEYBOARD_ID;
  mapStack.keymaps.push_front({keys, indie::component::KeyMapState::NORMAL});
  indie::engine::entityManager().addComponent(id, mapStack, true);
  indie::engine::entityManager().addComponent(id, mapStack, true);
}

void	indie::system::Spawn::update()
{
}

ecs::SysType	indie::system::Spawn::type() const
{
  return (system::SPAWN);
}

ecs::ISystem	*indie::system::Spawn::create()
{
  return new Spawn;
}
