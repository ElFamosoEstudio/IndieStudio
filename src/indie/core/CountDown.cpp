//
// CountDown.cpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 07:22:44 2017 akram abd-ali
// Last update Tue Jun 20 20:35:17 2017 akram abd-ali
//

#include <iostream>
#include "CountDown.hpp"

indie::CountDown::~CountDown() {}

indie::CountDown::CountDown(int ms)
  : _t0(Clock::now()), _init(ms), _rem(ms), _done(false)
{
}

indie::CountDown::CountDown(CountDown const&o)
  : _t0(o._t0), _init(o._init), _rem(o._rem), _done(o._done)
{
}

void	indie::CountDown::reset(int ms)
{
  _init = ms;
  _rem = ms;
  _t0 = Clock::now();
  _done = false;
}

int indie::CountDown::get() const
{
  if ((_rem == 0) && (_done == false))
    {
      _done = true;
      return (0);
    }
  else if (_done == true)
    return (-1);
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
