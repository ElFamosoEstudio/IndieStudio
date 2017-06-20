//
// BonusSystem.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue Jun 20 20:52:43 2017 Adam Akkari
// Last update Tue Jun 20 21:50:40 2017 Adam Akkari
//

#include "indie.hpp"
#include "components.hpp"

#include <iostream>

using namespace indie::component;

void		indie::system::BonusSystem::update()
{
  auto		&bonuses = engine::entityManager().getAllComponents<BonusSettings>();
  auto		&transform_cmp = engine::entityManager().getAllComponents<Transform>();

  for (auto &idx:bonuses)
    {
      if (transform_cmp.find(idx.first) != transform_cmp.end())
	{
	  transform_cmp[idx.first]->rotation.Z += 2;
	}
    }
}

ecs::SysType	indie::system::BonusSystem::type() const
{
  return (system::BONUS_SYSTEM);
}

ecs::ISystem	*indie::system::BonusSystem::create()
{
  return (new BonusSystem);
}
