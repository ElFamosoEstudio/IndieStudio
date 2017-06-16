//
// entity.hpp for indie studio in /home/silvy_n/IndieStudio/src/indie/entities
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 19:12:49 2017 Noam Silvy
// Last update Fri Jun 16 21:46:25 2017 Adam Akkari
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
	BOX
      };

    void	registerAllEntities();

    ecs::Entity	createBox();
  }
}

#endif //!ENTITY_HPP
