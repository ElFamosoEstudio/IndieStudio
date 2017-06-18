//
// system.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat Jun 17 00:07:05 2017 Adam Akkari
// Last update Sun Jun 18 02:41:16 2017 julien
//

#ifndef SYSTEM_HPP
# define SYSTEM_HPP

# include "MeshRenderer.hpp"
# include "Collision.hpp"
# include "CameraSystem.hpp"

namespace indie
{
  namespace system
  {
    enum ESystem
      {
	COLLISION,
	MESH_RENDERER,
	CAMERA_SYSTEM,
	LUASCRIPT_SYSTEM,
	SOUND_SYSTEM
      };
    void        registerAllSystems();
  }
}

#endif //!SYSTEM_HPP
