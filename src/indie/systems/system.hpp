//
// system.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat Jun 17 00:07:05 2017 Adam Akkari
// Last update Sat Jun 17 06:09:21 2017 Adam Akkari
//

#ifndef SYSTEM_HPP
# define SYSTEM_HPP

# include "MeshRenderer.hpp"
# include "Collision.hpp"
# include "CameraSystem.hpp"
# include "MapGenerator.hpp"

namespace indie
{
  namespace system
  {
    enum ESystem
      {
	COLLISION,
	MESH_RENDERER,
	CAMERA_SYSTEM,
	MAP_GENERATOR
      };
    void        registerAllSystems();
  }
}

#endif //!SYSTEM_HPP
