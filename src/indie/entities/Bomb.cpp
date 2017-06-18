//
// Bomb.cpp<entities> for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 10:08:20 2017 akram abd-ali
// Last update Sun Jun 18 21:55:02 2017 akram abd-ali
//

#include "engine.hpp"
#include "entity.hpp"

using namespace indie::component;

ecs::Entity	indie::entity::createBomb()
{
  auto		&ent = indie::engine::entityManager();
  ecs::Entity	id;

  id = ent.createEntity();
  auto &render = ent.getComponent<Renderer3d>(id);
  if (render)
    ent.addComponentEmplace<Skeleton>(id, render->mesh);
  ent.addComponentEmplace<HP>(id, 1);
  return (id);
}
