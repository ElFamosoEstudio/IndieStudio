//
// BonusSystem.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue Jun 20 20:50:14 2017 Adam Akkari
// Last update Wed Jun 21 04:37:51 2017 akram abd-ali
//

#ifndef BONUSSYSTEM_HPP
# define BONUSSYSTEM_HPP

# include "ecs.hpp"
# include "ASystem.hpp"

namespace indie
{
  namespace system
  {
    class BonusSystem : public ASystem
    {
    private:
      void	addBonus(ecs::Entity);
      void	createBonus(ecs::Entity);
    public:
      BonusSystem();
      ~BonusSystem() = default;
      void	update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif
