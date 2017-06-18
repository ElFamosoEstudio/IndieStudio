//
// SoundSystem.cpp for  in /home/julien/C++/IndieStudio/src/indie/systems
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 04:03:57 2017 julien
// Last update Sun Jun 18 13:23:37 2017 julien
//

#include "engine.hpp"
#include "components.hpp"
#include "SoundSystem.hpp"

using namespace indie::component;

//map[id] -> map[even] -> buffer

//subscribe in constructor all sound even needed even -> ptr func

//subscribe move &callback

//callback template sur event



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
  for (auto & elem : _sound)
    engine::eventManager().subscribe(elem.first, &callback<elem>);
}

void	indie::system::SoundSystem::update()
{
  ;
}
