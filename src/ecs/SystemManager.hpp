//
// SystemManager.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Thu Jun  8 22:31:02 2017 akram abd-ali
// Last update Sat Jun 10 05:46:27 2017 akram abd-ali
//

#ifndef SYSTEM_MANAGER_HPP
# define SYSTEM_MANAGER_HPP

# include <map>
# include <memory>
# include <utility>
# include "ISystem.hpp"
# include "SoundSystem.hpp"

namespace	ecs
{
  class		SystemManager
  {
    using SysPair = std::pair<std::unique_ptr<ISystem>, bool>;
  private:
    
    std::map<SysType, SysPair> _systems;
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
    void	update() const
    {
      for (auto const& it : _systems)
	{
	  if (it.second.second == true)
	    it.second.first->update();
	}
    }
  };
}

#endif // !SYSTEM_MANAGER_HPP