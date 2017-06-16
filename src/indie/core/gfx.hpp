//
// gfx.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/components
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 03:47:33 2017 Noam Silvy
// Last update Fri Jun 16 03:55:55 2017 Noam Silvy
//

#ifndef GFX_HPP
# define GFX_HPP

# include "irrlicht.h"

namespace indie
{
  namespace gfx
  {
    irr::IrrlichtDevice		*device();
    irr::scene::ISceneManager	*sceneManager();
    irr::video::IVideoDriver	*videoDriver();
  }
}

#endif //!GFX_HPP
