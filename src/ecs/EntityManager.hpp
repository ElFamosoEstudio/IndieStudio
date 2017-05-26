//
// EntityManager.hpp for IndieStudio in /home/silvy_n/projects/IndieStudio/src/ecs
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu May 25 18:46:02 2017 Noam Silvy
// Last update Fri May 26 22:16:43 2017 Noam Silvy
//

#ifndef INDIESTUDIO_ENTITYMANAGER_HPP
# define INDIESTUDIO_ENTITYMANAGER_HPP

#include <cstdint>
#include <tuple>
#include <map>
#include "NumIdGenerator.hpp"

namespace ecs
{
  using Entity = std::uint32_t;

  template<typename ...CompTypes>
  class EntityManager
  {
  public:
    EntityManager() = default;
    ~EntityManager() = default;
    EntityManager(EntityManager const &) = delete;
    EntityManager	&operator=(EntityManager const &) = delete;

    Entity		createEntity() { return (_idGenerator.createId()); }

  private:
    std::tuple<std::map<Entity, CompTypes>...>	_entities;
    NumIdGenerator<Entity>			_idGenerator;
  };
}

#endif //INDIESTUDIO_ENTITYMANAGER_HPP
