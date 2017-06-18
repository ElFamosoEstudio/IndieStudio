//
// Speed.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 20:36:50 2017 akram abd-ali
// Last update Sat Jun 17 21:13:04 2017 akram abd-ali
//

#ifndef SPEED_HPP
# define SPEED_HPP


namespace indie
{
  namespace component
  {
    struct Speed
    {
      float     value;
      Speed()
	: value(0.f) {}
      Speed(float speed)
	: value(speed) {}
    };
  }
}

#endif  // !SPEED_HPP
