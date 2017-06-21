//
// Spawn.cpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Sun Jun 18 20:21:40 2017 akram abd-ali
// Last update Wed Jun 21 17:17:12 2017 akram abd-ali
//

#include "Keycodes.h"
#include "Spawn.hpp"

void	indie::system::Spawn::giveHP(ecs::Entity entity)
{
  engine::entityManager().addComponent(entity, component::HP(1), true);
}

void	indie::system::Spawn::respawn(ecs::Entity entity)
{
  auto const& respawn = engine::entityManager().getComponent<component::Respawn>(entity);
  if (!respawn)
    return ;
  indie::engine::entityManager().addComponent(entity, respawn->transform, true);
}

indie::system::Spawn::Spawn()
{
  auto key = engine::eventManager().
    subscribe(event::RESPAWN, &indie::system::Spawn::respawn, this);
  _eventKeys[event::RESPAWN] = key;
  key = engine::eventManager().
    subscribe(event::SET_HP, &indie::system::Spawn::giveHP, this);
  _eventKeys[event::SET_HP] = key;
    component::Transform t;
  t.scale.X = 0.15;
  t.scale.Y = 0.15;
  t.scale.Z = 0.15;
  auto id = indie::engine::entityManager().create(indie::entity::PLAYER,
						  component::PlayerId(1),
						  component::PlayerId(1),
						  component::Timer(100, event::COL_ADD_OBS),
						  t,
						  component::Respawn(t));
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
