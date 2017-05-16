//
// Transform.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 20:11:20 2017 Adam Akkari
// Last update Mon May 15 00:38:12 2017 Adam Akkari
//

#include "Transform.hh"

Transform::Transform(GameObject &obj)
  : Component(obj, "Transform")
{
  position = irr::core::vector3df(0.0f, 0.0f, 0.0f);
  rotation = irr::core::vector3df(0.0f, 0.0f, 0.0f);
  scale = irr::core::vector3df(0.0f, 0.0f, 0.0f);
}

Transform::Transform(GameObject &obj,
		     irr::core::vector3df const &position)
  : Component(obj, "Transform"),
    position(position)
{
  rotation = irr::core::vector3df(0.0f, 0.0f, 0.0f);
  scale = irr::core::vector3df(1.0f, 1.0f, 1.0f);
}

Transform::Transform(GameObject &obj,
		     irr::core::vector3df const &position,
		     irr::core::vector3df const &rotation)
  : Component(obj, "Transform"),
    position(position),
    rotation(rotation)
{
  scale = irr::core::vector3df(1.0f, 1.0f, 1.0f);
}

Transform::Transform(GameObject &obj,
		     irr::core::vector3df const &position,
		     irr::core::vector3df const &rotation,
		     irr::core::vector3df const &scale)
  : Component(obj, "Transform"),
    position(position),
    rotation(rotation),
    scale(scale)
{

}
