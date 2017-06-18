//
// MeshRenderer.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
//
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
//
// Started on  Thu Jun 15 22:36:36 2017 Adam Akkari
// Last update Sun Jun 18 21:28:20 2017 Noam Silvy
//

#ifndef MESH_RENDERER_HPP
# define MESH_RENDERER_HPP

# include "ecs.hpp"
# include "ASystem.hpp"

namespace indie
{
  namespace system
  {
    class MeshRenderer : public ASystem
    {
    public:
      void	update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // MESH_RENDERER_HPP
