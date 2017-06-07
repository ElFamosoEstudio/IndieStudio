//
// RendererCamera.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 22:17:06 2017 Adam Akkari
// Last update Wed Jun  7 11:09:38 2017 Adam Akkari
//

#include "RendererCamera.hh"
#include "RessourcesLocator.hh"
#include "Transform.hh"
#include "GameObject.hpp"

RendererCamera::RendererCamera(GameObject &obj,
			       irr::core::vector3df const &lookat)
  : Renderer(obj),
    _camera(RessourcesLocator::getSceneManager()->addCameraSceneNode
	    (0, irr::core::vector3df(0.0f, 0.0f, 0.0f), lookat))
{
  
}

void	RendererCamera::lookAt(irr::core::vector3df &target)
{
  _camera->setTarget(target);
}

void	RendererCamera::update()
{
  Transform	*tmp = static_cast<Transform*>(_parent.getComponent("Transform"));

  if (tmp)
    _camera->setPosition(tmp->position);
}
