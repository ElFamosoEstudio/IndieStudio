//
// Engine.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Sat Jun 10 03:34:26 2017 akram abd-ali
// Last update Tue Jun 13 18:42:34 2017 Noam Silvy
//

#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <cassert>
# include "irrlicht.h"
# include "ecs.hpp"

struct CVelocity {int velocity;};
struct CPosition {int x; int y;};
struct CGraphics {std::string mesh;};

namespace indie
{
  class Engine
  {
  private:
    Engine() = delete;
    ~Engine() = delete;
    Engine(Engine const&) = delete;
    Engine& operator=(Engine const&) = delete;

  public:
    static void		initialize(irr::IrrlichtDevice *device)
    {
      Engine::_device = device;
    }
    static ecs::EntityManager<CPosition,
				CVelocity,
				CGraphics>&	entityManager()
    {
      static ecs::EntityManager<CPosition,
				CVelocity,
				CGraphics> _entityManager;
      return (_entityManager);
    }

    static auto&	systemManager()
    {
      static ecs::SystemManager _systemManager;
      return (_systemManager);
    }

    static auto&	systemFactory()
    {
      static ecs::SystemFactory _systemFactory;
      return (_systemFactory);
    }

    static auto&	contextManager()
    {
      static ecs::ContextManager _contextManager(&Engine::systemManager(),
						 &Engine::systemFactory());
      return (_contextManager);
    }

    static auto&	eventManager()
    {
      static ecs::EventManager<> _eventManager;
      return (_eventManager);
    }

    static auto&	inputReceiver()
    {
      assert(_device != NULL);
      static indie::InputReceiver _inputReceiver(_device);
      return (_inputReceiver);
    }

  private:
    static irr::IrrlichtDevice *_device;
  };
}

#endif // !ENGINE_HPP
