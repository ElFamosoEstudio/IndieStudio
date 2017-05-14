//
// Transform.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 20:11:20 2017 Adam Akkari
// Last update Sun May 14 22:50:06 2017 Adam Akkari
//

#include "Transform.hh"

Transform::Transform(GameObject &obj)
  : Component(obj, "Transform")
{

}

Transform::Transform(GameObject &obj,
		     irr::core::vector3df &position)
  : Component(obj, "Transform"),
    position(position)
{

}

Transform::Transform(GameObject &obj,
		     irr::core::vector3df &position,
		     irr::core::vector3df &rotation)
  : Component(obj, "Transform"),
    position(position),
    rotation(rotation)
{

}

Transform::Transform(GameObject &obj,
		     irr::core::vector3df &position,
		     irr::core::vector3df &rotation,
		     irr::core::vector3df &scale)
  : Component(obj, "Transform"),
    position(position),
    rotation(rotation),
    scale(scale)
{

}
