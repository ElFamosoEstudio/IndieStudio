//
// Wall.hh for bomberman in /home/akkari_a/rendu/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue Jun  6 15:06:46 2017 Adam Akkari
// Last update Wed Jun  7 10:04:44 2017 Adam Akkari
//

#ifndef WALL
# define WALL

# include "GameObject.hpp"
# include "Transform.hh"
# include "Renderer3D.hh"
# include "BoxCollider.hh"

class	Wall : public GameObject
{
private:
  Transform	*_transform;
  Renderer3D	*_renderer;
  BoxCollider	*_collider;

public:
  Wall(std::string const &name,
       irr::core::vector3df const &position);
  virtual void	update();
};

#endif // WALL
