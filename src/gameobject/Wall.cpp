//
// Wall.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue Jun  6 15:08:32 2017 Adam Akkari
// Last update Wed Jun  7 10:19:30 2017 Adam Akkari
//

#include <IAnimatedMeshSceneNode.h>
#include "Wall.hh"

Wall::Wall(std::string const &name,
	   irr::core::vector3df const &position)
  : GameObject(name)
{
  _transform = new Transform(*this, position);
  _renderer = new Renderer3D(*this, "cube1.obj");
  _collider = new BoxCollider(*this, irr::core::vector3df(1.0f, 1.0f, 1.0f));
  _components.push_back(_transform);
  _components.push_back(_renderer);
  _components.push_back(_collider);

  _renderer->setMaterial("conceit.JPG");
  _renderer->enableLighting(false);
}

void	Wall::update()
{

}
