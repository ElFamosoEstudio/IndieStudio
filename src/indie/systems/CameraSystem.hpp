//
// CameraSystem.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Fri Jun 16 20:04:00 2017 Adam Akkari
// Last update Fri Jun 16 20:06:14 2017 Adam Akkari
//

#ifndef CAMERA_SYSTEM_HPP
# define CAMERA_SYSTEM_HPP

namespace indie
{
  namespace system
  {
    class CameraSystem : public ecs::ISystem
    {
    public:
      void	update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // CAMERA_SYSTEM_HPP
