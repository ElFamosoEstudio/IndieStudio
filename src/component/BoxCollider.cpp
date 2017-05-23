//
// BoxCollider.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue May 23 08:33:55 2017 Adam Akkari
// Last update Tue May 23 10:03:53 2017 Adam Akkari
//

#include "GameObject.hpp"
#include "BoxCollider.hh"
#include "Transform.hh"

BoxCollider::BoxCollider(GameObject &obj, irr::core::vector3df const &size)
  : Component(obj, "Collider"), _size(size)
{

}


irr::core::aabbox3d<irr::f32>	BoxCollider::getBoundingBox() const
{
  Transform		*tmp = static_cast<Transform*>(_parent.getComponent("Transform"));

  if (tmp != nullptr)
    return (irr::core::aabbox3d<irr::f32>(irr::core::vector3df(tmp->position.X - _size.X / 2,
							       tmp->position.Y - _size.Y / 2,
							       tmp->position.Z - _size.Z / 2),
					  irr::core::vector3df(tmp->position.X + _size.X / 2,
							       tmp->position.Y + _size.Y / 2,
							       tmp->position.Z + _size.Z / 2)));
  else
    return (irr::core::aabbox3d<irr::f32>()); // TODO : throw
}
