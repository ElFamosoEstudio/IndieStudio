//
// Component.hpp for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 20:03:59 2017 Adam Akkari
// Last update Sat May 13 22:53:02 2017 Adam Akkari
//

#ifndef COMPONENT
# define COMPONENT

# include <string>

class		GameObject;

class		Component
{
private:
  GameObject const	&_parent;

public:
  Component(GameObject const &obj, std::string const &type) : _parent(obj), type(type) {}

  std::string const	&type;
};

#endif //COMPONENT
