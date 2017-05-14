//
// Renderer3D.hh for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 23:15:38 2017 Adam Akkari
// Last update Mon May 15 00:00:43 2017 Adam Akkari
//

#ifndef RENDERER_3D
# define RENDERER_3D

# include <IAnimatedMeshSceneNode.h>
# include "Renderer.hh"

class	Renderer3D : public Renderer
{
private:
  irr::scene::IAnimatedMeshSceneNode	*_mesh;

public:
  Renderer3D(GameObject &obj, std::string const &model);
  void	setMaterial(std::string const &name);
  void	enableLighting(bool state);
  virtual void	update();
};

#endif //RENDERER_3D
