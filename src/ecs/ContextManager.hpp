//
// ContextManager.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Thu Jun  8 22:28:04 2017 akram abd-ali
// Last update Mon Jun 12 21:16:17 2017 akram abd-ali
//

#ifndef CONTEXT_MANAGER_HPP
# define CONTEXT_MANAGER_HPP

# include <memory>
# include <list>
# include <map>
# include "ecs.hpp"
# include "SystemFactory.hpp"

namespace	ecs
{
  class		ContextManager
  {
  public:
    using Context = std::map<SysType, bool>;

  private:
    std::list<Context*>	_contexts;
    SystemManager*	_sysmgr;
    SystemFactory*	_sysFactory;

  public:
    ContextManager() = delete;
    ContextManager(SystemManager* sysmgr, SystemFactory *sysFactory)
      : _sysmgr(sysmgr),
	_sysFactory(sysFactory) {}
    ~ContextManager() = default;
    ContextManager(ContextManager const&) = delete;
    ContextManager& operator=(ContextManager const&) = delete;

  public:
    void	push(Context *context, bool disableAll = false)
    {
      bool	toCreate;

      if (disableAll == true)
	_sysmgr->disableAll();
      for (auto const& it : *context)
	{
	  toCreate = true;
	  for (auto const& comp : _contexts)
	    {
	      auto const& f = comp->find(it.first);
	      if (f != comp->end())
		{
		  _sysmgr->setState(it.first, it.second);
		  toCreate = false;
		  break ;
		}

	    }
	  if (toCreate == true)
	    _sysmgr->push(_sysFactory->create(it.first), it.second);
	}
      _contexts.push_front(context);
    }

    void	pop()
    {
      auto	size = _contexts.size();

      std::cout << "DELETE" << std::endl;
      if (size == 0)
	{
	  std::cout << "return" << std::endl;
	  return ;
	}
      else if (size == 1)
	{
	  std::cout << "pop and reset" << std::endl;
	  _contexts.pop_front();
	  _sysmgr->reset();
	  return ;
	}
      auto const& states = _contexts.front();
      bool	toDelete;
      auto i = 0;

      for (auto const& it : *states)
	{
	  i = 0;
	  toDelete = true;
	  for (auto const& comp : _contexts)
	    {
	      if (i == 0)
		{
		  ++i;
		  continue ;
		}
	      auto const& f = comp->find(it.first);
	      if (f != comp->end())
		{
		  std::cout << "set to " << f->second << std::endl;
		  _sysmgr->setState(it.first, f->second);
		  toDelete = false;
		  break ;
		}

	    }
	  if (toDelete == true)
	    {
	      std::cout << "delete " << it.first << std::endl;
	      _sysmgr->remove(it.first);
	    }
	}
      _contexts.pop_front();
    }

    void	reset()
    {
      while (!_contexts.empty())
	pop();
    }
  };
}

#endif // !CONTEXT_MANAGER_HPP
