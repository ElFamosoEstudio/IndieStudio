//
// RendererCamera.hh for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 22:15:00 2017 Adam Akkari
// Last update Sun May 14 23:46:08 2017 Adam Akkari
//

#ifndef RENDERER_CAMERA
# define RENDERER_CAMERA

# include <vector3d.h>
# include <ICameraSceneNode.h>
# include "Renderer.hh"

class	RendererCamera : public Renderer
{
private:
  irr::scene::ICameraSceneNode	*_camera;

public:
  RendererCamera(GameObject &obj, irr::core::vector3df const &lookat);
  void	lookAt(irr::core::vector3df &target);
  virtual void	update();
};

#endif //RENDERER_CAMERA
