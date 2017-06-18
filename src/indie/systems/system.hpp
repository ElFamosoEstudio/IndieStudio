//
// system.hpp for  in /home/julien/C++/IndieStudio
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 18:20:45 2017 julien
// Last update Sun Jun 18 19:59:22 2017 julien
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
	LUASCRIPT_SYSTEM,
	SOUND_SYSTEM,
	MAP_GENERATOR,
	ASCIIMAPSYSTEM,
	INPUT,
	MOVEMENT
      };
    void        registerAllSystems();
  }
}

#endif //!SYSTEM_HPP
