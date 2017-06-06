//
// test.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/scenes
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 22:54:00 2017 Adam Akkari
// Last update Tue Jun  6 15:13:22 2017 Adam Akkari
//

#include <irrlicht.h>
#include "Scene.hh"
#include "Camera.hh"
#include "Character.hh"
#include "Wall.hh"

void	loadTest(Scene *scene)
{
  Camera	*main = new Camera("main", irr::core::vector3df(-0.5f, 3.0f, 0.0f),
				   irr::core::vector3df(0.0f, 0.0f, 0.0f));
  Character	*player = new Character("player", irr::core::vector3df(0.0f, 0.0f, 0.0f));
  Wall		*wall = new Wall("wall", irr::core::vector3df(0.0f, 0.0f, 2.0f));

  (void)main;
  (void)scene;
  (void)player;
  (void)wall;
}
