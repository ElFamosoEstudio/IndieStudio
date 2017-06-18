//
// PlayerId.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 19:31:23 2017 akram abd-ali
// Last update Sat Jun 17 22:09:58 2017 akram abd-ali
//

#ifndef PLAYER_ID_HPP
# define PLAYER_ID_HPP


namespace indie
{
  namespace component
  {
    struct PlayerId
    {
      uint8_t id;
      PlayerId(uint8_t playerId)
	: id(playerId) {}
    };
  }
}

#endif  // !PLAYER_ID_HPP
