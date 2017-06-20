//
// SysTime.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sun Jun 18 16:53:52 2017 akram abd-ali
// Last update Sun Jun 18 22:16:40 2017 akram abd-ali
//

#ifndef TIME_SYSTEM_HPP
# define TIME_SYSTEM_HPP

# include "indie.hpp"
# include "ASystem.hpp"

namespace indie
{
  namespace system
  {
    class SysTime : ASystem
    {
    public:
      SysTime() = default;
      ~SysTime() = default;
      SysTime(SysTime const&) = delete;
      SysTime& operator=(SysTime const&) = delete;
    public:
      void	update();
      ecs::SysType	type() const;
      static ISystem	*create();
    };
  }
}

#endif // !TIME_SYSTEM_HPP
