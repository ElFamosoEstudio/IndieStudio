//
// Box.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/entities
//
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
//
// Started on  Fri Jun 16 21:40:38 2017 Adam Akkari
// Last update Sun Jun 18 12:11:14 2017 Noam Silvy
//

// #include "engine.hpp"
// #include "entity.hpp"
// #include "event.hpp"
// #include "components.hpp"
// #include "Keymap.hpp"
// #include "InputReceiver.hpp"
#include "irrlicht.h"
#include "indie.hpp"

ecs::Entity	indie::entity::createBox()
{
  auto		&ent = indie::engine::entityManager();
  ecs::Entity	id;

  id = ent.createEntity();
  ent.addComponentEmplace<component::Transform>(id);
  ent.addComponentEmplace<component::Renderer3d>(id, "cube1.obj", "conceit.JPG");

  component::KeyMaps	useless;
  component::KeyMap	map = {{event::GO_RIGHT,
				{InputState::DOWN,
				 {static_cast<component::KeyType>(component::
								  GamepadKeyCode::LRIGHT)}}},
			       {event::GO_LEFT,
				{InputState::DOWN,
				 {static_cast<component::KeyType>(component::
								  GamepadKeyCode::LLEFT)}}},
			       {event::GO_UP,
				{InputState::DOWN,
				 {static_cast<component::KeyType>(component::
								  GamepadKeyCode::LUP)}}},
			       {event::GO_DOWN,
				{InputState::DOWN,
				 {static_cast<component::KeyType>(component::
								  GamepadKeyCode::LDOWN)}}}};

  useless.id = 0;
  useless.keymaps.push_front({map, indie::component::KeyMapState::NORMAL});
  ent.addComponent(id, useless);
  return (id);
}
