//
// Crate.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/entities
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun Jun 18 05:23:30 2017 Adam Akkari
// Last update Sun Jun 18 14:39:05 2017 akram abd-ali
//

#include "engine.hpp"
#include "entity.hpp"

using namespace indie::component;

ecs::Entity	indie::entity::createCrate()
{
  auto		&ent = indie::engine::entityManager();
  ecs::Entity	id;

  id = ent.createEntity();
  ent.addComponentEmplace<Transform>(id);
  ent.addComponentEmplace<Renderer3d>(id, "gfx/cube1.obj", "gfx/crate.jpg");
  auto &render = ent.getComponent<Renderer3d>(id);
  ent.addComponentEmplace<Skeleton>(id, render->mesh);
  ent.addComponentEmplace<HP>(id, 1);
  return (id);
}
