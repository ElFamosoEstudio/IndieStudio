//
// BonusSystem.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue Jun 20 20:52:43 2017 Adam Akkari
// Last update Tue Jun 20 20:54:37 2017 Adam Akkari
//

#include "indie.hpp"
#include "BonusSystem.hpp"

using namespace indie::component;

void		indie::system::BonusSystem::update()
{

}

ecs::Systype	indie::system::MeshRenderer::type() const
{
  return (system::BONUS_SYSTEM);
}

ecs::ISystem	*indie::system::MeshRenderer::create()
{
  return (new MeshRenderer);
}
