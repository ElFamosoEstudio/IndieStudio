//
// MeshRenderer.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Thu Jun 15 22:36:36 2017 Adam Akkari
// Last update Thu Jun 15 23:21:03 2017 Adam Akkari
//

#ifndef MESH_RENDERER_HPP
# define MESH_RENDERER_HPP

namespace indie
{
  namespace system
  {
    class MeshRenderer : public ecs::ISystem
    {
    public:
      void	update()
      {
	auto	&transform_cmp;
	auto	&renderer_cmp;

	transform_cmp = engine::entityManager().getAllComponents<Transform>();
	renderer_cmp = engine::entityManager().getAllComponents<Renderer3d>();
	for (auto const &idx:renderer_cmp)
	  {
	    
	  }
      }
      ecs::SysType	type() const;
      static ISystem	*create()
      {
	return new MeshRenderer;
      }
    };
  }
}

#endif // MESH_RENDERER_HPP
