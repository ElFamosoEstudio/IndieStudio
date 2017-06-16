//
// system.hpp for indie studio in /home/silvy_n/IndieStudio/src/indie/systems
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 20:29:09 2017 Noam Silvy
// Last update Fri Jun 16 21:39:56 2017 akram abd-ali
//

#ifndef SYSTEM_HPP
# define SYSTEM_HPP

# include "MeshRenderer.hpp"
# include "Collision.hpp"

namespace indie
{
  namespace system
  {
    enum ESystem
      {
	INPUT,
	COLLISION,
	MESH_RENDERER
      };

    void        registerAllSystems();
  }
}

#endif //!SYSTEM_HPP
