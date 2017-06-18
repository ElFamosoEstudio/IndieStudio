//
// MapGenerator.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat Jun 17 05:13:04 2017 Adam Akkari
// Last update Sun Jun 18 19:59:20 2017 Adam Akkari
//

#include <chrono>
#include <random>
#include "indie.hpp"
#include "MapGenerator.hpp"

using namespace indie::component;

indie::system::MapGenerator::MapGenerator()
{
  key1 = engine::eventManager().subscribe
    (event::BOMB_DROPPED, &indie::system::MapGenerator::bombDropped, this);
}

indie::system::MapGenerator::~MapGenerator()
{
}

void		indie::system::MapGenerator::bombDropped(ecs::Entity ent)
{
  auto		&settings = indie::engine::entityManager().getAllComponents<MapSettings>();
  auto		&ent_tsfm = indie::engine::entityManager().getComponent<Transform>(ent);
  if (settings.size() == 0 || !ent_tsfm)
    {
      engine::eventManager().emit(event::DROP_BOMB_ERR, ent);
      return ;
    }
  auto			&data = settings.begin()->second->map;
  unsigned int		size_x = settings.begin()->second->size_x;
  irr::core::vector3df	new_pos(round(ent_tsfm->position.X),
				round(ent_tsfm->position.Y),
				round(ent_tsfm->position.Z));

  if (data[new_pos.X + size_x * new_pos.Y].second == BLOCK)
    engine::eventManager().emit(event::DROP_BOMB_ERR, ent);
  else
    data[new_pos.X + size_x * new_pos.Y].second = indie::component::BOMB;
}

void	placeCrate(unsigned int i, unsigned int j,
		   unsigned int size_x, unsigned int size_y,
		   std::vector<std::pair<ecs::Entity, element> > &data,
		   unsigned int val)
{
  if ((!(i < 3 && j < 3) || (i == 2 && j == 2)) &&
      (!(i < 3 && j > size_y - 4) || (i == 2 && j == size_y - 3)) &&
      (!(i > size_x - 4 && j < 3) || (i == size_x - 3 && j == 2)) &&
      (!(i > size_x - 4 && j > size_y - 4) || (i == size_x - 3 && j == size_x - 3)))
    {
      if (val % 10)
	{
	  data[j * size_x + i].first = indie::engine::entityManager().create
	    (indie::entity::CRATE, Transform(i, j, 0));
	  data[j * size_x + i].second = CRATE;
	}
    }
}

bool		indie::system::MapGenerator::init_map()
{
  static bool	initiated = false;
  auto		&settings = indie::engine::entityManager().getAllComponents<MapSettings>();
  if (settings.size() == 0 || settings.size() > 1 || initiated)
    return (false);
  unsigned int	size_x = settings.begin()->second->size_x;
  unsigned int	size_y = settings.begin()->second->size_y;
  unsigned int	max_size = size_x > size_y ? size_x : size_y;
  std::list<ecs::Entity>	&boxes = settings.begin()->second->boxes;
  std::vector<std::pair<ecs::Entity, element> >	&data = settings.begin()->second->map;
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 gen(seed);
  
  boxes.push_back(indie::engine::entityManager().create
		  (indie::entity::BOX, Transform(-1, -1, 0)));
  boxes.push_back(indie::engine::entityManager().create
		  (indie::entity::BOX, Transform(size_x, -1, 0)));
  boxes.push_back(indie::engine::entityManager().create
		  (indie::entity::BOX, Transform(-1, size_y, 0)));
  boxes.push_back(indie::engine::entityManager().create
		  (indie::entity::BOX, Transform(size_x, size_y, 0)));
  for (unsigned int i = 0; i < size_x; i++)
    {
      boxes.push_back(indie::engine::entityManager().create
		      (indie::entity::BOX, Transform(i, -1, 0)));
      boxes.push_back(indie::engine::entityManager().create
		      (indie::entity::BOX, Transform(i, size_y, 0)));
      for (unsigned int j = 0; j < size_y; j++)
	{
	  if ((i % 2) && (j % 2))
	    {
	      data[j * size_x + i].first = indie::engine::entityManager().create
		(indie::entity::BOX, Transform(i, j, 0));
	      data[j * size_x + i].second = BLOCK;
	    }
	  else
	    placeCrate(i, j, size_x, size_y, data, gen());
	  boxes.push_back(indie::engine::entityManager().create
			  (indie::entity::BOX, Transform(-1, j, 0)));
	  boxes.push_back(indie::engine::entityManager().create
			  (indie::entity::BOX, Transform(size_x, j, 0)));
	  boxes.push_back(indie::engine::entityManager().create
			  (indie::entity::FLOOR, Transform(i, j, -1)));
	}
    }

  camera = indie::engine::entityManager().create(indie::entity::CAMERA);
  indie::engine::entityManager().getComponent<Transform>(camera)->position
    = irr::core::vector3df(max_size / 2, (float)(- (max_size / 2 - 0.5)), max_size);
  indie::engine::entityManager().getComponent<Camera>(camera)->lookat
    = irr::core::vector3df(max_size / 2, max_size / 2, 0);

  return (true);
}

void		indie::system::MapGenerator::update()
{
  static bool	init = init_map();

  if (!init)
    init = init_map();
}

ecs::SysType	indie::system::MapGenerator::type() const
{
  return (system::MAP_GENERATOR);
}

ecs::ISystem	*indie::system::MapGenerator::create()
{
  return (new MapGenerator);
}
