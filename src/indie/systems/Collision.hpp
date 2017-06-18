//
// Collision.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Fri Jun 16 17:24:21 2017 akram abd-ali
// Last update Sun Jun 18 15:07:46 2017 akram abd-ali
//

#ifndef COLLISION_SYSTEM_HPP
# define COLLISION_SYSTEM_HPP

# include <unordered_map>
# include "ecs.hpp"

namespace indie
{
  namespace system
  {
    class Collision : public ecs::ISystem
    {
    private:
      std::unordered_map<ecs::EventTypeDefault, ecs::EventKey>	_subKeys;
    public:
      Collision();
      ~Collision();
      Collision(Collision const&) = delete;
      Collision& operator=(Collision const&) = delete;
    public:
      void		removeSkel(ecs::Entity entity);
      void	        addBombsToAnimator(ecs::Entity entity);
      void		update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // !COLLISION_SYSTEM_HPP
