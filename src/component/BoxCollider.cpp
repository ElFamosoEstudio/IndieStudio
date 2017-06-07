//
// BoxCollider.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue May 23 08:33:55 2017 Adam Akkari
// Last update Wed Jun  7 08:45:24 2017 Adam Akkari
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
    return (irr::core::aabbox3d<irr::f32>(irr::core::vector3df
					  (tmp->position.X - (_size.X / 2) * tmp->scale.X,
					   tmp->position.Y - (_size.Y / 2) * tmp->scale.Y,
					   tmp->position.Z - (_size.Z / 2) * tmp->scale.Z),
					  irr::core::vector3df
					  (tmp->position.X + (_size.X / 2) * tmp->scale.X,
					   tmp->position.Y + (_size.Y / 2) * tmp->scale.Y,
					   tmp->position.Z + (_size.Z / 2) * tmp->scale.Z)));
  else
    return (irr::core::aabbox3d<irr::f32>());
}

bool	BoxCollider::checkCollision()
{
  Transform	*tmp = static_cast<Transform*>(_parent.getComponent("Transform"));
  irr::core::aabbox3d<irr::f32>	const	bbox = this->getBoundingBox();
  irr::core::aabbox3d<irr::f32>		tmp_bbox;

  if (tmp != nullptr)
    for (auto idx:RessourcesLocator::getScene()->getColliders())
      {
	tmp_bbox = idx->getBoundingBox();
	if (bbox != tmp_bbox && bbox.intersectsWithBox(tmp_bbox))
	  return (true);
      }
  return (false);
}
