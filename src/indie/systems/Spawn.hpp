//
// Spawn.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sun Jun 18 20:21:52 2017 akram abd-ali
// Last update Sun Jun 18 22:03:07 2017 akram abd-ali
//

#ifndef SPAWN_SYSTEM_HPP
# define SPAWN_SYSTEM_HPP

# include <unordered_map>
# include <array>
# include "indie.hpp"
# include "ASystem.hpp"

namespace indie
{
  namespace system
  {
    class Spawn : public ASystem
    {
    public:
      Spawn();
      ~Spawn() = default;
      Spawn(Spawn const&) = delete;
      Spawn& operator=(Spawn const&) = delete;
    public:
      void		respawn(ecs::Entity entity);
      void		update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // !SPAWN_SYSTEM_HPP
