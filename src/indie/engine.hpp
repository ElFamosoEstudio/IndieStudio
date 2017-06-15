//
// Engine.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Sat Jun 10 03:34:26 2017 akram abd-ali
// Last update Thu Jun 15 18:28:03 2017 Noam Silvy
//

#ifndef ENGINE_HPP
# define ENGINE_HPP

# include "irrlicht.h"
# include "ecs.hpp"
# include "InputReceiver.hpp"
# include "Position.hpp"
# include "Velocity.hpp"

namespace indie
{
  namespace engine
  {
    using namespace component;
    using IndieEntityManager = ecs::EntityManager<Position, Velocity>;

    static irr::IrrlichtDevice *_device = nullptr;

    void	provideDevice(irr::IrrlichtDevice *device);

    ecs::SystemManager&	systemManager();

    ecs::ContextManager&	contextManager();

    ecs::EventManager<>&	eventManager();

    indie::InputReceiver&	inputReceiver();

    IndieEntityManager&		entityManager();
  }
}

#endif // !ENGINE_HPP
