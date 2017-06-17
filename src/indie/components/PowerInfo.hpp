//
// PowerInfo.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 20:18:16 2017 akram abd-ali
// Last update Sat Jun 17 20:19:10 2017 akram abd-ali
//

#ifndef POWER_INFO_HPP
# define POWER_INFO_HPP

# include <cstddef>

namespace indie
{
  namespace component
  {
    struct PowerInfo
    {
      int	power;
      PowerInfo(int pow)
	: power(pow) {}
    };
  }
}

#endif // POWER_INFO_HPP
