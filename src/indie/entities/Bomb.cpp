//
// Bomb.cpp<entities> for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 10:08:20 2017 akram abd-ali
// Last update Sun Jun 18 21:28:45 2017 akram abd-ali
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
  if (!render)
    std::cout << "no render" << std::endl;
  std::cout << "before" << std::endl;
  ent.addComponentEmplace<Skeleton>(id, render->mesh);
  std::cout << "after" << std::endl;
  ent.addComponentEmplace<HP>(id, 1);
  std::cout << "alala" << std::endl;
  return (id);
}
