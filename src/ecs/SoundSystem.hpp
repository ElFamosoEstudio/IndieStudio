//
// SoundSystem.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Thu Jun  8 22:12:15 2017 akram abd-ali
// Last update Fri Jun  9 00:13:00 2017 akram abd-ali
//

#ifndef SOUND_SYSTEM_HPP
# define SOUND_SYSTEM_HPP

# include "ISystem.hpp"

namespace	ecs
{
  class	        SoundSystem : public ISystem
  {
  private:
    static const SysType TYPE = 1;
  public:
    static SysType type() { return TYPE; }
  public:
    SoundSystem() = default;
    ~SoundSystem() = default;
    SoundSystem(SoundSystem const&) = delete;
    SoundSystem& operator=(SoundSystem const&) = delete;
  public:
    void	update() {}
  };
}

#endif // !SOUND_SYSTEM_HPP
