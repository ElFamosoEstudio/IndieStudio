//
// Player.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/entities
//
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
//
// Started on  Sun Jun 18 12:15:10 2017 Adam Akkari
// Last update Tue Jun 20 22:40:47 2017 Noam Silvy
//

#include "engine.hpp"
#include "entity.hpp"
#include "event.hpp"

using namespace indie::component;

ecs::Entity	indie::entity::createPlayer()
{
  auto		&ent = indie::engine::entityManager();
  ecs::Entity	id;
  Animation	anim;

  id = ent.createEntity();
  ent.addComponentEmplace<Transform>(id);
  ent.addComponentEmplace<Renderer3d>(id, "bombie.b3d", "elfamosohat.jpg");
  ent.addComponentEmplace<BombInfo>(id, 1, 1, 1, 90);
  ent.addComponentEmplace<LifeNumber>(id, 1);
  ent.addComponentEmplace<HP>(id, 1);
  ent.addComponentEmplace<Speed>(id, 0.5);
  ent.addComponentEmplace<Movement>(id, 0.05f);

  anim.cursor[event::MOVED] = {0, 34};
  anim.cursor[event::STOPED] = {36, 46};
  anim.cursor[event::BORED] = {47, 78};
  ent.addComponent<Animation>(id, anim);
  return (id);
}
