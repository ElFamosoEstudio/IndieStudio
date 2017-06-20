//
// Timer.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 04:42:26 2017 akram abd-ali
// Last update Sun Jun 18 22:30:21 2017 akram abd-ali
//

#ifndef THE_TIMER_HPP
# define THE_TIMER_HPP

# include "CountDown.hpp"

namespace indie
{
  namespace component
  {
    struct Timer
    {
      CountDown		countDown;
      ecs::EventKey	eventType;
      Timer(uint32_t msTime, ecs::EventTypeDefault type)
	: countDown(msTime),
	  eventType(type)
      {}
    };
  }
}

#endif // !THE_TIMER_HPP
