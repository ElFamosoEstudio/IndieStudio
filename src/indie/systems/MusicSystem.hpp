//
// MusicSystem.hpp for  in /home/julien/C++/IndieStudio/src/indie
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 21:29:48 2017 julien
// Last update Sun Jun 18 21:52:12 2017 julien
//

#ifndef MUSICSYSTEM_HPP
# define MUSICSYSTEM_HPP

# include <map>
# include <queue>
# include <utility>
# include "indie.hpp"
# include "SFML/Audio.hpp"
# include "MusicSystem.hpp"

namespace indie
{
  namespace system
  {
    class MusicSystem : public ecs::ISystem
    {
    private:
      std::queue<std::pair<indie::event::EEvent, ecs::Entity>> _sound_list;
      std::map<indie::event::EEvent, std::map<ecs::Entity, sf::Music>> _sound;
    public:
      MusicSystem();
      void		update();
      ecs::SysType	type() const
      {
	return (indie::system::ESystem::MUSIC_SYSTEM);
      }
      static ISystem	*create()
      {
	return new MusicSystem;
      }
      void		callback(indie::event::EEvent event,
				 ecs::Entity id);
    };
  }
}

#endif // MUSICSYSTEM_HPP
