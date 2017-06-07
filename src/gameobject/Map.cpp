//
// Map.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Wed Jun  7 09:02:12 2017 Adam Akkari
// Last update Wed Jun  7 14:43:26 2017 Adam Akkari
//

#include <IAnimatedMeshSceneNode.h>
#include "Map.hh"
#include "Wall.hh"
#include "Camera.hh"
#include "Character.hh"

Map::Map(std::string const &name,
	 unsigned int size_x, unsigned int size_y)
  : GameObject(name)
{
  //Reserve enough space for the map
  _map.reserve(size_x * size_y);
  for (unsigned int i = 0; i < size_x * size_y; i++)
    _map.push_back(Block::EMPTY);
  
  //Create walls

  //Corners
  _objects.push_back(new Wall("map_wall", irr::core::vector3df(-1.0f, 0.0f, -1.0f)));
  _objects.push_back(new Wall("map_wall", irr::core::vector3df(-1.0f, 0.0f, size_y)));
  _objects.push_back(new Wall("map_wall", irr::core::vector3df(size_x, 0.0f, -1.0f)));
  _objects.push_back(new Wall("map_wall", irr::core::vector3df(size_x, 0.0f, size_y)));
  //Walls
  for (unsigned int i = 0; i < size_x; i++)
    {
      _objects.push_back(new Wall("map_wall", irr::core::vector3df(i, 0.0f, -1.0f)));
      _objects.push_back(new Wall("map_wall", irr::core::vector3df(i, 0.0f, size_y)));
      for (unsigned int j = 0; j < size_y; j++)
	{
	  if (!(i % 2) && !(j % 2) && (i + 1) < size_x && (j + 1) < size_y)
	    {
	      _objects.push_back(new Wall("map_wall", irr::core::vector3df(i + 1, 0.0f, j + 1)));
	      _map[size_x * j + i] = Block::WALL;
	    }
	  else
	    _map[size_x * j + i] = Block::EMPTY;
	  _objects.push_back(new Wall("map_wall", irr::core::vector3df(-1.0f, 0.0f, j)));
	  _objects.push_back(new Wall("map_wall", irr::core::vector3df(size_x, 0.0f, j)));
	}
    }

  //Create camera
  _objects.push_back(new Camera("camera",
				irr::core::vector3df(size_x / 2,
						     (size_x > size_y ? size_x : size_y) - 2,
						     size_y / 2 + 1),
				irr::core::vector3df(size_x / 2, 0.0f, size_y / 2)));

  //Create player
  _objects.push_back(new Character("player", irr::core::vector3df(size_x - 1, 0.0f, 0.0f)));
				   
}

Map::~Map()
{
  for (auto idx:_objects)
    delete idx;
}

void	Map::update()
{
  
}
