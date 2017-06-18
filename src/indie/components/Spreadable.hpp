//
// Spreadable.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 04:29:26 2017 akram abd-ali
// Last update Sun Jun 18 06:34:15 2017 akram abd-ali
//

#ifndef SPREADABLE_HPP
# define SPREADABLE_HPP

# include <cstddef>

namespace indie
{
  namespace component
  {
    struct Spreadable
    {
      uint32_t	range;
      uint8_t	propagationMask;
      Spreadable(int bombRange, uint8_t propagation) : range(bombRange), propagationMask(propagation) {}
    };
  }
}

#endif // SPREADABLE_HPP
