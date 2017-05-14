//
// Renderer3D.hh for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sat May 13 23:15:38 2017 Adam Akkari
// Last update Sun May 14 22:15:42 2017 Adam Akkari
//

#ifndef RENDERER_3D
# define RENDERER_3D

# include <IAnimatedMeshSceneNode.h>
# include "Component.hpp"

class	Renderer3D : public Component
{
private:
  irr::scene::IAnimatedMeshSceneNode	*_mesh;

public:
  Renderer3D(GameObject &obj, std::string const &model);
  void	setMaterial(std::string const &name);
  void	update();
};

#endif //RENDERER_3D
