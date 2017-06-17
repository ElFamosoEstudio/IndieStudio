//
// Damage.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 21:14:24 2017 akram abd-ali
// Last update Sat Jun 17 21:15:27 2017 akram abd-ali
//

#ifndef DAMAGE_HPP
# define DAMAGE_HPP


namespace indie
{
  namespace component
  {
    struct Damage
    {
      int     value;
      Damage()
	: value(0.f) {}
      Damage(int damage)
	: value(damage) {}
    };
  }
}

#endif  // !DAMAGE_HPP
