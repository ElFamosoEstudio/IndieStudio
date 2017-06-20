//
// Explosion.cpp<entities> for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sun Jun 18 06:41:35 2017 akram abd-ali
// Last update Tue Jun 20 20:50:00 2017 akram abd-ali
//

#include "engine.hpp"
#include "entity.hpp"

using namespace indie::component;

ecs::Entity	indie::entity::createExplosion()
{
  auto		&ent = indie::engine::entityManager();
  ecs::Entity	id;

  id = ent.createEntity();
  ent.addComponentEmplace<Renderer3d>(id, "explosion.blend.b3d",
				      "explosion.jpg");
  ent.addComponentEmplace<TagExplosion>(id);
  return (id);
}
