//
// Respawn.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 20:29:38 2017 akram abd-ali
// Last update Sat Jun 17 20:31:32 2017 akram abd-ali
//

#ifndef RESPAWN_HPP
# define RESPAWN_HPP

# include <vector3d.h>

namespace indie
{
  namespace component
  {
    struct Respawn
    {
      Respawn()
	: position(irr::core::vector3df(0,0,0)),
	  rotation(irr::core::vector3df(0,0,0)),
	  scale(irr::core::vector3df(0,0,0)) {}
      Respawn(float x, float y, float z)
	: position(irr::core::vector3df(x,y,z)),
	  rotation(irr::core::vector3df(0,0,0)),
	  scale(irr::core::vector3df(0,0,0)) {}
      irr::core::vector3df	position;
      irr::core::vector3df	rotation;
      irr::core::vector3df	scale;
    };
  }
}

#endif  // !RESPAWN_HPP
