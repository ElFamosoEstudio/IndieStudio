//
// engine.cpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 17:48:23 2017 Noam Silvy
// Last update Fri Jun 16 02:17:02 2017 Adam Akkari
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

irr::video::IVideoDriver	*indie::engine::videoDriver()
{
  static irr::video::IVideoDriver	*video = _device->getVideoDriver();
  return (video);
}

irr::scene::ISceneManager	*indie::engine::sceneManager()
{
  static irr::scene::ISceneManager	*scene = _device->getSceneManager();
  return (scene);
}
