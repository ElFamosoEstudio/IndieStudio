//
// Transform.hh for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 20:02:55 2017 Adam Akkari
// Last update Sun May 14 22:49:53 2017 Adam Akkari
//

#ifndef TRANSFORM
# define TRANSFORM

# include <vector3d.h>
# include "Component.hpp"

class	Transform : public Component
{
public:
  Transform(GameObject &obj);
  Transform(GameObject &obj,
	    irr::core::vector3df &position);
  Transform(GameObject &obj,
	    irr::core::vector3df &position,
	    irr::core::vector3df &rotation);
  Transform(GameObject &obj,
	    irr::core::vector3df &position,
	    irr::core::vector3df &rotation,
	    irr::core::vector3df &scale);

  irr::core::vector3df	position;
  irr::core::vector3df	rotation;
  irr::core::vector3df	scale;
};

#endif //TRANSFORM
