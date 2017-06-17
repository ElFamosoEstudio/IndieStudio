//
// Box.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/entities
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Fri Jun 16 21:40:38 2017 Adam Akkari
// Last update Sat Jun 17 22:14:49 2017 Adam Akkari
//

#include "engine.hpp"
#include "entity.hpp"

using namespace indie::component;

ecs::Entity	indie::entity::createBox()
{
  auto		&ent = indie::engine::entityManager();
  ecs::Entity	id;

  id = ent.createEntity();
  ent.addComponentEmplace<Transform>(id);
  ent.addComponentEmplace<Renderer3d>(id, "cube1.obj", "brick.jpg");
  return (id);
}
