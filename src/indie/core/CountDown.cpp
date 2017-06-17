//
// CountDown.cpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 07:22:44 2017 akram abd-ali
// Last update Sat Jun 17 22:26:31 2017 akram abd-ali
//

#include <iostream>
#include "CountDown.hpp"

indie::CountDown::~CountDown() {}

indie::CountDown::CountDown(uint32_t ms) : _t0(Clock::now()), _init(ms), _rem(ms)
{
}

indie::CountDown::CountDown(CountDown const&o) : _t0(o._t0), _init(o._init), _rem(o._rem)
{
}

void	indie::CountDown::reset(uint32_t ms)
{
  _init = ms;
  _rem = ms;
  _t0 = Clock::now();
}

uint32_t indie::CountDown::get() const
{
  return (_rem);
}

void indie::CountDown::update()
{
  Clock::time_point	t1 = Clock::now();
  uint32_t inter = std::chrono::duration_cast<milliseconds>(t1 - _t0).count();
  if (inter >= _init)
    _rem = 0;
  else
    _rem = _init - inter;
}
