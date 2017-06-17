//
// MapSettings.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/components
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat Jun 17 02:55:46 2017 Adam Akkari
// Last update Sat Jun 17 03:53:47 2017 Adam Akkari
//

#ifndef MAPSETTINGS_HPP
# define MAPSETTINGS_HPP

namespace indie
{
  namespace component
  {
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
	indie::engine::entityManager().create(indie::entity::BOX, Transform(-1, -1, 0));
	indie::engine::entityManager().create(indie::entity::BOX, Transform(size_x, -1, 0));
	indie::engine::entityManager().create(indie::entity::BOX, Transform(-1, size_y, 0));
	indie::engine::entityManager().create(indie::entity::BOX, Transform(size_x, size_y, 0));
	for (unsigned int i = 0; i < size_x; i++)
	  {
	    indie::engine::entityManager().create(indie::entity::BOX, Transform(i, -1, 0));
	    indie::engine::entityManager().create(indie::entity::BOX, Transform(i, size_y, 0));
	  }
	for (unsigned int j = 0; j < size_y; j++)
	  {
	    indie::engine::entityManager().create(indie::entity::BOX, Transform(-1, j, 0));
	    indie::engine::entityManager().create(indie::entity::BOX, Transform(size_x, j, 0));
	  }
      }
      unsigned int	size_x;
      unsigned int	size_y;
    };
  }
}

#endif // MAPSETTINGS_HPP
