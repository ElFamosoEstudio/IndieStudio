//
// EntityManager.hpp for IndieStudio in /home/silvy_n/projects/IndieStudio/src/ecs
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu May 25 18:46:02 2017 Noam Silvy
// Last update Sun Jun 18 02:06:31 2017 Noam Silvy
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
# include "EntityManager.hpp"

namespace ecs
{
  using Entity = uint32_t;
  using EntityType = uint32_t;

  template<typename ...CompTypes>
  class EntityManager
  {
    template<typename Comp>
    using CompPtr = std::unique_ptr<Comp>;

    template<typename CompType>
    using map_of = std::map<Entity, CompPtr<CompType>>;

  private:
    std::tuple<std::map<Entity, CompPtr<CompTypes>>...>		_entities;
    NumIdGenerator<Entity>					_idGenerator;
    std::map<EntityType, std::function<Entity()>>		_factories;

  public:
    EntityManager() = default;
    ~EntityManager() = default;
    EntityManager(EntityManager const &) = delete;
    EntityManager	&operator=(EntityManager const &) = delete;

    void registerEntity(EntityType type, std::function<Entity()> func)
    {
      _factories[type] = func;
    }

    template<typename ...Args>
    Entity create(EntityType type, Args&&... args)
    {
      auto it = _factories.find(type);
      if (it == _factories.end())
	throw (std::out_of_range("EntityManager: \"Unkown factory type\""));
      auto id = it->second();
      (void)std::initializer_list<int>{ (this->addComponent(id, std::forward<Args>(args), true), 0)...};
      return (id);
    }

    Entity		createEntity() { return (_idGenerator.createId()); }

    template<typename Comp>
    void		addComponent(Entity id, Comp const &comp, bool replace = false)
    {
      auto &components = std::get<map_of<Comp>>(_entities);
      auto it = components.find(id);

      if (!replace && it != components.end())
	return ;
      components[id] = std::make_unique<Comp>(comp);
    }

    // Constructs a Comp object with @args, eventually replacing existing one
    template<typename Comp, typename ...Args>
    void		addComponentEmplace(Entity id, Args&& ...args)
    {
      std::get<map_of<Comp>>(_entities)[id] = std::make_unique<Comp>(std::forward<Args>(args)...);
    }

    template<typename Comp>
    CompPtr<Comp>&		getComponent(Entity id)
    {
      static auto nullComp = std::move(std::unique_ptr<Comp>());
      auto &components = std::get<map_of<Comp>>(_entities);
      auto it = components.find(id);

      if (it == components.end())
	return (nullComp);
      return (it->second);
    }

    template<typename Comp>
    std::map<Entity, CompPtr<Comp>>&	getAllComponents()
    {
      return (std::get<map_of<Comp>>(_entities));
    }

    template<typename Comp>
    void				removeComponent(Entity id)
    {
      auto &components = std::get<map_of<Comp>>(_entities);
      auto it = components.find(id);

      if (it == components.end())
	throw (std::out_of_range(_getOutOfRangeMsg<Comp>(id))); // or return ;
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
  };
}


#endif //ENTITY_MANAGER_HPP
