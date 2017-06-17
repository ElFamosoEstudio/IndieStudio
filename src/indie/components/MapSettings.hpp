//
// MapSettings.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/components
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat Jun 17 02:55:46 2017 Adam Akkari
// Last update Sat Jun 17 06:27:24 2017 Adam Akkari
//

#ifndef MAPSETTINGS_HPP
# define MAPSETTINGS_HPP

# include <list>
# include "ecs.hpp"

namespace indie
{
  namespace component
  {
    struct MapSettings
    {
      MapSettings() = delete;
      MapSettings(unsigned int x,
		  unsigned int y)
	: size_x(x), size_y(y), walls(new std::list<ecs::Entity>)
      {
	if (!(x % 2))
	  size_x += 1;
	if (!(y % 2))
	  size_y += 1;
      }
      unsigned int	size_x;
      unsigned int	size_y;
      std::list<ecs::Entity>	*walls;
    };
  }
}

#endif // MAPSETTINGS_HPP
