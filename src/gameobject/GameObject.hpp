//
// GameObject.hpp for Bomberman in /home/akkari_a/work/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 17:53:33 2017 Adam Akkari
// Last update Wed Jun  7 10:53:14 2017 Adam Akkari
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
  GameObject(std::string const &name);
  virtual ~GameObject();
  Component	*getComponent(std::string const &type);
  virtual void	update() = 0;

  std::string const	name;
};

#endif //GAMEOBJECT
