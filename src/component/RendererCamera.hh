//
// RendererCamera.hh for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 22:15:00 2017 Adam Akkari
// Last update Wed Jun  7 10:14:05 2017 Adam Akkari
//

#ifndef RENDERER_CAMERA
# define RENDERER_CAMERA

# include <ICameraSceneNode.h>
# include <vector3d.h>
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
