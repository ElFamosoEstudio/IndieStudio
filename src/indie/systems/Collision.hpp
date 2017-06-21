//
// Collision.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Fri Jun 16 17:24:21 2017 akram abd-ali
// Last update Wed Jun 21 00:10:34 2017 akram abd-ali
//

#ifndef COLLISION_SYSTEM_HPP
# define COLLISION_SYSTEM_HPP

# include <unordered_map>
# include "indie.hpp"
# include "ASystem.hpp"

namespace indie
{
  namespace system
  {
    class Collision : public ASystem
    {
    public:
      Collision();
      ~Collision();
      Collision(Collision const&) = delete;
      Collision& operator=(Collision const&) = delete;
    public:
      void		removeSkel(ecs::Entity entity);
      void	        addElemToAnimators(ecs::Entity entity);
      void	        addObsToAnimator(ecs::Entity entity);
      void		update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // !COLLISION_SYSTEM_HPP
