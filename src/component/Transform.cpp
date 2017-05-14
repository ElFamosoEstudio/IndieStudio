//
// Transform.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 20:11:20 2017 Adam Akkari
// Last update Sun May 14 02:00:46 2017 Adam Akkari
//

#include "Transform.hh"

Transform::Transform(GameObject &obj,
		     float px, float py, float pz,
		     float rx, float ry, float rz,
		     float sx, float sy, float sz)
  : Component(obj, "Transform"),
    position(irr::core::vector3df(px, py, pz)),
    rotation(irr::core::vector3df(rx, ry, rz)),
    scale(irr::core::vector3df(sx, sy, sz))
{

}
