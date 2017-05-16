//
// InputManager.cpp for bomberman in /home/akkari_a/work/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Mon May 15 01:09:03 2017 Adam Akkari
// Last update Tue May 16 16:24:58 2017 Adam Akkari
//

#include "InputManager.hh"

InputManager::EventReceiver		*InputManager::_receiver = nullptr;

std::map<std::string, irr::EKEY_CODE>	InputManager::_keymap =
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

InputManager::EventReceiver::EventReceiver()
{
  for (irr::u64 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
    _keyIsDown[i] = false;
}

bool	InputManager::EventReceiver::OnEvent(const irr::SEvent &event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    _keyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
  return (false);
}

bool	InputManager::EventReceiver::isKeyDown(irr::EKEY_CODE keyCode) const
{
  return (_keyIsDown[keyCode]);
}

void	InputManager::initialize()
{
  _receiver = new InputManager::EventReceiver;
}

InputManager::EventReceiver	*InputManager::getReceiver()
{
  return (_receiver);
}

bool	InputManager::isKeyDown(std::string const &key)
{
  if (_receiver)
    return (_receiver->isKeyDown(_keymap.at(key)));
  else
    return (false);
}
