//
// EntityManager.hpp for IndieStudio in /home/silvy_n/projects/IndieStudio/src/ecs
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu May 25 18:46:02 2017 Noam Silvy
// Last update Thu Jun  8 01:22:47 2017 akram abd-ali
//

#ifndef INDIESTUDIO_ENTITYMANAGER_HPP
# define INDIESTUDIO_ENTITYMANAGER_HPP

# include <iostream>
# include <utility>
# include <memory>
# include <cstdint>
# include <tuple>
# include <experimental/tuple>
# include <map>
# include <exception>
# include "NumIdGenerator.hpp"
# include "ecs.hpp"

namespace ecs
{
  using CTypeSize = std::uint16_t;

  enum class CType : CTypeSize
    {
      POS2D,
      POS3D,
      VELOCITY
    };

  template<typename ...CompTypes>
  class EntityManager
  {
    template<typename CompType>
    using map_of = std::map<Entity, CompType>;

  public:
    EntityManager() = default;

    ~EntityManager() = default;
    EntityManager(EntityManager const &) = delete;
    EntityManager	&operator=(EntityManager const &) = delete;

    Entity		createEntity() { return (_idGenerator.createId()); }

    template<typename Comp>
    void		addComponent(Entity id, Comp const &comp, bool replace = false)
    {
      auto &components = std::get<map_of<Comp>>(_entities);
      auto it = components.find(id);

      if (!replace && it != components.end())
	return ;
      components[id] = comp;
    }

    // Constructs a Comp object with @args, eventually replacing existing one
    template<typename Comp, typename ...Args>
    void		addComponentEmplace(Entity id, Args& ...args)
    {
      std::get<map_of<Comp>>(_entities)[id] = Comp(args...);
    }

    template<typename Comp>
    Comp&		getComponent(Entity id)
    {
      auto &components = std::get<map_of<Comp>>(_entities);
      auto it = components.find(id);

      if (it == components.end())
	throw (std::exception());
      return (it->second);
    }

    template<typename Comp>
    std::map<Entity, Comp>&		getAllComponents()
    {
      return (std::get<map_of<Comp>>(_entities));
    }

    template<typename Comp>
    void				removeComponent(Entity id)
    {
      auto &components = std::get<map_of<Comp>>(_entities);
      auto it = components.find(id);

      if (it == components.end())
	throw (std::exception());
      components.erase(it);
    }

    void				removeEntity(Entity id)
    {
      static auto rmEntity = [id](auto &components) {
	auto it = components.find(id);
	if (it != components.end())
	  components.erase(it);
      };
      _call(rmEntity, _entities);
    }

  private:
    template<typename Function, typename Tuple>
    auto _call(Function &&f, Tuple &t, std::index_sequence<>)
    {}

    template<typename Function, typename Tuple, size_t I, size_t ...Rest>
    auto _call(Function &&f, Tuple &t, std::index_sequence<I, Rest...>)
    {
      f(std::get<I>(t));
      _call(f, t, std::index_sequence<Rest...>());
    }

    template<typename Function, typename Tuple>
    auto _call(Function &&f, Tuple &t)
    {
      static constexpr auto size = std::tuple_size<Tuple>::value;
      return (_call(f, t, std::make_index_sequence<size>()));
    }

  private:
    std::tuple<std::map<Entity, CompTypes>...>	_entities;
    NumIdGenerator<Entity>			_idGenerator;
    // std::unordered_map<CTypeSize, CTypeSize>	_keyToIndex;
  };
}


#endif //INDIESTUDIO_ENTITYMANAGER_HPP


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
      // generateKeyToIndex(std::index_sequence_for<CompTypes...>(), _entities, _keyToIndex, 0);
