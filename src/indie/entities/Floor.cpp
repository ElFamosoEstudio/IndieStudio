//
// Floor.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/entities
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat Jun 17 22:31:57 2017 Adam Akkari
// Last update Sun Jun 18 00:26:41 2017 Adam Akkari
//

#include "engine.hpp"
#include "entity.hpp"

using namespace indie::component;

ecs::Entity	indie::entity::createFloor()
{
  auto		&ent = indie::engine::entityManager();
  ecs::Entity	id;

  id = ent.createEntity();
  ent.addComponentEmplace<Transform>(id);
  ent.addComponentEmplace<Renderer3d>(id, "cube1.obj", "bite.jpg");
  return (id);
}
