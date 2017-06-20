//
// Animation.hpp for indie sutdio in /home/silvy_n/projects/IndieStudio/src/indie
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Sun Jun 18 18:32:29 2017 Noam Silvy
// Last update Tue Jun 20 19:33:55 2017 Noam Silvy
//

#ifndef ANIMATION_SYSTEM_HPP
# define ANIMATION_SYSTEM_HPP

# include <list>
# include <utility>
# include <queue>
# include "indie.hpp"
# include "ASystem.hpp"

namespace indie
{
  namespace system
  {
    class AnimationSystem : public ASystem
    {
    private:
      std::queue<std::pair<event::EEvent, ecs::Entity>> _tasks;
    public:
      AnimationSystem();
    public:
      void		update() override;
      ecs::SysType	type() const override;
      static ISystem	*create();
    };
  }
}

#endif //!ANIMATION_SYSTEM_HPP
