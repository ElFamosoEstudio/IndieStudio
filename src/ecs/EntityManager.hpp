//
// EntityManager.hpp for IndieStudio in /home/silvy_n/projects/IndieStudio/src/ecs
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu May 25 18:46:02 2017 Noam Silvy
// Last update Sat May 27 05:23:42 2017 Noam Silvy
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

  template<typename Tuple, // typename Map,
	   size_t ...I>
  void generateKeyToIndex(std::index_sequence<I...>,
			  Tuple &tuple// ,
			  // Map &keyToIndex
			  );

  template<typename Tuple// , typename Map
	   >
  void generateKeyToIndex(std::index_sequence<>, Tuple &tuple// , Map &keyToIndex
			  ) {}

  template<typename Tuple, // typename Map,
	   size_t I, size_t ...Rest>
  void generateKeyToIndex(std::index_sequence<I, Rest...>, Tuple &tuple// , Map &keyToIndex
			  )
  {
    auto m = std::get<I>(tuple);
    std::cout << decltype(m)::mapped_type::TYPE << std::endl;
    generateKeyToIndex(std::index_sequence<Rest...>(), tuple// , keyToIndex
		       );
  }

  template<typename ...CompTypes>
  class EntityManager
  {
  public:
    EntityManager()
    {
      generateKeyToIndex(std::index_sequence_for<CompTypes...>(), _entities// , _keyToIndex
			 );
    }

    ~EntityManager() = default;
    EntityManager(EntityManager const &) = delete;
    EntityManager	&operator=(EntityManager const &) = delete;

    Entity		createEntity() { return (_idGenerator.createId()); }

    template<typename Comp>
    void		addComponent(Entity id, Comp const &comp)
    {
      std::get<Comp::TYPE>(_entities)[id] = comp;
    }

    template<typename Comp>
    Comp*		getComponent(Entity id)
    {

      auto map = std::get<Comp::TYPE>(_entities);
      auto it = map.find(id);
      if (it == map.end())
	return (NULL);
      return (std::addressof(*it));
    }

    template<typename Comp>
    std::map<Entity, Comp>&		getAllComponents()
    {
      // auto map = std::get<Comp::TYPE>(_entities);
      // auto it = map.find(id);
      // if (it == map.end())
      // 	return (NULL);
      // return (std::addressof(*it));
    }

  private:
    std::tuple<std::map<Entity, CompTypes>...>	_entities;
    NumIdGenerator<Entity>			_idGenerator;
    std::unordered_map<CTypeSize, std::size_t>	_keyToIndex;
  public:
    // void					lol()
    // {
    //   for (auto const  &el : _keyToIndex)
    // 	std::cout << el.second << std::endl;
    // }
  };

}


#endif //INDIESTUDIO_ENTITYMANAGER_HPP
