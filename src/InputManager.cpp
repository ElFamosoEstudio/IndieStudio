//
// InputManager.cpp for bomberman in /home/akkari_a/work/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Mon May 15 01:09:03 2017 Adam Akkari
// Last update Mon May 15 01:18:10 2017 Adam Akkari
//

#include "InputManager.hh"

std::map<std::string, irr::EKEY_CODE>	InputManager::keymap =
  {
    {"up", irr::KEY_UP},
    {"down", irr::KEY_DOWN},
    {"left", irr::KEY_LEFT},
    {"right", irr::KEY_RIGHT},
    {"bomb", irr::KEY_SPACE},
    {"kick", irr::KEY_CONTROL},
    {"back", irr::KEY_ESCAPE},
    {"select", irr::KEY_RETURN}
  };

bool	InputManager::isKeyDown(std::string const &key)
{
  //insérer du code
  (void)key;
  return (false);
}
