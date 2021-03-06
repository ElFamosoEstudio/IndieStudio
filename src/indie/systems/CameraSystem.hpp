//
// CameraSystem.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
//
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
//
// Started on  Fri Jun 16 20:04:00 2017 Adam Akkari
// Last update Sat Jun 17 21:19:57 2017 Noam Silvy
//

#ifndef CAMERA_SYSTEM_HPP
# define CAMERA_SYSTEM_HPP

# include "ecs.hpp"

namespace indie
{
  namespace system
  {
    class CameraSystem : public ecs::ISystem
    {
    public:
      void		update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // CAMERA_SYSTEM_HPP
