//
// Respawn.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 20:29:38 2017 akram abd-ali
// Last update Wed Jun 21 16:32:20 2017 akram abd-ali
//

#ifndef RESPAWN_HPP
# define RESPAWN_HPP

# include <vector3d.h>
# include "components.hpp"

namespace indie
{
  namespace component
  {
    struct Respawn
    {
      Respawn()
	: transform(component::Transform(0,0,0)) {}
      Respawn(component::Transform t) : transform(t)
      {
      }
      component::Transform transform;
    };
  }
}

#endif  // !RESPAWN_HPP
