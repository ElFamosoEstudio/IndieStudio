//
// Renderer3d.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/components
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Thu Jun 15 22:23:05 2017 Adam Akkari
// Last update Fri Jun 16 16:25:57 2017 Adam Akkari
//

#ifndef RENDERER3D_HPP
# define RENDERER3D_HPP

# include <vector>
# include <string>
# include "gfx.hpp"

namespace indie
{
  namespace component
  {
    struct Renderer3d
    {
      Renderer3d() = delete;
      Renderer3d(std::string const &file, std::string const &tex)
	: file(file)
      {
	textures.push_back(tex);
	mesh = gfx::sceneManager()->addAnimatedMeshSceneNode
	  (gfx::sceneManager()->getMesh(file.c_str()));
	// mesh->setMaterialFlag(irr::video::EMF_LIGHTNING, false);
	mesh->setMaterialTexture(0, gfx::videoDriver()->getTexture(tex.c_str()));
      }
      std::string				file;
      std::vector<std::string>			textures;
      irr::scene::IAnimatedMeshSceneNode	*mesh;
    };
  }
}

#endif // RENDERER3D_HPP
