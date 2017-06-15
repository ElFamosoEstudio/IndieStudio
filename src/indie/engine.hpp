//
// Engine.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Sat Jun 10 03:34:26 2017 akram abd-ali
// Last update Fri Jun 16 01:45:01 2017 Adam Akkari
//

#ifndef ENGINE_HPP
# define ENGINE_HPP

# include "irrlicht.h"
# include "ecs.hpp"
# include "InputReceiver.hpp"
# include "Transform.hpp"
# include "Renderer3d.hpp"

namespace indie
{
  namespace engine
  {
    using namespace component;
    using IndieEntityManager = ecs::EntityManager<Transform, Renderer3d>;

    static irr::IrrlichtDevice *_device = nullptr;

    void	provideDevice(irr::IrrlichtDevice *device);

    ecs::SystemManager&	systemManager();

    ecs::ContextManager&	contextManager();

    ecs::EventManager<>&	eventManager();

    indie::InputReceiver&	inputReceiver();

    IndieEntityManager&		entityManager();

    irr::scene::ISceneManager	*sceneManager();
  }
}

#endif // !ENGINE_HPP
