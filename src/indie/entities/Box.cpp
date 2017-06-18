//
// Box.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/entities
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Fri Jun 16 21:40:38 2017 Adam Akkari
// Last update Sun Jun 18 11:52:20 2017 akram abd-ali
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
  ent.addComponentEmplace<Renderer3d>(id, "gfx/cube1.obj", "gfx/brick.jpg");
  auto &render = ent.getComponent<Renderer3d>(id);
  ent.addComponentEmplace<Skeleton>(id, render->mesh);
  return (id);
}
