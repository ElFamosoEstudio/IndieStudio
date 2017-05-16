//
// GameObject.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 20:45:48 2017 Adam Akkari
// Last update Mon May 15 00:34:51 2017 Adam Akkari
//

#include "GameObject.hpp"
#include "RessourcesLocator.hh"

GameObject::GameObject(std::string const &name) : name(name)
{
  Scene	*scene = RessourcesLocator::getScene();

  if (scene)
    scene->addGameObject(this);
}

GameObject::~GameObject()
{
  Scene	*scene = RessourcesLocator::getScene();

  if (scene)
    scene->removeGameObject(this);
}

Component	*GameObject::getComponent(std::string const &type)
{
  unsigned int	i = 0;

  while (i < _components.size())
    {
      if (_components[i]->type == type)
	return (_components[i]);
      i++;
    }
  return (nullptr);
}
