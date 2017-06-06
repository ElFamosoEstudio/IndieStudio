//
// BoxCollider.hh for bomberman in /home/akkari_a/rendu/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue May 23 08:14:53 2017 Adam Akkari
// Last update Tue Jun  6 11:07:39 2017 Adam Akkari
//

#ifndef BOXCOLLIDER
# define BOXCOLLIDER

# include <aabbox3d.h>
# include "Component.hpp"

class	BoxCollider : public Component
{
private:
  irr::core::vector3df	_size;

public:
  BoxCollider(GameObject &obj, irr::core::vector3df const &size);
  ~BoxCollider();
  irr::core::aabbox3d<irr::f32>	getBoundingBox() const;
  bool	checkCollision();
};

#endif // BOXCOLLIDER
