//
// entity.hpp for indie studio in /home/silvy_n/IndieStudio/src/indie/entities
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 19:12:49 2017 Noam Silvy
// Last update Thu Jun 15 20:30:26 2017 Noam Silvy
//

#ifndef ENTITY_HPP
# define ENTITY_HPP

namespace indie
{
  namespace entity
  {
    enum EEntity
      {
	PLAYER,
	SOFT_BOX,
	HARD_BOX,
	BOMB,
	EXPLOSION,
	POWERUP
      };

    void	registerAllEntities();
  }
}

#endif //!ENTITY_HPP
