//
// engine.cpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 17:48:23 2017 Noam Silvy
// Last update Fri Jun 16 04:07:50 2017 Noam Silvy
//

#include "system.hpp"
#include "context.hpp"
#include "entity.hpp"
#include "gfx.hpp"
#include "engine.hpp"

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
  static indie::InputReceiver _inputReceiver(indie::gfx::device());
  return (_inputReceiver);
}

indie::engine::IndieEntityManager&	indie::engine::entityManager()
{
  static indie::engine::IndieEntityManager _entityManager;
  return (_entityManager);
}
