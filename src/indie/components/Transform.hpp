//
// Transform.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/components
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Thu Jun 15 22:19:54 2017 Adam Akkari
// Last update Thu Jun 15 22:21:50 2017 Adam Akkari
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
      irr::core::vector3df	position;
      irr::core::vector3df	rotation;
      irr::core::vector3df	scale;
    };
  }
}

#endif // TRANSFORM_HPP
