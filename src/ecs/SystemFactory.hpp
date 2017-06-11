//
// SystemFactory.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 10 03:01:14 2017 akram abd-ali
// Last update Sat Jun 10 06:08:48 2017 akram abd-ali
//

#ifndef SYSTEM_FACTORY_HPP
# define SYSTEM_FACTORY_HPP

# include <map>
# include <functional>
# include "ISystem.hpp"
# include "SoundSystem.hpp"
# include "ecs.hpp"

namespace	ecs
{
  class		SystemFactory
  {
  private:
    std::map<SysType, std::function<ISystem*(void)>> _factoryMap;
  public:
    SystemFactory()
    {
      _factoryMap[2] = &SoundSystem::create;
    }
    SystemFactory(SystemFactory const&) = delete;
    SystemFactory& operator=(SystemFactory const&) = delete;
    ~SystemFactory() {}
  public:
    void registerSystem(SysType type, std::function<ISystem*(void)> func)
    {
      _factoryMap[type] = func;
    }
    ISystem *create(SysType type)
    {
      return _factoryMap[type]();
    }
  };
}

#endif // !SYSTEM_FACTORY_HPP
