//
// SoundSystem.cpp for  in /home/julien/C++/IndieStudio/src/indie/systems
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 04:03:57 2017 julien
// Last update Sun Jun 18 21:52:59 2017 julien
//

#include <functional>
#include "event.hpp"
#include "Sound.hpp"
#include "engine.hpp"
#include "components.hpp"
#include "SoundSystem.hpp"

using namespace indie::component;

void	indie::system::SoundSystem::callback(indie::event::EEvent event, ecs::Entity id)
{
  _sound_list.push({event, id});
}

indie::system::SoundSystem::SoundSystem()
{
  sf::SoundBuffer	tmpsound;
  auto			&sound_cmp = engine::entityManager().getAllComponents<Sound>();

  for (auto const &it : sound_cmp)
    for (auto const &elem  : it.second->sounds)
      {
	tmpsound.loadFromFile(elem.second);
	_sound[elem.first][it.first] = tmpsound;
      }
  engine::eventManager().subscribe(indie::event::EEvent::PLAYER_MOVED,
				   std::bind(&SoundSystem::callback, this,
					     indie::event::EEvent::PLAYER_MOVED,
					     std::placeholders::_1));
  engine::eventManager().subscribe(indie::event::EEvent::BOMB_EXPLODED,
				   std::bind(&SoundSystem::callback, this,
					     indie::event::EEvent::BOMB_EXPLODED,
					     std::placeholders::_1));
  engine::eventManager().subscribe(indie::event::EEvent::BOMB_EXPLODED,
				   std::bind(&SoundSystem::callback, this,
					     indie::event::EEvent::COLLIDED,
					     std::placeholders::_1));
  engine::eventManager().subscribe(indie::event::EEvent::COLLIDED,
				   std::bind(&SoundSystem::callback, this,
					     indie::event::EEvent::PLAYER_MOVED,
					     std::placeholders::_1));
  engine::eventManager().subscribe(indie::event::EEvent::BOMB_DROPPED,
				   std::bind(&SoundSystem::callback, this,
					     indie::event::EEvent::BOMB_DROPPED,
					     std::placeholders::_1));
}

void	indie::system::SoundSystem::update()
{
  ;
}
