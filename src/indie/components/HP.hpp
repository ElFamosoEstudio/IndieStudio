//
// HP.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 20:35:30 2017 akram abd-ali
// Last update Sun Jun 18 18:23:15 2017 Adam Akkari
//

#ifndef HP_HPP
# define HP_HPP

namespace indie
{
  namespace component
  {
    struct HP
    {
      int       value;
      HP()
	: value(0) {}
      HP(int num)
	: value(num) {}
    };
  }
}

#endif  // !HP_HPP
