//
// Box.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/entities
//
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
//
// Started on  Fri Jun 16 21:40:38 2017 Adam Akkari
// Last update Sun Jun 18 12:14:56 2017 Noam Silvy
//

#include "irrlicht.h"
#include "indie.hpp"

ecs::Entity	indie::entity::createBox()
{
  auto		&ent = indie::engine::entityManager();
  ecs::Entity	id;

  id = ent.createEntity();
  ent.addComponentEmplace<component::Transform>(id);
  ent.addComponentEmplace<component::Renderer3d>(id, "cube1.obj", "conceit.JPG");

  return (id);
}
