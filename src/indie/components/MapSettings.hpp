//
// MapSettings.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/components
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat Jun 17 02:55:46 2017 Adam Akkari
// Last update Sun Jun 18 18:51:45 2017 julien
//

#ifndef MAPSETTINGS_HPP
# define MAPSETTINGS_HPP

# include <list>
# include <vector>
# include <utility>
# include "ecs.hpp"

namespace indie
{
  namespace component
  {
    enum element
      {
	EMPTY,
	BLOCK,
	CRATE,
	BOMB,
	EXPL
      };
    
    struct MapSettings
    {
      MapSettings() = delete;
      MapSettings(unsigned int x,
		  unsigned int y)
	: size_x(x), size_y(y)
      {
	if (!(x % 2))
	  size_x += 1;
	if (!(y % 2))
	  size_y += 1;
	map.reserve(size_x * size_y);
	for (unsigned int i = 0; i < size_x * size_y; i++)
	  map.push_back(std::pair<ecs::Entity, element>(-1, EMPTY));
      }
      unsigned int	size_x;
      unsigned int	size_y;
      std::string	AsciiMap;
      std::list<ecs::Entity>	boxes;
      std::vector<std::pair<ecs::Entity, element> >	map;
    };
  }
}

#endif // MAPSETTINGS_HPP
