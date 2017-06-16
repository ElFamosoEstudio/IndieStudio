//
// SystemManager.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Thu Jun  8 22:31:02 2017 akram abd-ali
// Last update Fri Jun 16 21:34:28 2017 akram abd-ali
//

#ifndef SYSTEM_MANAGER_HPP
# define SYSTEM_MANAGER_HPP

# include <map>
# include <memory>
# include <utility>
# include <functional>
# include <stdexcept>
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
    bool	isPresentSystem(SysType systemType) const;
    void        push(ISystem *system, bool isActive = true);
    void	setState(SysType systemType, bool newState);
    bool	getState(SysType systemType) const;
    void	remove(SysType systemType);
    void	reset();
    void	disableAll();
    void	update() const;
    void	registerSystem(SysType type, std::function<ISystem*(void)> func);
    ISystem	*create(SysType type);
  };
}

#endif // !SYSTEM_MANAGER_HPP
