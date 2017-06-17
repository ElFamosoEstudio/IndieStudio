//
// MapGenerator.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat Jun 17 04:39:24 2017 Adam Akkari
// Last update Sat Jun 17 20:44:49 2017 Adam Akkari
//

#ifndef MAP_GENERATOR_HPP
# define MAP_GENERATOR_HPP

# include <unordered_map>
# include "ecs.hpp"

namespace indie
{
  namespace system
  {
    class MapGenerator : public ecs::ISystem
    {
    public:
      MapGenerator();
      ~MapGenerator();
      void		bombDropped(ecs::Entity ent);
      bool		init_map();
      void		update();
      ecs::SysType	type() const;
      static ISystem	*create();

      std::unordered_map<ecs::EventKey, ecs::EventTypeDefault>	keys;
    };
  }
}

#endif // MAP_GENERATOR_HPP
