//
// event.hpp for  in /home/julien/C++/IndieStudio/src/indie
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 19:52:44 2017 julien
// Last update Sun Jun 18 19:52:45 2017 julien
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
	// BOMB_EXPLODED -> event happened
	// GO_RIGHT -> action requested
	// GO_RIGHT,
	// GO_LEFT,
	// GO_DOWN,
	// GO_UP,
	PLAYER_MOVED,
	BOMB_EXPLODED,
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
