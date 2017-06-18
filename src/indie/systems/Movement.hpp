//
// Movement.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sun Jun 18 15:29:23 2017 akram abd-ali
// Last update Sun Jun 18 16:20:07 2017 akram abd-ali
//

#ifndef MOVEMENT_SYSTEM_HPP
# define MOVEMENT_SYSTEM_HPP

# include <unordered_map>
# include <vector>
# include "indie.hpp"

namespace indie
{
  namespace system
  {
    class Movement : public ecs::ISystem
    {
    private:
      std::unordered_map<ecs::EventTypeDefault, ecs::EventKey>	_subKeys;
    private:
      void	goUp(ecs::Entity);
      void	goDown(ecs::Entity);
      void	goLeft(ecs::Entity);
      void	goRight(ecs::Entity);
    public:
      Movement();
      ~Movement();
      Movement(Movement const&) = delete;
      Movement& operator=(Movement const&) = delete;
    public:
      void	update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // !MOVEMENT_SYSTEM_HPP
