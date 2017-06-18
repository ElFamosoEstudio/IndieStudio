//
// SysTime.cpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sun Jun 18 16:53:45 2017 akram abd-ali
// Last update Sun Jun 18 23:12:06 2017 akram abd-ali
//

#include "SysTime.hpp"

void	indie::system::SysTime::update()
{
  auto& timers = engine::entityManager().getAllComponents<component::Timer>();

  for (auto& it : timers)
    {
      auto id = it.first;
      auto& timer = it.second;
      timer->countDown.update();
      if (timer->countDown.get() == 0)
	{
	  engine::eventManager().emit(timer->eventType, id);
	  engine::entityManager().removeComponent<component::Timer>(id);
	}
    }

  auto& intervals = engine::entityManager().getAllComponents<component::Interval>();

  for (auto& it : intervals)
    {
      auto id = it.first;
      auto& interval = it.second;
      interval->countDown.update();
      if (interval->countDown.get() == 0)
	{
	  engine::eventManager().emit(interval->eventType, id);
	  interval->countDown.reset(interval->resetTime);
	}
    }
}

ecs::SysType	indie::system::SysTime::type() const
{
  return (system::SYSTIME);
}

ecs::ISystem	*indie::system::SysTime::create()
{
  return new SysTime;
}
