//
// Transform.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/components
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Thu Jun 15 22:19:54 2017 Adam Akkari
// Last update Sun Jun 18 20:51:09 2017 akram abd-ali
//

#ifndef TRANSFORM_HPP
# define TRANSFORM_HPP

# include <vector3d.h>

namespace indie
{
  namespace component
  {
    struct Transform
    {
      Transform()
	: position(irr::core::vector3df(0,0,0)),
	  rotation(irr::core::vector3df(90,0,0)),
	  scale(irr::core::vector3df(1,1,1)) {}
      Transform(float x, float y, float z)
	: position(irr::core::vector3df(x,y,z)),
	  rotation(irr::core::vector3df(90,0,0)),
	  scale(irr::core::vector3df(1,1,1)) {}
      irr::core::vector3df	position;
      irr::core::vector3df	rotation;
      irr::core::vector3df	scale;
    };
  }
}

#endif // TRANSFORM_HPP
