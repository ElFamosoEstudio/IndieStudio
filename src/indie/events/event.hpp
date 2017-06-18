//
// event.hpp for  in /home/julien/C++/IndieStudio
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 15:07:10 2017 julien
// Last update Sun Jun 18 16:21:32 2017 julien
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
	SPREAD_EXPLOSION,
	// BOMB_EXPLODED -> event happened
	// GO_RIGHT -> action requested
	// GO_RIGHT,
	// GO_LEFT,
	// GO_DOWN,
	// GO_UP,
	PLAYER_MOVED,
	BOMB_EXPLODED,
	COLLIDED,
	BOMB_DROPPED,
	DROP_BOMB_ERR,
	EXPLOSION_ERR
      };
  }
}

#endif //!EVENT_HPP
