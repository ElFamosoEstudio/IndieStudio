//
// event.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/events
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 21:09:13 2017 Noam Silvy
// Last update Sun Jun 18 03:37:37 2017 Noam Silvy
//

#ifndef EVENT_HPP
# define EVENT_HPP

namespace indie
{
  namespace event
  {
    enum EEvent
      {
	COLLIDED,
	// BOMB_EXPLODED -> event happened
	// GO_RIGHT -> action requested
	GO_RIGHT,
	GO_LEFT,
	GO_UP,
	GO_DOWN
      };
  }
}

#endif //!EVENT_HPP
