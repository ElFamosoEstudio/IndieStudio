//
// BombInfo.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 03:52:24 2017 akram abd-ali
// Last update Sat Jun 17 04:29:55 2017 akram abd-ali
//

#ifndef BOMB_INFO_HPP
# define BOMB_INFO_HPP

# include <cstddef>

namespace indie
{
  namespace component
  {
    struct BombInfo
    {
      int	count;
      int	range;
      int	power;
      uint8_t	propagationMask;
    };
  }
}

#endif // BOMB_INFO_HPP
