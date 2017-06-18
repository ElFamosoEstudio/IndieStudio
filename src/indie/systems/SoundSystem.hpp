//
// SoundSystem.hpp for  in /home/julien/C++/IndieStudio/src/indie/systems
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 02:31:46 2017 julien
// Last update Sun Jun 18 13:19:15 2017 julien
//

#ifndef SOUNDSYSTEM_HPP
# define SOUNDSYSTEM_HPP

# include <map>
# include <queue>
# include "indie.hpp"
# include "SFML/Audio.hpp"
# include "SoundSystem.hpp"

namespace indie
{
  namespace system
  {
    class SoundSystem : public ecs::ISystem
    {
    private:
      std::map<indie::event::EEvent, std::map<ecs::Entity, sf::SoundBuffer>> _sound;

    public:
      SoundSystem();
      void		update();
      ecs::SysType	type() const
      {
	return (indie::system::ESystem::SOUND_SYSTEM);
      }
      static ISystem	*create()
      {
	return new SoundSystem;
      }
      template<typename Event>
      void		callback(indie::event::EEvent, Event func);
    };
  }
}

#endif // SOUNDSYSTEM_HPP
