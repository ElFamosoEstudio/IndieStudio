//
// CameraSystem.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Fri Jun 16 20:06:33 2017 Adam Akkari
// Last update Fri Jun 16 20:30:11 2017 Adam Akkari
//

#include "ecs.hpp"
#include "CameraSystem.hpp"
#include "components.hpp"
#include "engine.hpp"
#include "system.hpp"

using namespace indie::component;

void	indie::system::CameraSystem::update()
{
  auto	&transform_cmp = engine::entityManager().getAllComponents<Transform>();
  auto	&camera_cmp = engine::entityManager().getAllComponents<Camera>();

  for (auto &idx:camera_cmp)
    if (transform_cmp.find(idx.first) != transform_cmp.end())
      {
	idx.second->camera->setPosition(transform_cmp[idx.first]->position);
	idx.second->camera->setRotation(transform_cmp[idx.first]->rotation);
      }
}

ecs::SysType	indie::system::CameraSystem::type() const
{
  return (system::CAMERA_SYSTEM);
}

ecs::ISystem	*indie::system::CameraSystem::create()
{
  return (new CameraSystem);
}
