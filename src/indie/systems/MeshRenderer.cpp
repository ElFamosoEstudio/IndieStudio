//
// MeshRenderer.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Thu Jun 15 23:36:51 2017 Adam Akkari
// Last update Fri Jun 16 01:43:57 2017 Adam Akkari
//

#include "system.hpp"
#include "ecs.hpp"
#include "MeshRenderer.hpp"
#include "Transform.hpp"
#include "Renderer3d.hpp"

void		indie::system::MeshRenderer::update()
{
  auto		&transform_cmp;
  auto		&renderer_cmp;

  transform_cmp = engine::entityManager().getAllComponents<Transform>();
  renderer_cmp = engine::entityManager().getAllComponents<Renderer3d>();
  for (auto const &idx:renderer_cmp)
    if (transform_cmp.find(idx.first) != transform_cmp.end())
      {
	idx.second.mesh->setPosition = transform_cmp[idx.first].position;
	idx.second.mesh->setRotation = transform_cmp[idx.first].rotation;
	idx.second.mesh->setScale = transform_cmp[idx.first].scale;
      }
}

ecs::SysType	indie::system::MeshRenderer::type() const
{
  return (system::MESH_RENDERER);
}

static ISystem	indie::system::MeshRenderer::create()
{
  return (new MeshRenderer);
}
