//
// Character.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue Jun  6 11:45:15 2017 Adam Akkari
// Last update Wed Jun  7 11:16:00 2017 Adam Akkari
//

#include <IAnimatedMeshSceneNode.h>
#include "Character.hh"
#include "InputManager.hh"

Character::Character(std::string const &name,
		     irr::core::vector3df const &position)
  : GameObject(name)
{
  _transform = new Transform(*this, position,
			     irr::core::vector3df(0.0f, 0.0f, 0.0f),
			     irr::core::vector3df(0.75f, 0.75f, 0.75f));
  _renderer = new Renderer3D(*this, "cube1.obj");
  _collider = new BoxCollider(*this, irr::core::vector3df(1.0f, 1.0f, 1.0f));
  _components.push_back(_transform);
  _components.push_back(_renderer);
  _components.push_back(_collider);

  _renderer->setMaterial("chancla.png");
  _renderer->enableLighting(false);
}

void	Character::update()
{
  if (InputManager::isKeyDown("left"))
    _transform->move(-RIGHT * 0.1f);
  if (InputManager::isKeyDown("right"))
    _transform->move(RIGHT * 0.1f);
  if (InputManager::isKeyDown("up"))
    _transform->move(UP * 0.1f);
  if (InputManager::isKeyDown("down"))
    _transform->move(-UP * 0.1f);
}