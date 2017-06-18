//
// Movement.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 20:39:28 2017 akram abd-ali
// Last update Sat Jun 17 21:13:27 2017 akram abd-ali
//

#ifndef MOVEMENT_HPP
# define MOVEMENT_HPP


namespace indie
{
  namespace component
  {
    struct Movement
    {
      int       value;
      Movement()
	: value(0) {}
      Movement(int num)
	: value(num) {}
    };
  }
}

#endif  // !MOVEMENT_HPP
