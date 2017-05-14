//
// GameObject.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 20:45:48 2017 Adam Akkari
// Last update Sun May 14 02:11:55 2017 Adam Akkari
//

#include "GameObject.hpp"

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
