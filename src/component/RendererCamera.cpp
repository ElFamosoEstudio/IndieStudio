//
// RendererCamera.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 22:17:06 2017 Adam Akkari
// Last update Sun May 14 22:46:17 2017 Adam Akkari
//

#include "RendererCamera.hh"
#include "RessourcesLocator.hh"
#include "Transform.hh"
#include "GameObject.hpp"

RendererCamera::RendererCamera(GameObject &obj,
			       irr::core::vector3df &lookat)
  : Component(obj, "RendererCamera"),
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
