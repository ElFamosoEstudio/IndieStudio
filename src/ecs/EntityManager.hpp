//
// EntityManager.hpp for IndieStudio in /home/silvy_n/projects/IndieStudio/src/ecs
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu May 25 18:46:02 2017 Noam Silvy
// Last update Sat May 27 19:28:36 2017 Noam Silvy
//

#ifndef INDIESTUDIO_ENTITYMANAGER_HPP
# define INDIESTUDIO_ENTITYMANAGER_HPP

#include <iostream>
#include <utility>
#include <memory>
#include <cstdint>
#include <tuple>
#include <map>
#include <unordered_map>
#include "NumIdGenerator.hpp"

namespace ecs
{
  using Entity = std::uint32_t;
  using CTypeSize = std::uint16_t;

  enum class CType : CTypeSize
    {
      POS2D,
      POS3D,
      VELOCITY
    };

  // template<typename Tuple, typename Map, size_t ...I>
  // void generateKeyToIndex(std::index_sequence<I...>, Tuple &tuple, Map &keyToIndex, CTypeSize idx);

  // template<typename Tuple, typename Map>
  // void generateKeyToIndex(std::index_sequence<>, Tuple &tuple, Map &keyToIndex, CTypeSize idx)
  // {}

  // template<typename Tuple, typename Map, size_t I, size_t ...Rest>
  // void generateKeyToIndex(std::index_sequence<I, Rest...>,
  // 			  Tuple		&tuple,
  // 			  Map		&keyToIndex,
  // 			  CTypeSize	idx)
  // {
  //   const CTypeSize lol = idx;
  //   auto m = std::get<I>(tuple);
  //   auto typeKey = decltype(m)::mapped_type::TYPE;
  //   keyToIndex[typeKey] = idx;
  //   generateKeyToIndex(std::index_sequence<Rest...>(), tuple, keyToIndex, idx + 1);
  // }

  template<typename ...CompTypes>
  class EntityManager
  {
    template<typename CompType>
    using map_of = std::map<Entity, CompType>;

  public:
    EntityManager()
    {
      // generateKeyToIndex(std::index_sequence_for<CompTypes...>(), _entities, _keyToIndex, 0);
    }

    ~EntityManager() = default;
    EntityManager(EntityManager const &) = delete;
    EntityManager	&operator=(EntityManager const &) = delete;

    Entity		createEntity() { return (_idGenerator.createId()); }

    // TODO: Throw Exception
    template<typename Comp>
    void		addComponent(Entity id, Comp const &comp)
    {
      std::get<map_of<Comp>>(_entities)[id] = comp;
    }

    // Might be better to return a shared_ptr or a custom iterator
    // TODO: Throw Exception
    template<typename Comp>
    Comp*		getComponent(Entity id)
    {
      auto &components = std::get<map_of<Comp>>(_entities);
      auto it = components.find(id);
      if (it == components.end())
      	return (nullptr);
      return (&it->second);
    }

    // Might be better to return a shared_ptr or a custom iterator
    // TODO: Throw Exception
    template<typename Comp>
    std::map<Entity, Comp>&		getAllComponents()
    {
      return (std::get<map_of<Comp>>(_entities));
    }

  private:
    std::tuple<std::map<Entity, CompTypes>...>	_entities;
    NumIdGenerator<Entity>			_idGenerator;
    // std::unordered_map<CTypeSize, CTypeSize>	_keyToIndex;
  };
}


#endif //INDIESTUDIO_ENTITYMANAGER_HPP
