//
// Bomb.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 02:27:36 2017 akram abd-ali
// Last update Sat Jun 17 09:52:58 2017 akram abd-ali
//

#ifndef BOMB_SYSTEM_HPP
# define BOMB_SYSTEM_HPP

# include <map>
# include <vector>
# include "indie.hpp"

namespace indie
{
  namespace system
  {
    class Bomb : public ecs::ISystem
    {
    private:
      std::map<ecs::EventTypeDefault, ecs::EventKey>	_subKeys;
    private:
      void	dropBomb(ecs::Entity entity);
      void	dropBombErr(ecs::Entity entity);
    public:
      Bomb();
      ~Bomb();
      Bomb(Bomb const&) = delete;
      Bomb& operator=(Bomb const&) = delete;
    public:
      void	update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // !BOMB_SYSTEM_HPP
