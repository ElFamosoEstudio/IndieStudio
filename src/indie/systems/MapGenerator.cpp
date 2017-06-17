//
// MapGenerator.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat Jun 17 05:13:04 2017 Adam Akkari
// Last update Sat Jun 17 06:29:17 2017 Adam Akkari
//

#include <iostream>
#include "indie.hpp"
#include "MapGenerator.hpp"

using namespace indie::component;

bool		indie::system::MapGenerator::init_map()
{
  auto		&settings = indie::engine::entityManager().getAllComponents<MapSettings>();
  unsigned int	size_x = settings.begin()->second->size_x;
  unsigned int	size_y = settings.begin()->second->size_y;
  std::list<ecs::Entity>	*walls = settings.begin()->second->walls;

  std::cout << "suce bien ma bite " << size_x << std::endl;

  walls->push_back(indie::engine::entityManager().create
		  (indie::entity::BOX, Transform(-1, -1, 0)));
  walls->push_back(indie::engine::entityManager().create
		  (indie::entity::BOX, Transform(size_x, -1, 0)));
  walls->push_back(indie::engine::entityManager().create
		  (indie::entity::BOX, Transform(-1, size_y, 0)));
  walls->push_back(indie::engine::entityManager().create
		  (indie::entity::BOX, Transform(size_x, size_y, 0)));
  for (unsigned int i = 0; i < size_x; i++)
    {
      walls->push_back(indie::engine::entityManager().create
		      (indie::entity::BOX, Transform(i, -1, 0)));
      walls->push_back(indie::engine::entityManager().create
		      (indie::entity::BOX, Transform(i, size_y, 0)));
    }
  for (unsigned int j = 0; j < size_y; j++)
    {
      walls->push_back(indie::engine::entityManager().create
		      (indie::entity::BOX, Transform(-1, j, 0)));
      walls->push_back(indie::engine::entityManager().create
		      (indie::entity::BOX, Transform(size_x, j, 0)));
    }
  std::cout << "sale pute " << walls->size() << std::endl;
  return (true);
}

void		indie::system::MapGenerator::update()
{
  static bool	init = init_map();
}

ecs::SysType	indie::system::MapGenerator::type() const
{
  return (system::MAP_GENERATOR);
}

ecs::ISystem	*indie::system::MapGenerator::create()
{
  return (new MapGenerator);
}
