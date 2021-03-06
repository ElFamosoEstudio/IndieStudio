//
// MapGenerator.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat Jun 17 04:39:24 2017 Adam Akkari
// Last update Sun Jun 18 21:53:19 2017 Adam Akkari
//

#ifndef MAP_GENERATOR_HPP
# define MAP_GENERATOR_HPP

# include "ASystem.hpp"
# include "ecs.hpp"

namespace indie
{
  namespace system
  {
    class MapGenerator : public ASystem
    {
    public:
      MapGenerator();
      ~MapGenerator();
      void		checkDamage(ecs::Entity ent);
      void		bombDropped(ecs::Entity ent);
      bool		init_map();
      void		update();
      ecs::SysType	type() const;
      static ISystem	*create();

      ecs::Entity	camera;
    };
  }
}

#endif // MAP_GENERATOR_HPP
