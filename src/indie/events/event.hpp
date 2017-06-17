//
// event.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/events
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 21:09:13 2017 Noam Silvy
// Last update Sat Jun 17 20:46:49 2017 Adam Akkari
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
	COLLIDED,
	BOMB_DROPPED,
	DROP_BOMB_ERR
      };
  }
}

#endif //!EVENT_HPP
