//
// Engine.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Sat Jun 10 03:34:26 2017 akram abd-ali
// Last update Wed Jun 14 02:25:06 2017 Noam Silvy
//

#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <cassert>
# include <memory>
# include "irrlicht.h"
# include "ecs.hpp"
# include "Position.hpp"
# include "Velocity.hpp"
# include "InputReceiver.hpp"

namespace indie
{
  namespace engine
  {
    static irr::IrrlichtDevice *_device = nullptr;

    static void	        provideDevice(irr::IrrlichtDevice *device)
    {
      _device = device;
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
      static ecs::ContextManager _contextManager(std::addressof(systemManager()),
						 std::addressof(systemFactory()));
      return (_contextManager);
    }

    static auto&	eventManager()
    {
      static ecs::EventManager<> _eventManager;
      return (_eventManager);
    }

    static auto&	inputReceiver()
    {
      assert(_device);
      static InputReceiver _inputReceiver(_device);
      return (_inputReceiver);
    }

    using namespace component;
    static auto&	entityManager()
    {
      static ecs::EntityManager<Position, Velocity> _entityManager;
      return (_entityManager);
    }
  }
}

#endif // !ENGINE_HPP
