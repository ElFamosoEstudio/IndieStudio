//
// Transform.hh for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 20:02:55 2017 Adam Akkari
// Last update Tue Jun  6 15:05:54 2017 Adam Akkari
//

#ifndef TRANSFORM
# define TRANSFORM

# include <vector3d.h>
# include "Component.hpp"

# define UP	irr::core::vector3df(1.0f, 0.0f, 0.0f)
# define LEFT	irr::core::vector3df(0.0f, 0.0f, 1.0f)

class	Transform : public Component
{
public:
  Transform(GameObject &obj);
  Transform(GameObject &obj,
	    irr::core::vector3df const &position);
  Transform(GameObject &obj,
	    irr::core::vector3df const &position,
	    irr::core::vector3df const &rotation);
  Transform(GameObject &obj,
	    irr::core::vector3df const &position,
	    irr::core::vector3df const &rotation,
	    irr::core::vector3df const &scale);
  void	move(irr::core::vector3df const &direction);

  irr::core::vector3df	position;
  irr::core::vector3df	rotation;
  irr::core::vector3df	scale;
};

#endif //TRANSFORM
