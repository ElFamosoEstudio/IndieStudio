//
// GameObject.hpp for Bomberman in /home/akkari_a/work/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 17:53:33 2017 Adam Akkari
// Last update Sun May 14 02:03:28 2017 Adam Akkari
//

#ifndef GAMEOBJECT
# define GAMEOBJECT

# include <string>
# include <vector>
# include "Component.hpp"

class	GameObject
{
protected:
  std::vector<Component*>	_components;

public:
  GameObject(std::string const &name) : name(name) {}
  Component	*getComponent(std::string const &type);

  std::string const	&name;
};

#endif //GAMEOBJECT
