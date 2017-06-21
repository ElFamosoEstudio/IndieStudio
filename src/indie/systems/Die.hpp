//
// Die.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Tue Jun 20 19:29:55 2017 akram abd-ali
// Last update Wed Jun 21 16:23:49 2017 akram abd-ali
//

#ifndef DIE_SYSTEM_HPP
# define DIE_SYSTEM_HPP

# include <unordered_map>
# include <array>
# include "indie.hpp"
# include "ASystem.hpp"

namespace indie
{
  namespace system
  {
    class Die : public ASystem
    {
    public:
      Die();
      ~Die() = default;
      Die(Die const&) = delete;
      Die& operator=(Die const&) = delete;
    public:
      void	        crateToBonus(ecs::Entity entity);
      void	        killPlayer(ecs::Entity entity);
      void		update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // !DIE_SYSTEM_HPP
