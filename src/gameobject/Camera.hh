//
// Camera.hh for bomberman in /home/akkari_a/work/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 20:13:45 2017 Adam Akkari
// Last update Wed Jun  7 10:04:19 2017 Adam Akkari
//

#ifndef CAMERA
# define CAMERA

# include "GameObject.hpp"
# include "Transform.hh"
# include "RendererCamera.hh"

class	Camera : public GameObject
{
private:
  Transform		*_transform;
  RendererCamera	*_rendererCamera;

public:
  Camera(std::string const &name,
	 irr::core::vector3df const &position,
	 irr::core::vector3df const &lookat);
  virtual void	update();
};

#endif //CAMERA
