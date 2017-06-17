//
// entity.hpp for indie studio in /home/silvy_n/IndieStudio/src/indie/entities
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 19:12:49 2017 Noam Silvy
// Last update Sat Jun 17 22:33:56 2017 Adam Akkari
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
	FLOOR,
	CAMERA,
	MAP
      };

    void	registerAllEntities();

    ecs::Entity	createBox();
    ecs::Entity createFloor();
    ecs::Entity	createCamera();
    ecs::Entity	createMap();
  }
}

#endif //!ENTITY_HPP
