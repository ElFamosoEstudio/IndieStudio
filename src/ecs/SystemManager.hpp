//
// SystemManager.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Thu Jun  8 22:31:02 2017 akram abd-ali
// Last update Thu Jun 15 01:48:22 2017 Noam Silvy
//

#ifndef SYSTEM_MANAGER_HPP
# define SYSTEM_MANAGER_HPP

# include <map>
# include <memory>
# include <utility>
# include <functional>
# include "ISystem.hpp"

namespace	ecs
{
  class		SystemManager
  {
    using SysPair = std::pair<std::unique_ptr<ISystem>, bool>;
  private:
    std::map<SysType, SysPair>				_systems;
    std::map<SysType, std::function<ISystem*(void)>>	_factories;
  public:
    SystemManager() = default;
    ~SystemManager() = default;
    SystemManager(SystemManager const&) = delete;
    SystemManager& operator=(SystemManager const&) = delete;
  public:
    bool	isPresentSystem(SysType systemType) const
    {
      auto const& it = _systems.find(systemType);
      return ((it != _systems.end()) ? true : false);
    }
    void        push(ISystem *system, bool isActive = true)
    {
      if (isPresentSystem(system->type()) == true)
	return ;
      _systems[system->type()] = std::make_pair(std::unique_ptr<ISystem>(system), isActive);
    }
    void	setState(SysType systemType, bool newState)
    {
      if (isPresentSystem(systemType) == false)
	return ;
      auto &elem = _systems[systemType].second;
      elem = newState;
    }
    bool	getState(SysType systemType) const
    {
      auto const &it = _systems.find(systemType);
      if (it == _systems.end())
	return false;
      return (it->second.second);
    }
    void	remove(SysType systemType)
    {
      auto const &it = _systems.find(systemType);
      if (it == _systems.end())
	return ;
      _systems.erase(it);
    }
    void	reset()
    {
      _systems.clear();
    }
    void	disableAll()
    {
      for (auto& it : _systems)
	{
	  it.second.second = false;
	}
    }
    void	update() const
    {
      for (auto const& it : _systems)
	{
	  if (it.second.second == true)
	    it.second.first->update();
	}
    }

    void registerSystem(SysType type, std::function<ISystem*(void)> func)
    {
      _factories[type] = func;
    }

    ISystem *create(SysType type)
    {
      return _factories[type]();
    }
  };
}

#endif // !SYSTEM_MANAGER_HPP
