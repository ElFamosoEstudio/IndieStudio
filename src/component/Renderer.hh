//
// Renderer.hh for bomberman in /home/akkari_a/work/IndieStudio/src/component
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 23:16:00 2017 Adam Akkari
// Last update Mon May 15 00:06:43 2017 Adam Akkari
//

#ifndef RENDERER
# define RENDERER

# include "Component.hpp"

class	Renderer : public Component
{
public:
  Renderer(GameObject &obj);
  ~Renderer();
  virtual void	update() = 0;
};

#endif //RENDERER
