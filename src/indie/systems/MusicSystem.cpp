//
// MusicSystem.cpp for  in /home/julien/C++/IndieStudio/src/indie
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 21:34:16 2017 julien
// Last update Sun Jun 18 22:11:41 2017 julien
//

#include <functional>
#include <memory>
#include "event.hpp"
#include "Music.hpp"
#include "engine.hpp"
#include "components.hpp"
#include "MusicSystem.hpp"

using namespace indie::component;

void	indie::system::MusicSystem::callback(indie::event::EEvent event, ecs::Entity id)
{
  _sound_list.push({event, id});
}

indie::system::MusicSystem::MusicSystem()
{
  auto			&sound_cmp = engine::entityManager().getAllComponents<Music>();

  for (auto const &it : sound_cmp)
    for (auto const &elem  : it.second->sounds)
      _sound[elem.first][it.first].openFromFile(elem.second);
  engine::eventManager().subscribe(indie::event::EEvent::MENU_MUSIC,
				   std::bind(&MusicSystem::callback, this,
					     indie::event::EEvent::MENU_MUSIC,
					     std::placeholders::_1));
  engine::eventManager().subscribe(indie::event::EEvent::GAME_MUSIC,
				   std::bind(&MusicSystem::callback, this,
					     indie::event::EEvent::GAME_MUSIC,
					     std::placeholders::_1));
}

void	indie::system::MusicSystem::update()
{
  ;
}
