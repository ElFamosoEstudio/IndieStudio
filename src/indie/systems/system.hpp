//
// system.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat Jun 17 00:07:05 2017 Adam Akkari
// Last update Sat Jun 17 02:31:05 2017 akram abd-ali
//

#ifndef SYSTEM_HPP
# define SYSTEM_HPP

# include "MeshRenderer.hpp"
# include "Collision.hpp"
# include "Bomb.hpp"
# include "CameraSystem.hpp"

namespace indie
{
  namespace system
  {
    enum ESystem
      {
	COLLISION,
	BOMB,
	MESH_RENDERER,
	CAMERA_SYSTEM
      };
    void        registerAllSystems();
  }
}

#endif //!SYSTEM_HPP
