//
// GameObject.hpp for Bomberman in /home/akkari_a/work/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 17:53:33 2017 Adam Akkari
// Last update Sat May 13 21:17:59 2017 Adam Akkari
//

#ifndef GAMEOBJECT
# define GAMEOBJECT

# include <string>
# include <vector>
# include "Component.hpp"

class	GameObject
{
private:
  std::vector<Component*>	_components;

public:
  GameObject(std::string const &name) : name(name) {}
  Component	&getComponent(std::string const &type);

  std::string const	&name;
};

#endif //GAMEOBJECT
