//
// engine.hpp for  in /home/julien/C++/IndieStudio/src/indie
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 19:51:44 2017 julien
// Last update Sun Jun 18 21:43:16 2017 julien
//

#ifndef ENGINE_HPP
# define ENGINE_HPP

# include "ecs.hpp"
# include "InputReceiver.hpp"
# include "components.hpp"
# include "CountDown.hpp"

namespace indie
{
  namespace engine
  {
    using namespace component;

    using IndieEntityManager = ecs::EntityManager<Transform,
						  Renderer3d,
						  Skeleton,
						  Camera,
						  Timer,
						  Interval,
						  BombInfo,
						  PowerInfo,
						  LifeNumber,
						  Damage,
						  HP,
						  Movement,
						  Respawn,
						  Speed,
						  PlayerId,
						  RemoteExplosion,
						  Spreadable,
						  MapSettings,
						  KeyMaps,
						  LuaScript,
						  Sound,
						  Music,
						  TagExplosion,
						  TagPlayer>;

    ecs::SystemManager&		systemManager();

    ecs::ContextManager&	contextManager();

    ecs::EventManager<>&	eventManager();

    indie::InputReceiver&	inputReceiver();

    IndieEntityManager&		entityManager();
  }
  void			init();
}

#endif // !ENGINE_HPP
