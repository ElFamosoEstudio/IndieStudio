//
// Engine.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Sat Jun 10 03:34:26 2017 akram abd-ali
// Last update Sun Jun 18 05:50:51 2017 julien
//

#ifndef ENGINE_HPP
# define ENGINE_HPP

# include "ecs.hpp"
# include "InputReceiver.hpp"
# include "components.hpp"

namespace indie
{
  namespace engine
  {
    using namespace component;
    using IndieEntityManager = ecs::EntityManager<Transform, Renderer3d, Skeleton, Camera, LuaScript, Sound>;

    ecs::SystemManager&		systemManager();

    ecs::ContextManager&	contextManager();

    ecs::EventManager<>&	eventManager();

    indie::InputReceiver&	inputReceiver();

    IndieEntityManager&		entityManager();

    void			init();
  }
}

#endif // !ENGINE_HPP
