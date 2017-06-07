//
// Camera.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 21:52:49 2017 Adam Akkari
// Last update Wed Jun  7 11:07:59 2017 Adam Akkari
//

#include "Camera.hh"

Camera::Camera(std::string const &name,
	       irr::core::vector3df const &position,
	       irr::core::vector3df const &lookat)
  : GameObject(name)
{
  _transform = new Transform(*this, position, irr::core::vector3df(0.0f, 90.0f, 0.0f));
  _rendererCamera = new RendererCamera(*this, lookat);
  _components.push_back(_transform);
  _components.push_back(_rendererCamera);
}

void	Camera::update()
{

}
