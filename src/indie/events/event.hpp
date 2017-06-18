//
// event.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/events
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 21:09:13 2017 Noam Silvy
// Last update Sun Jun 18 13:04:22 2017 julien
//

#ifndef EVENT_HPP
# define EVENT_HPP

namespace indie
{
  namespace event
  {
    enum EEvent
      {
	// BOMB_EXPLODED -> event happened
	// GO_RIGHT -> action requested
	GO_RIGHT,
	GO_LEFT,
	GO_DOWN,
	GO_UP,
	PLAYER_MOVED,
	BOMB_DROPED,
	BOMB_EXPLODED,
	COLLIDED
      };
  }
}

#endif //!EVENT_HPP
