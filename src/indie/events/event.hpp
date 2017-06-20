//
// event.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/events
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 21:09:13 2017 Noam Silvy
// Last update Sun Jun 18 19:35:53 2017 Adam Akkari
//

#ifndef EVENT_HPP
# define EVENT_HPP

namespace indie
{
  namespace event
  {
    enum EEvent
      {
	GO_RIGHT,
	GO_LEFT,
	GO_UP,
	GO_DOWN,
	DROP_BOMB,
	DETONATE_BOMB,
	MAP_3D_FROM_2D,
	REMOVE_SKEL,
	COL_ADD_BOMB,
	COLLIDED,
	BOMB_DROPPED,
	DROP_BOMB_ERR,
	NO_DAMAGE,
	CHECK_DAMAGE,
	SPREAD_EXPLOSION,
	DAMAGE,
	HIT
      };
  }
}

#endif //!EVENT_HPP
