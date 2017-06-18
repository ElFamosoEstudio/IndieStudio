//
// Sound.hpp for  in /home/julien/C++/IndieStudio/src/indie/components
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 02:41:48 2017 julien
// Last update Sun Jun 18 16:40:26 2017 julien
//

#ifndef SOUND_HPP
# define SOUND_HPP

# include <map>
# include <iostream>
# include "ecs.hpp"
# include "event.hpp"

namespace indie
{
  namespace component
  {
    struct Sound
    {
      std::map<indie::event::EEvent, std::string>	sounds =
	{
	  {indie::event::EEvent::PLAYER_MOVED, ""},
	  // {indie::event::SoundEvent::JUMP, ""},
	  // {indie::event::SoundEvent::BROKEN, ""},
	  {indie::event::EEvent::BOMB_EXPLODED, ""},
	  // {indie::event::SoundEvent::GAMEOVER, ""},
	  {indie::event::EEvent::BOMB_DROPPED, ""},
	  {indie::event::EEvent::COLLIDED, ""},
	  // {indie::event::SoundEvent::CURSOR_MOVE, ""},
	  // {indie::event::SoundEvent::GET_POWERUP, ""},
	  // {indie::event::SoundEvent::TOUCH_BUTTON, ""},
	};
    };
  }
}

#endif // SOUND_HPP
