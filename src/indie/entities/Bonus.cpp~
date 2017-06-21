//
// Bonus.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/entities
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue Jun 20 20:12:18 2017 Adam Akkari
// Last update Tue Jun 20 21:38:12 2017 Adam Akkari
//

#include "engine.hpp"
#include "entity.hpp"

using namespace indie::component;

ecs::Entity	indie::entity::createBonus()
{
  auto		&ent = indie::engine::entityManager();
  Transform	tsfm;
  ecs::Entity	id;

  tsfm.scale = irr::core::vector3df(0.5f, 0.5f, 0.5f);
  id = ent.createEntity();
  ent.addComponent<Transform>(id, tsfm);
  ent.addComponentEmplace<Renderer3d>(id, "gfx/cube1.obj", "gfx/chancla.png");
  //TODO collision
  return (id);
}
