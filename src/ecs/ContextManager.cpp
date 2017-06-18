//
// ContextManager.cpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Thu Jun 15 02:57:29 2017 akram abd-ali
// Last update Sun Jun 18 16:26:45 2017 Noam Silvy
//

#include "ContextManager.hpp"

void	ecs::ContextManager::push(ContextType key, bool disableAll)
{
  auto it = _knownContexts.find(key);
  if (it == _knownContexts.end())
    throw (std::out_of_range("ContextManager: \"ContextType unknown\""));
  this->push(std::addressof(it->second), disableAll);
}

void	ecs::ContextManager::push(Context *context, bool disableAll)
{
  _todo.push({PUSH, {context, disableAll}});
}

void	ecs::ContextManager::_push(Context *context, bool disableAll)
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
	_sysmgr->push(_sysmgr->create(it.first), it.second);
    }
  _contexts.push_front(context);
}

void	ecs::ContextManager::pop()
{
  _todo.push({POP, {}});
}

void	ecs::ContextManager::_pop()
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

void	ecs::ContextManager::execute()
{
  while (!_todo.empty())
    {
      auto const& action = _todo.front();
      if (action.first == PUSH)
	this->_push(action.second.first, action.second.second);
      else if (action.first == POP)
        this->_pop();
      _todo.pop();
    }
}

void	ecs::ContextManager::reset()
{
  while (!_contexts.empty())
    pop();
}
void	ecs::ContextManager::registerContext(ContextType	key,
					     Context&&		context)
{
  _knownContexts[key] = std::forward<Context>(context);
}

void	ecs::ContextManager::registerContext(ContextType	key,
					     const Context&	context)
{
  _knownContexts[key] = context;
}
