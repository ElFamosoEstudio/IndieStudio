//
// registerAllEntities.cpp for indie studio in /home/silvy_n/IndieStudio/src/indie/entities
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 19:55:55 2017 Noam Silvy
// Last update Sat Jun 17 22:34:50 2017 Adam Akkari
//

#include "engine.hpp"
#include "entity.hpp"

using namespace indie::component;

// Example of factory to code outside this file
// Entity		createBomb()
// {
//   auto&		mng = indie::engine::entityManager();
//   Entity	id;

//   id = mng.createEntity();
//   mng.addComponent<Position>(id, Position(42, 42));
//   mng.addComponent<Timer>(id, 42);
//   return (id);
// }

void		indie::entity::registerAllEntities()
{
  indie::engine::entityManager().registerEntity(indie::entity::BOX, &indie::entity::createBox);
  indie::engine::entityManager().registerEntity(indie::entity::FLOOR, &indie::entity::createFloor);
  indie::engine::entityManager().registerEntity(indie::entity::CAMERA, &indie::entity::createCamera);
  indie::engine::entityManager().registerEntity(indie::entity::MAP, &indie::entity::createMap);
}
