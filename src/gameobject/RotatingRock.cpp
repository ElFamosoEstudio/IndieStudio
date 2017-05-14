//
// RotatingRock.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 23:53:35 2017 Adam Akkari
// Last update Mon May 15 00:41:14 2017 Adam Akkari
//

#include <irrlicht.h>
#include "RotatingRock.hh"

RotatingRock::RotatingRock(std::string const &name,
			   irr::core::vector3df const &position)
  : GameObject(name)
{
  _transform = new Transform(*this, position);
  _renderer = new Renderer3D(*this, "rock2.obj");
  _components.push_back(_transform);
  _components.push_back(_renderer);

  _renderer->setMaterial("rock_diffuse.png");
  _renderer->enableLighting(false);
}

void	RotatingRock::update()
{
  _transform->rotation.Y += 1;
}
