//
// entity.hpp for indie studio in /home/silvy_n/IndieStudio/src/indie/entities
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 19:12:49 2017 Noam Silvy
// Last update Sat Jun 17 10:07:12 2017 akram abd-ali
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
	BOMB
      };

    void	registerAllEntities();

    ecs::Entity	createBox();
    ecs::Entity	createCamera();
    ecs::Entity	createBomb();
  }
}

#endif //!ENTITY_HPP
