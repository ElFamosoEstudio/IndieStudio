//
// entity.hpp for indie studio in /home/silvy_n/IndieStudio/src/indie/entities
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 19:12:49 2017 Noam Silvy
// Last update Sun Jun 18 06:44:39 2017 akram abd-ali
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
	EXPLOSION
      };

    void	registerAllEntities();

    ecs::Entity	createBox();
    ecs::Entity	createCamera();
    ecs::Entity	createBomb();
    ecs::Entity	createExplosion();
  }
}

#endif //!ENTITY_HPP
