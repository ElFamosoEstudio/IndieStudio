//
// Renderer3d.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/components
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Thu Jun 15 22:23:05 2017 Adam Akkari
// Last update Thu Jun 15 22:30:02 2017 Adam Akkari
//

#ifndef RENDERER3D_HPP
# define RENDERER3D_HPP

# include <string>
# include <IAnimatedMeshSceneNode.h>

namespace indie
{
  namespace component
  {
    struct Renderer3D
    {
      std::string	&file;
      irr::scene::IAnimatedMeshSceneNode	*mesh;
    };
  }
}

#endif // RENDERER3D_HPP
