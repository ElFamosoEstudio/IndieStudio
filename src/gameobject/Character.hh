//
// Character.hh for bomberman in /home/akkari_a/rendu/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue Jun  6 11:43:04 2017 Adam Akkari
// Last update Wed Jun  7 10:16:52 2017 Adam Akkari
//

#ifndef CHARACTER
# define CHARACTER

# include <vector3d.h>
# include "GameObject.hpp"
# include "Transform.hh"
# include "Renderer3D.hh"
# include "BoxCollider.hh"

class	Character : public GameObject
{
private:
  Transform	*_transform;
  Renderer3D	*_renderer;
  BoxCollider	*_collider;

public:
  Character(std::string const &name,
	    irr::core::vector3df const &position);
  virtual void	update();
};

#endif // CHARACTER