//
// SystemManager.cpp for indie studio in /home/silvy_n/projects/IndieStudio/src/ecs
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 00:57:23 2017 Noam Silvy
// Last update Fri Jun 16 01:46:53 2017 Noam Silvy
//

#include "SystemManager.hpp"

using namespace ecs;

bool	SystemManager::isPresentSystem(SysType systemType) const
{
  auto const& it = _systems.find(systemType);
  return ((it != _systems.end()) ? true : false);
}
void	SystemManager::push(ISystem *system, bool isActive)
{
  if (isPresentSystem(system->type()) == true)
    return ;
  _systems[system->type()] = std::make_pair(std::unique_ptr<ISystem>(system), isActive);
}
void	SystemManager::setState(SysType systemType, bool newState)
{
  if (isPresentSystem(systemType) == false)
    return ;
  auto &elem = _systems[systemType].second;
  elem = newState;
}
bool	SystemManager::getState(SysType systemType) const
{
  auto const &it = _systems.find(systemType);
  if (it == _systems.end())
    return false;
  return (it->second.second);
}
void	SystemManager::remove(SysType systemType)
{
  auto const &it = _systems.find(systemType);
  if (it == _systems.end())
    return ;
  _systems.erase(it);
}
void	SystemManager::reset()
{
  _systems.clear();
}
void	SystemManager::disableAll()
{
  for (auto& it : _systems)
    {
      it.second.second = false;
    }
}
void	SystemManager::update() const
{
  for (auto const& it : _systems)
    {
      if (it.second.second == true)
	it.second.first->update();
    }
}

void	SystemManager::registerSystem(SysType type, std::function<ISystem*(void)> func)
{
  _factories[type] = func;
}

ISystem*	SystemManager::create(SysType type)
{
  auto it = _factories.find(type);
  if (it == _factories.end())
    throw (std::out_of_range("SystemManager: \"Unkown factory type\""));
  return _factories[type]();
}
