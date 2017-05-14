//
// Camera.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 21:52:49 2017 Adam Akkari
// Last update Sun May 14 22:50:34 2017 Adam Akkari
//

#include "Camera.hh"

Camera::Camera(std::string const &name,
	       irr::core::vector3df &position,
	       irr::core::vector3df &lookat)
  : GameObject(name)
{
  _transform = new Transform(*this, position);
  _rendererCamera = new RendererCamera(*this, lookat);
  _components.push_back(_transform);
  _components.push_back(_rendererCamera);
}

void	Camera::update()
{

}
