//
// RotatingRock.hh for bomberman in /home/akkari_a/work/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 23:51:13 2017 Adam Akkari
// Last update Mon May 15 00:12:35 2017 Adam Akkari
//

#ifndef ROTATING_ROCK
# define ROTATING_ROCK

# include "GameObject.hpp"
# include "Transform.hh"
# include "Renderer3D.hh"

class	RotatingRock : public GameObject
{
private:
  Transform	*_transform;
  Renderer3D	*_renderer;

public:
  RotatingRock(std::string const &name,
	       irr::core::vector3df const &position);
  virtual void	update();
};

#endif //ROTATING_ROCK
