//
// Sound.hpp for  in /home/julien/C++/IndieStudio/src/indie/components
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 02:41:48 2017 julien
// Last update Sun Jun 18 21:24:30 2017 julien
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
	  {indie::event::EEvent::PLAYER_MOVED, "sounds/move.wav"},
	  {indie::event::EEvent::BOMB_EXPLODED, "sounds/explosion.wav"},
	  {indie::event::EEvent::BOMB_DROPPED, "sounds/pop.wav"},
	  // {indie::event::EEvent::COLLIDED, ""},
	  // {indie::event::SoundEvent::JUMP, ""},
	  // {indie::event::SoundEvent::BROKEN, "sounds/smb_breakblock.wav"},
	  // {indie::event::SoundEvent::GAMEOVER, ""},
	  // {indie::event::SoundEvent::CURSOR_MOVE, ""},
	  // {indie::event::SoundEvent::GET_POWERUP, ""},
	  // {indie::event::SoundEvent::TOUCH_BUTTON, ""},
	};
    };
  }
}

#endif // SOUND_HPP
