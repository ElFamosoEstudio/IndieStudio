//
// Collision.cpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Fri Jun 16 17:56:19 2017 akram abd-ali
// Last update Fri Jun 16 21:36:43 2017 akram abd-ali
//

#include "irrlicht.h"
#include "Collision.hpp"
#include "engine.hpp"
#include "system.hpp"

void	indie::system::Collision::update() {
  auto&	skels = engine::entityManager().getAllComponents<indie::component::Skeleton>();

  for (auto& it : skels)
    {
      auto id = it.first;
      auto& skel = it.second;
      irr::scene::IMetaTriangleSelector	*meta = skel->metaSelector;
      if (meta != nullptr)
	{
		
	}
    }
}

ecs::SysType	indie::system::Collision::type() const
{
  return (system::COLLISION);
}

ecs::ISystem	*indie::system::Collision::create()
{
  return new Collision;
}
