//
// BoxCollider.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue May 23 08:33:55 2017 Adam Akkari
// Last update Tue Jun  6 11:10:21 2017 Adam Akkari
//

#include "GameObject.hpp"
#include "BoxCollider.hh"
#include "Transform.hh"
#include "RessourcesLocator.hh"

BoxCollider::BoxCollider(GameObject &obj, irr::core::vector3df const &size)
  : Component(obj, "Collider"), _size(size)
{
  RessourcesLocator::getScene()->addCollider(this);
}

BoxCollider::~BoxCollider()
{
  RessourcesLocator::getScene()->removeCollider(this);
}

irr::core::aabbox3d<irr::f32>	BoxCollider::getBoundingBox() const
{
  Transform	*tmp = static_cast<Transform*>(_parent.getComponent("Transform"));

  if (tmp != nullptr)
    return (irr::core::aabbox3d<irr::f32>(irr::core::vector3df(tmp->position.X - _size.X / 2,
							       tmp->position.Y - _size.Y / 2,
							       tmp->position.Z - _size.Z / 2),
					  irr::core::vector3df(tmp->position.X + _size.X / 2,
							       tmp->position.Y + _size.Y / 2,
							       tmp->position.Z + _size.Z / 2)));
  else
    return (irr::core::aabbox3d<irr::f32>());
}

bool	BoxCollider::checkCollision()
{
  Transform	*tmp = static_cast<Transform*>(_parent.getComponent("Transform"));
  irr::core::aabbox3d<irr::f32>	const	bbox = this->getBoundingBox();

  if (tmp != nullptr)
    for (auto idx:RessourcesLocator::getScene()->getColliders())
      if (bbox.intersectsWithBox(idx->getBoundingBox()))
	return (true);
  return (false);
}
