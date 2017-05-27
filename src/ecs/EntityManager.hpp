//
// EntityManager.hpp for IndieStudio in /home/silvy_n/projects/IndieStudio/src/ecs
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu May 25 18:46:02 2017 Noam Silvy
// Last update Sat May 27 02:14:32 2017 akram abd-ali
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


template <typename... T, std::size_t... I>
void toTpl_(const JVal& mV, std::tuple<T...>& mX, std::index_sequence<I...>)
{
    (void) std::initializer_list<int>{ (std::get<I>(mX) = mV[I].as<T>(), 0)... };
}

template <typename... TS>
void toTpl(const JVal& mV, std::tuple<TS...>& mX)
{
    toTpl_(mV, mX, std::index_sequence_for<TS...>() );
}


 template<typename ...Types, CTypeSize ...I>
  void	generateKeyToIndex(std::unordered_map<CTypeSize, CTypeSize>&,
  			   std::integer_sequence<CTypeSize, I...>);
   
  template<>
  void	generateKeyToIndex(std::unordered_map<CTypeSize, CTypeSize>&)
  {
  }
  
  template<typename T, typename ...Types, CTypeSize I, CTypeSize ...Rest>
  void	generateKeyToIndex(std::unordered_map<CTypeSize, CTypeSize>& map,
			   std::integer_sequence<CTypeSize, I, Rest...>)
  {
    map[T::TYPE] = I;
    generateKeyToIndex<Types..., Rest...>(map, std::integer_sequence<CTypeSize,
					  Rest...>());
  }



  
  // template<typename ...Types, CTypeSize ...I>
  // void	generateKeyToIndex(std::unordered_map<CTypeSize, CTypeSize>&,
  // 			   std::integer_sequence<CTypeSize, I...>);
   
  // template<>
  // void	generateKeyToIndex(std::unordered_map<CTypeSize, CTypeSize>&)
  // {
  // }
  
  // template<typename T, typename ...Types, CTypeSize I, CTypeSize ...Rest>
  // void	generateKeyToIndex(std::unordered_map<CTypeSize, CTypeSize>& map,
  // 			   std::integer_sequence<CTypeSize, I, Rest...>)
  // {
  //   map[T::TYPE] = I;
  //   generateKeyToIndex<Types..., Rest...>(map, std::integer_sequence<CTypeSize,
  // 					  Rest...>());
  // }
  

  template<typename ...CompTypes>
  class EntityManager
  {
  public:
    EntityManager()
    {
      generateKeyToIndex<CompTypes...>(_keyToIndex,
				       std::make_integer_sequence<CTypeSize,
				       sizeof ...(CompTypes)>{});
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


  private:
    std::tuple<std::map<Entity, CompTypes>...>	_entities;
    NumIdGenerator<Entity>			_idGenerator;
    std::unordered_map<CTypeSize, CTypeSize>		_keyToIndex;
  public:
    void					lol()
    {
      for (auto const  &el : _keyToIndex)
	std::cout << el.second << std::endl;
    }
  };

}


#endif //INDIESTUDIO_ENTITYMANAGER_HPP
