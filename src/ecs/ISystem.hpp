//
// ISystem.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Thu Jun  8 21:57:34 2017 akram abd-ali
// Last update Thu Jun  8 23:31:28 2017 akram abd-ali
//

#ifndef ISYSTEM_HPP
# define ISYSTEM_HPP

namespace	ecs
{
  class		ISystem
  {
  public:
    virtual ~ISystem() {}
  public:
    virtual void	update() = 0;
  };
}

#endif // !ISYSTEM_HPP
