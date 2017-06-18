//
// ContextManager.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Thu Jun  8 22:28:04 2017 akram abd-ali
// Last update Sun Jun 18 16:02:58 2017 Noam Silvy
//

#ifndef CONTEXT_MANAGER_HPP
# define CONTEXT_MANAGER_HPP

# include <memory>
# include <list>
# include <map>
# include <stdexcept>
# include <queue>
# include "SystemManager.hpp"

namespace ecs
{
  using ContextType	= uint32_t;
  using Context		= std::map<SysType, bool>;

  class ContextManager
  {
    enum EStackAction
      {
	PUSH,
	POP
      };
  private:
    std::list<Context*>			_contexts;
    std::map<ContextType, Context>	_knownContexts;
    SystemManager*			_sysmgr;
    std::queue<std::pair<EStackAction, std::pair<Context *, bool>>> _todo;

    public:
    ContextManager();
    ContextManager(SystemManager* sysmgr) : _sysmgr(sysmgr) {}
    ~ContextManager() = default;
    ContextManager(ContextManager const&) = delete;
    ContextManager& operator=(ContextManager const&) = delete;

  public:
    void	push(ContextType key,	bool disableAll = false);
    void	push(Context *context,	bool disableAll = false);
    void	pop();
    void	reset();
    void	registerContext(ContextType	key,
				Context&&	context);


    void	registerContext(ContextType	key,
			        const Context&	context);
    void	execute();

  private:
    void	_push(Context *context,	bool disableAll = false);
    void	_pop();
  };
}

#endif //!CONTEXT_MANAGER
