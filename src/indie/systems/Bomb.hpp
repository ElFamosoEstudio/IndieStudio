//
// Bomb.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 02:27:36 2017 akram abd-ali
// Last update Sun Jun 18 05:33:47 2017 akram abd-ali
//

#ifndef BOMB_SYSTEM_HPP
# define BOMB_SYSTEM_HPP

# include <unordered_map>
# include <vector>
#include "components.hpp"
# include "indie.hpp"

namespace indie
{
  namespace system
  {
    class Bomb : public ecs::ISystem
    {
    private:
      std::unordered_map<ecs::EventTypeDefault, ecs::EventKey>	_subKeys;
    private:
      void	dropBomb(ecs::Entity entity);
      void      removeBomb(ecs::Entity entity);
      void      explode(ecs::Entity entity);
    public:
      static void set3DPropagationPos(component::Transform& trans, uint8_t spread);
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
