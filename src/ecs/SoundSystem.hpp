//
// SoundSystem.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Thu Jun  8 22:12:15 2017 akram abd-ali
// Last update Sat Jun 10 06:08:20 2017 akram abd-ali
//

#ifndef SOUND_SYSTEM_HPP
# define SOUND_SYSTEM_HPP

# include <iostream>
# include "ISystem.hpp"

namespace	ecs
{
  class	        SoundSystem : public ISystem
  {
  private:
  public:
    SoundSystem() = default;
    ~SoundSystem() = default;
    SoundSystem(SoundSystem const&) = delete;
    SoundSystem& operator=(SoundSystem const&) = delete;
  public:
    void	update() {
      std::cout << "update sound" << std::endl;
    }
    SysType	type()
    {
      static const SysType TYPE = 2;
      return TYPE;
    }
    static ISystem	*create()
    {
      return new SoundSystem;
    }
  };
}

#endif // !SOUND_SYSTEM_HPP
