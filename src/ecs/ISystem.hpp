//
// ISystem.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Thu Jun  8 21:57:34 2017 akram abd-ali
// Last update Tue Jun 13 18:14:59 2017 Noam Silvy
//

#ifndef ISYSTEM_HPP
# define ISYSTEM_HPP

# include "ecs.hpp"

namespace	ecs
{
  class		ISystem
  {
  public:
    virtual ~ISystem() {}
  public:
    virtual void	update() = 0;
    virtual SysType     type() const = 0;
  };
}

#endif // !ISYSTEM_HPP
