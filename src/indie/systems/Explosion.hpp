//
// Explosion.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sun Jun 18 05:53:14 2017 akram abd-ali
// Last update Sun Jun 18 06:16:45 2017 akram abd-ali
//

#ifndef EXPLOSION_SYSTEM_HPP
# define EXPLOSION_SYSTEM_HPP

# include <unordered_map>
# include <vector>
# include "components.hpp"
# include "indie.hpp"

namespace indie
{
  namespace system
  {
    class Explosion : public ecs::ISystem
    {
    private:
      std::unordered_map<ecs::EventTypeDefault, ecs::EventKey>	_subKeys;
    private:
      void	spreadExplosion(ecs::Entity entity);
      void      removeExplosion(ecs::Entity entity);
    public:
      Explosion();
      ~Explosion();
      Explosion(Explosion const&) = delete;
      Explosion& operator=(Explosion const&) = delete;
    public:
      void	update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // !EXPLOSION_SYSTEM_HPP
