//
// engine.cpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 17:48:23 2017 Noam Silvy
// Last update Thu Jun 15 18:29:09 2017 Noam Silvy
//

#include <cassert>
#include "engine.hpp"

void	indie::engine::provideDevice(irr::IrrlichtDevice *device)
{
  _device = device;
}

ecs::SystemManager&	indie::engine::systemManager()
{
  static ecs::SystemManager _systemManager;
  return (_systemManager);
}

ecs::ContextManager&	indie::engine::contextManager()
{
  static ecs::ContextManager _contextManager(std::addressof(systemManager()));
  return (_contextManager);
}

ecs::EventManager<>&	indie::engine::eventManager()
{
  static ecs::EventManager<> _eventManager;
  return (_eventManager);
}

indie::InputReceiver&	indie::engine::inputReceiver()
{
  assert(_device);
  static indie::InputReceiver _inputReceiver(_device);
  return (_inputReceiver);
}

indie::engine::IndieEntityManager&	indie::engine::entityManager()
{
  static indie::engine::IndieEntityManager _entityManager;
  return (_entityManager);
}
