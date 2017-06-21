//
// system.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
//
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
//
// Started on  Sat Jun 17 00:07:05 2017 Adam Akkari
// Last update Wed Jun 21 17:36:16 2017 akram abd-ali
//

#ifndef SYSTEM_HPP
# define SYSTEM_HPP

# include "MeshRenderer.hpp"
# include "Collision.hpp"
# include "Bomb.hpp"
# include "Explosion.hpp"
# include "CameraSystem.hpp"
# include "MainMenu.hpp"
# include "SubMenu.hpp"
# include "OverMenu.hpp"
# include "MapGenerator.hpp"
# include "Movement.hpp"
# include "Spawn.hpp"
# include "Die.hpp"
# include "BonusSystem.hpp"
# include "SysTime.hpp"
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
	MAIN_MENU,
	SUB_MENU,
	OVER_MENU,
	MAP_GENERATOR,
	INPUT,
	MOVEMENT,
	ANIMATION,
	SYSTIME,
	SPAWN,
	DIE,
	BONUS_SYSTEM
      };
    void        registerAllSystems();
  }
}

#endif //!SYSTEM_HPP
