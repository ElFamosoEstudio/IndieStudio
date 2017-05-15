//
// RotatingRock.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 23:53:35 2017 Adam Akkari
// Last update Mon May 15 16:29:13 2017 Adam Akkari
//

#include <irrlicht.h>
#include "InputManager.hh"
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
  if (InputManager::isKeyDown("left"))
    _transform->rotation.Y += 1;
  if (InputManager::isKeyDown("right"))
    _transform->rotation.Y -= 1;
  if (InputManager::isKeyDown("up"))
    _transform->rotation.X += 1;
  if (InputManager::isKeyDown("down"))
    _transform->rotation.X -= 1;
}
