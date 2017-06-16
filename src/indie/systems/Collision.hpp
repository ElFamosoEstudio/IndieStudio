//
// Collision.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Fri Jun 16 17:24:21 2017 akram abd-ali
// Last update Fri Jun 16 21:33:43 2017 akram abd-ali
//

#ifndef COLLISION_SYSTEM_HPP
# define COLLISION_SYSTEM_HPP

# include "ecs.hpp"

namespace indie
{
  namespace system
  {
    class Collision : public ecs::ISystem
    {
    private:

    public:
      Collision() = default;
      ~Collision() = default;
      Collision(Collision const&) = delete;
      Collision& operator=(Collision const&) = delete;
    public:
      void	update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // !COLLISION_SYSTEM_HPP
