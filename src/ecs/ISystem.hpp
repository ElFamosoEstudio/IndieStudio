//
// ISystem.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Thu Jun  8 21:57:34 2017 akram abd-ali
// Last update Fri Jun 16 01:59:45 2017 Noam Silvy
//

#ifndef ISYSTEM_HPP
# define ISYSTEM_HPP

namespace ecs
{
  using SysType = uint32_t;

  class ISystem
  {
  public:
    virtual		~ISystem() {}
  public:
    virtual void	update() = 0;
    virtual SysType     type() const = 0;
  };
}

#endif // !ISYSTEM_HPP
