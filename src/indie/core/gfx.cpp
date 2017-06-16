//
// gfx.cpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/components
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 03:56:07 2017 Noam Silvy
// Last update Fri Jun 16 04:00:57 2017 Noam Silvy
//

#include "gfx.hpp"

irr::IrrlichtDevice*		indie::gfx::device()
{
  static auto			*device =
    irr::createDevice(irr::video::EDT_OPENGL,
		      irr::core::dimension2d<irr::u32>(1920, 968), 16, false);
  return (device);
}

irr::scene::ISceneManager*	indie::gfx::sceneManager()
{
  static auto			*smgr = indie::gfx::device()->getSceneManager();
  return (smgr);
}

irr::video::IVideoDriver*	indie::gfx::videoDriver()
{
  static auto			vdri = indie::gfx::device()->getVideoDriver();
  return (vdri);
}
