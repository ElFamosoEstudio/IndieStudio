//
// system.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
//
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
//
// Started on  Sat Jun 17 00:07:05 2017 Adam Akkari
// Last update Sat Jun 17 05:50:56 2017 Bento
//

#ifndef SYSTEM_HPP
# define SYSTEM_HPP

# include "MeshRenderer.hpp"
# include "Collision.hpp"
# include "CameraSystem.hpp"
# include "Menu.hpp"

namespace indie
{
  namespace system
  {
    enum ESystem
      {
	COLLISION,
	MESH_RENDERER,
	CAMERA_SYSTEM,
	MAIN_MENU
      };
    void        registerAllSystems();
  }
}

#endif //!SYSTEM_HPP
