//
// Interval.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 04:44:11 2017 akram abd-ali
// Last update Sat Jun 17 10:25:20 2017 akram abd-ali
//

#ifndef INTERVAL_HPP
# define INTERVAL_HPP

# include "CountDown.hpp"
# include "ecs.hpp"

namespace indie
{
  namespace component
  {
    struct Interval
    {
      uint32_t		resetTime;
      CountDown		countDown;
      ecs::EventKey	eventType;
      Interval(uint32_t reset, ecs::EventTypeDefault type)
	: resetTime(reset),
	  countDown(reset),
	  eventType(type)
      {}
    };
  }
}

#endif // INTERVAL_HPP
