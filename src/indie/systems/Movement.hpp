//
// Movement.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Sun Jun 18 15:29:23 2017 akram abd-ali
// Last update Sun Jun 18 21:47:15 2017 Noam Silvy
//

#ifndef MOVEMENT_SYSTEM_HPP
# define MOVEMENT_SYSTEM_HPP

# include <unordered_map>
# include <array>
# include "indie.hpp"
# include "ASystem.hpp"

namespace indie
{
  namespace system
  {
    class Movement : public ASystem
    {
      enum	Dir
	{
	  UP = 0,
	  DOWN,
	  LEFT,
	  RIGHT
	};
    private:
      std::unordered_map<ecs::EventTypeDefault, ecs::EventKey>	_subKeys;
      std::unordered_map<ecs::Entity, std::array<bool, 4>>	_movements;

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
      static void setDirs(std::unordered_map<ecs::Entity,
			  std::array<bool, 4>>& move, char dir);
      void	update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // !MOVEMENT_SYSTEM_HPP
