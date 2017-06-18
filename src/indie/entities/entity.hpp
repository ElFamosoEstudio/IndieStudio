//
// entity.hpp for indie studio in /home/silvy_n/IndieStudio/src/indie/entities
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 19:12:49 2017 Noam Silvy
// Last update Sun Jun 18 13:02:07 2017 Adam Akkari
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
	PLAYER
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
  }
}

#endif //!ENTITY_HPP
