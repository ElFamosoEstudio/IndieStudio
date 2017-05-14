//
// Renderer3D.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 23:32:21 2017 Adam Akkari
// Last update Sun May 14 02:47:05 2017 Adam Akkari
//

#include "RessourcesLocator.hh"
#include "Renderer3D.hh"
#include "Transform.hh"
#include "GameObject.hpp"

Renderer3D::Renderer3D(GameObject &obj, std::string const &model)
  : Component(obj, "Renderer3D"),
    _mesh(RessourcesLocator::getSceneManager()->addAnimatedMeshSceneNode
	  (RessourcesLocator::getSceneManager()->getMesh(model.c_str())))
{

}

void	Renderer3D::setMaterial(std::string const &name)
{
  _mesh->setMaterialTexture(0, RessourcesLocator::getVideoDriver()->getTexture(name.c_str()));
}

void	Renderer3D::update()
{
  Transform	*tmp = static_cast<Transform*>(_parent.getComponent("Transform"));

  if (tmp)
    {
      _mesh->setPosition(tmp->position);
      _mesh->setRotation(tmp->rotation);
      _mesh->setScale(tmp->scale);
    }
}
