//
// sound_event.hpp for  in /home/julien/C++/IndieStudio/src/indie
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 03:49:17 2017 julien
// Last update Sun Jun 18 05:26:59 2017 julien
//

#ifndef SOUND_EVENT_HPP
# define SOUND_EVENT_HPP

namespace indie
{
  namespace event
  {
    enum class	SoundEvent
    {
      MOVE,
	EXPLOSE,
	JUMP,
	BROKEN,
	GET_POWERUP,
	GAMEOVER,
	PUT_BOMB,
	TOUCH_BUTTON,
	CURSOR_MOVE
	};
  }
}

#endif // SOUND_EVENT_HPP
