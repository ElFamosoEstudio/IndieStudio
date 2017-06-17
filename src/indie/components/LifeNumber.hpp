//
// LifeNumber.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 20:32:13 2017 akram abd-ali
// Last update Sat Jun 17 20:54:44 2017 akram abd-ali
//

#ifndef LIFE_NUMBER_HPP
# define LIFE_NUMBER_HPP


namespace indie
{
  namespace component
  {
    struct LifeNumber
    {
      int       value;
      LifeNumber()
	: value(0) {}
      LifeNumber(int num)
	: value(num) {}
    };
  }
}

#endif  // !LIFE_NUMBER_HPP
