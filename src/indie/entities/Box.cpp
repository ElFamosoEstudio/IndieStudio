//
// Box.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/entities
//
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
//
// Started on  Fri Jun 16 21:40:38 2017 Adam Akkari
// Last update Tue Jun 20 20:57:05 2017 akram abd-ali
//

#include "irrlicht.h"
#include "indie.hpp"

ecs::Entity	indie::entity::createBox()
{
  auto		&ent = indie::engine::entityManager();
  ecs::Entity	id;

  id = ent.createEntity();
  ent.addComponentEmplace<component::Transform>(id);
  ent.addComponentEmplace<component::Renderer3d>(id, "gfx/cube1.obj", "gfx/brick.jpg");
  auto &render = ent.getComponent<component::Renderer3d>(id);
  if (render)
    ent.addComponentEmplace<component::Skeleton>(id, render->mesh);
  return (id);
}
