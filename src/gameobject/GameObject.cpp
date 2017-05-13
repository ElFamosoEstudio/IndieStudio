//
// GameObject.cpp for bomberman in /home/akkari_a/work/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 20:45:48 2017 Adam Akkari
// Last update Sat May 13 22:51:28 2017 Adam Akkari
//

#include "GameObject.hpp"

Component	&GameObject::getComponent(std::string const &type)
{
  for (auto const &idx:_components)
    if (idx->type == type)
      return (*idx);
  throw;
}
