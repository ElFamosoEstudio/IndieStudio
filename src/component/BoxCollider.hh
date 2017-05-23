//
// BoxCollider.hh for bomberman in /home/akkari_a/rendu/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue May 23 08:14:53 2017 Adam Akkari
// Last update Tue May 23 10:03:00 2017 Adam Akkari
//

#ifndef BOXCOLLIDER
# define BOXCOLLIDER

# include <irrlicht.h>
# include "Component.hpp"

class	BoxCollider : public Component
{
private:
  irr::core::vector3df	_size;

public:
  BoxCollider(GameObject &obj, irr::core::vector3df const &size);
  irr::core::aabbox3d<irr::f32>	getBoundingBox() const;
};

#endif // BOXCOLLIDER
