//
// SystemManager.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Thu Jun  8 22:31:02 2017 akram abd-ali
// Last update Fri Jun  9 00:19:14 2017 akram abd-ali
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
    template<typename T>
    void        createSystem(bool isActive = true)
    {
      if (isPresentSystem(T::type()) == true)
	return ;
      _systems[T::type()] = std::make_pair(std::make_unique<T>(), isActive);
    }
    void	setSystemState(SysType systemType, bool newState)
    {
      if (isPresentSystem(systemType) == false)
	return ;
      auto &elem = _systems[systemType].second;
      elem = newState;
    }
    bool	getSystemState(SysType systemType) const
    {
      auto const &it = _systems.find(systemType);
      if (it == _systems.end())
	return false;
      return (it->second.second);
    }
    void	removeSystem(SysType systemType)
    {
      auto const &it = _systems.find(systemType);
      if (it == _systems.end())
	return ;
      _systems.erase(it);
    }
  };
}

#endif // !SYSTEM_MANAGER_HPP
