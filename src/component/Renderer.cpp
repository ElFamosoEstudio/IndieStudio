//
// Renderer.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 23:19:05 2017 Adam Akkari
// Last update Mon May 15 00:06:27 2017 Adam Akkari
//

#include "Renderer.hh"
#include "RessourcesLocator.hh"

Renderer::Renderer(GameObject &obj) : Component(obj, "Renderer")
{
  Scene	*scene = RessourcesLocator::getScene();

  if (scene)
    scene->addRenderer(this);
}

Renderer::~Renderer()
{
  Scene	*scene = RessourcesLocator::getScene();

  if (scene)
    scene->removeRenderer(this);
}
