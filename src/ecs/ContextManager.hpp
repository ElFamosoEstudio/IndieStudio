//
// ContextManager.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Thu Jun  8 22:28:04 2017 akram abd-ali
// Last update Thu Jun  8 22:31:24 2017 akram abd-ali
//

#ifndef CONTEXT_MANAGER_HPP
# define CONTEXT_MANAGER_HPP

# include "ecs.hpp"

namespace	ecs
{
  class		ContextManager
  {
  private:
    
  public:
    ContextManager() = default;
    ~ContextManager() = default;
    ContextManager(ContextManager const&) = delete;
    ContextManager& operator=(ContextManager const&) = delete;
  public:
  };
}

#endif // !CONTEXT_MANAGER_HPP
