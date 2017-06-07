//
// Map.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Wed Jun  7 09:02:12 2017 Adam Akkari
// Last update Wed Jun  7 11:14:47 2017 Adam Akkari
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
    }
  for (unsigned int i = 0; i < size_y; i++)
    {
      _objects.push_back(new Wall("map_wall", irr::core::vector3df(-1.0f, 0.0f, i)));
      _objects.push_back(new Wall("map_wall", irr::core::vector3df(size_x, 0.0f, i)));
    }

  //Create camera
  _objects.push_back(new Camera("camera",
				irr::core::vector3df(size_x / 2 - 0.5f,
						     size_x > size_y ? size_x : size_y,
						     size_y / 2 + 1),
				irr::core::vector3df(size_x / 2 - 0.5f, 0.0f, size_y / 2)));

  //Create player
  _objects.push_back(new Character("player", irr::core::vector3df(0.0f, 0.0f, 0.0f)));
				   
}

Map::~Map()
{
  for (auto idx:_objects)
    delete idx;
}

void	Map::update()
{
  
}
