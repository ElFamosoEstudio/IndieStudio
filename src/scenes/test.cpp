//
// test.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/scenes
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 22:54:00 2017 Adam Akkari
// Last update Mon May 15 00:42:42 2017 Adam Akkari
//

#include <irrlicht.h>
#include "Scene.hh"
#include "Camera.hh"
#include "RotatingRock.hh"

void	loadTest(Scene *scene)
{
  Camera	*main = new Camera("main", irr::core::vector3df(0.0f, 0.0f, 0.0f),
				   irr::core::vector3df(0.0f, 0.0f, 2.0f));
  RotatingRock	*rock = new RotatingRock("rock", irr::core::vector3df(0.0f, 0.0f, 2.0f));

  (void)main;
  (void)rock;
  (void)scene;
}
