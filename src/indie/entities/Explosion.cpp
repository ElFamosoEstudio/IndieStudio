//
// Explosion.cpp<entities> for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sun Jun 18 06:41:35 2017 akram abd-ali
// Last update Sun Jun 18 23:34:51 2017 akram abd-ali
//

#include "engine.hpp"
#include "entity.hpp"

using namespace indie::component;

ecs::Entity	indie::entity::createExplosion()
{
  auto		&ent = indie::engine::entityManager();
  ecs::Entity	id;

  id = ent.createEntity();
  ent.addComponentEmplace<Renderer3d>(id, "gfx/ball.obj", "gfx/lava.png");
  auto &render = ent.getComponent<Renderer3d>(id);
  if (render)
    ent.addComponentEmplace<Skeleton>(id, render->mesh);
  ent.addComponentEmplace<TagExplosion>(id);
  return (id);
}
