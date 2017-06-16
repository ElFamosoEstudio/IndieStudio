//
// system.hpp for indie studio in /home/silvy_n/IndieStudio/src/indie/systems
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 20:29:09 2017 Noam Silvy
// Last update Fri Jun 16 20:19:13 2017 Adam Akkari
//

#ifndef SYSTEM_HPP
# define SYSTEM_HPP

namespace indie
{
  namespace system
  {
    enum ESystem
      {
	INPUT,
	MESH_RENDERER,
	CAMERA_SYSTEM
      };

    void        registerAllSystems();
  }
}

#endif //!SYSTEM_HPP
