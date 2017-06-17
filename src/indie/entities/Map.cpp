//
// Map.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/entities
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat Jun 17 04:05:06 2017 Adam Akkari
// Last update Sat Jun 17 04:06:51 2017 Adam Akkari
//

#include "engine.hpp"
#include "entity.hpp"

using namespace indie::component;

ecs::Entity	indie::entity::createMap()
{
  auto		&ent = indie::engine::entityManager();
  ecs::Entity	id;

  id = ent.createEntity();
  ent.addComponentEmplace<MapSettings>(id, 5, 5);
  return (id);
}
