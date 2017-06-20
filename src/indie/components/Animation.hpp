//
// Animation.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/components
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Sun Jun 18 18:16:11 2017 Noam Silvy
// Last update Tue Jun 20 21:02:02 2017 Noam Silvy
//

#ifndef ANIMATION_HPP
# define ANIMATION_HPP

# include <map>
# include <utility>
# include "event.hpp"
# include "irrlicht.h"

namespace indie
{
  namespace component
  {
    struct Animation
    {
      std::map<event::EEvent, std::pair<irr::s32, irr::s32>>	cursor;
    };
  }
}

#endif //!ANIMATION_HPP
