//
// system.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
//
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
//
// Started on  Sat Jun 17 00:07:05 2017 Adam Akkari
// Last update Sun Jun 18 18:43:05 2017 Noam Silvy
//

#ifndef SYSTEM_HPP
# define SYSTEM_HPP

# include "MeshRenderer.hpp"
# include "Collision.hpp"
# include "Bomb.hpp"
# include "Explosion.hpp"
# include "CameraSystem.hpp"
# include "MapGenerator.hpp"
# include "Movement.hpp"
# include "Input.hpp"
# include "AnimationSystem.hpp"

namespace indie
{
  namespace system
  {
    enum ESystem
      {
	COLLISION,
	BOMB,
	EXPLOSION,
	MESH_RENDERER,
	CAMERA_SYSTEM,
	MAP_GENERATOR,
	INPUT,
	MOVEMENT,
	ANIMATION
      };
    void        registerAllSystems();
  }
}

#endif //!SYSTEM_HPP
