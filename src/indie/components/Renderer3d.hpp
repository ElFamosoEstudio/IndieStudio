//
// Renderer3d.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/components
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Thu Jun 15 22:23:05 2017 Adam Akkari
// Last update Fri Jun 16 01:45:32 2017 Adam Akkari
//

#ifndef RENDERER3D_HPP
# define RENDERER3D_HPP

# include <vector>
# include <string>
# include <IAnimatedMeshSceneNode.h>

namespace indie
{
  namespace component
  {
    struct Renderer3d
    {
      Renderer3d() = delete;
      Renderer3d(std::string const &file)
      {
	//initialiser le mesh
      }
      std::string				file;
      std::vector<std::string>			textures;
      irr::scene::IAnimatedMeshSceneNode	*mesh;
    };
  }
}

#endif // RENDERER3D_HPP
