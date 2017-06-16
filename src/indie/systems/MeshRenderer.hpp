//
// MeshRenderer.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Thu Jun 15 22:36:36 2017 Adam Akkari
// Last update Fri Jun 16 16:33:40 2017 Adam Akkari
//

#ifndef MESH_RENDERER_HPP
# define MESH_RENDERER_HPP

# include "ecs.hpp"

namespace indie
{
  namespace system
  {
    class MeshRenderer : public ecs::ISystem
    {
    public:
      void	update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // MESH_RENDERER_HPP
