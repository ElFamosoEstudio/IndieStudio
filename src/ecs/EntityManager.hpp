//
// EntityManager.hpp for IndieStudio in /home/silvy_n/projects/IndieStudio/src/ecs
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu May 25 18:46:02 2017 Noam Silvy
// Last update Tue Jun 13 17:48:02 2017 Noam Silvy
//

#ifndef ENTITY_MANAGER_HPP
# define ENTITY_MANAGER_HPP

# include <iostream>
# include <utility>
# include <memory>
# include <cstdint>
# include <tuple>
# include <map>
# include <string>
# include <stdexcept>
# include "NumIdGenerator.hpp"
# include "ecs.hpp"

namespace ecs
{
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
	throw (std::out_of_range(_getOutOfRangeMsg<Comp>(id)));
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
	throw (std::out_of_range(_getOutOfRangeMsg<Comp>(id)));
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

    template<typename Comp>
    std::string _getOutOfRangeMsg(Entity id)
    {
      return (std::string("Entity ") + std::to_string(id) + " doesn't have component " + typeid(Comp).name());
    }

  private:
    std::tuple<std::map<Entity, CompTypes>...>	_entities;
    NumIdGenerator<Entity>			_idGenerator;
  };
}


#endif //ENTITY_MANAGER_HPP
