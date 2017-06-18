#ifndef SYSTEM_HPP
# define SYSTEM_HPP

# include "MeshRenderer.hpp"
# include "Collision.hpp"
# include "Bomb.hpp"
# include "Explosion.hpp"
# include "CameraSystem.hpp"
# include "MainMenu.hpp"
# include "SubMenu.hpp"
# include "MapGenerator.hpp"

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
	MAP_GENERATOR
      };
    void        registerAllSystems();
  }
}

#endif //!SYSTEM_HPP
