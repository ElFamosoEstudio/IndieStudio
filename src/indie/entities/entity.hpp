//
// entity.hpp for indie studio in /home/silvy_n/IndieStudio/src/indie/entities
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 19:12:49 2017 Noam Silvy
// Last update Wed Jun 21 03:05:03 2017 akram abd-ali
//

#ifndef ENTITY_HPP
# define ENTITY_HPP

# include "ecs.hpp"

namespace indie
{
  namespace entity
  {
    enum EEntity
      {
	BOX,
	CAMERA,
	BOMB,
	EXPLOSION,
	FLOOR,
	MAP,
	CRATE,
	PLAYER,
	BONUS
      };

    void	registerAllEntities();

    ecs::Entity	createBox();
    ecs::Entity createFloor();
    ecs::Entity	createCamera();
    ecs::Entity	createBomb();
    ecs::Entity	createExplosion();
    ecs::Entity	createMap();
    ecs::Entity	createCrate();
    ecs::Entity createPlayer();
    ecs::Entity createBonus();
  }
}

#endif //!ENTITY_HPP
