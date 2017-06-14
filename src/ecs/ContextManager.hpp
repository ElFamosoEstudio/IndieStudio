//
// ContextManager.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Thu Jun  8 22:28:04 2017 akram abd-ali
// Last update Wed Jun 14 15:46:26 2017 Noam Silvy
//

#ifndef CONTEXT_MANAGER_HPP
# define CONTEXT_MANAGER_HPP

# include <memory>
# include <list>
# include <map>
# include <stdexcept>
# include "ecs.hpp"
# include "SystemFactory.hpp"

namespace	ecs
{
  using Context = std::map<SysType, bool>;

  class		ContextManager
  {
  private:
    std::list<Context*>			_contexts;
    std::map<ContextType, Context>	_knownContexts;
    SystemManager*			_sysmgr;
    SystemFactory*			_sysFactory;

  public:
    ContextManager() = delete;
    ContextManager(SystemManager* sysmgr, SystemFactory *sysFactory)
      : _sysmgr(sysmgr),
	_sysFactory(sysFactory) {}
    ~ContextManager() = default;
    ContextManager(ContextManager const&) = delete;
    ContextManager& operator=(ContextManager const&) = delete;

  public:
    void	push(ContextType key, bool disableAll = false)
    {
      auto it = _knownContexts.find(key);
      if (it == _knownContexts.end())
      	throw (std::out_of_range("ContextManager: \"ContextType unknown\""));
      this->push(std::addressof(it->second), disableAll);
    }

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

      if (size == 0)
	return ;
      else if (size == 1)
	{
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
		  _sysmgr->setState(it.first, f->second);
		  toDelete = false;
		  break ;
		}

	    }
	  if (toDelete == true)
	    _sysmgr->remove(it.first);
	}
      _contexts.pop_front();
    }

    void	reset()
    {
      while (!_contexts.empty())
	pop();
    }

    void	registerContext(ContextType	key,
				Context&&	context)
    {
      std::cerr << "registerContext move ref" << std::endl;
      _knownContexts[key] = std::forward<Context>(context);
    }

    void	registerContext(ContextType	key,
			        const Context& context)
    {
      std::cerr << "registerContext ref" << std::endl;
      _knownContexts[key] = context;
    }
  };
}

#endif // !CONTEXT_MANAGER_HPP
