//
// Music.hpp for  in /home/julien/C++/IndieStudio/src/indie/components
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 02:41:48 2017 julien
// Last update Sun Jun 18 21:46:54 2017 julien
//

#ifndef MUSIC_HPP
# define MUSIC_HPP

# include <map>
# include <iostream>
# include "ecs.hpp"
# include "event.hpp"

namespace indie
{
  namespace component
  {
    struct Music
    {
      std::map<indie::event::EEvent, std::string>	sounds =
	{
	  {indie::event::EEvent::MENU_MUSIC, "sounds/guadalajara.ogg"},
	  {indie::event::EEvent::GAME_MUSIC, "sounds/mexico.ogg"},
	};
    };
  }
}

#endif // MUSIC_HPP
