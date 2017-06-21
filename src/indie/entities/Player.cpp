//
// Player.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/entities
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun Jun 18 12:15:10 2017 Adam Akkari
// Last update Wed Jun 21 16:54:25 2017 akram abd-ali
//

#include "engine.hpp"
#include "entity.hpp"

using namespace indie::component;

ecs::Entity	indie::entity::createPlayer()
{
  auto		&ent = indie::engine::entityManager();
  ecs::Entity	id;

  id = ent.createEntity();
  ent.addComponentEmplace<Transform>(id);
  ent.addComponentEmplace<Renderer3d>(id, "bombie.b3d", "elfamosohat.jpg");
  ent.addComponentEmplace<BombInfo>(id, 1, 1, 1, 90);
  ent.addComponentEmplace<LifeNumber>(id, 3);
  ent.addComponentEmplace<HP>(id, 1);
  ent.addComponentEmplace<Speed>(id, 0.4);
  ent.addComponentEmplace<Movement>(id, 0.02f);
  auto &render = ent.getComponent<Renderer3d>(id);
  if (render)
    ent.addComponentEmplace<Skeleton>(id, render->mesh, true);
  return (id);
}
