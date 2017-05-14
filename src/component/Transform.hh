//
// Transform.hh for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 20:02:55 2017 Adam Akkari
// Last update Sun May 14 02:00:39 2017 Adam Akkari
//

#ifndef TRANSFORM
# define TRANSFORM

# include <vector3d.h>
# include "Component.hpp"

class	Transform : public Component
{
public:
  Transform(GameObject &obj,
	    float px = 0, float py = 0, float pz = 0,
	    float rx = 0, float ry = 0, float rz = 0,
	    float sx = 1, float sy = 1, float sz = 1);

  irr::core::vector3df	position;
  irr::core::vector3df	rotation;
  irr::core::vector3df	scale;
};

#endif //TRANSFORM
