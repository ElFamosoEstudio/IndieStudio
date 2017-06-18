//
// Movement.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 20:39:28 2017 akram abd-ali
// Last update Sun Jun 18 13:00:54 2017 Adam Akkari
//

#ifndef MOVEMENT_HPP
# define MOVEMENT_HPP


namespace indie
{
  namespace component
  {
    struct Movement
    {
      float	value;
      Movement()
	: value(0) {}
      Movement(float num)
	: value(num) {}
    };
  }
}

#endif  // !MOVEMENT_HPP
