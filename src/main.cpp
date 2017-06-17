#include <iostream>
#include "irrlicht.h"
#include "indie.hpp"

using namespace indie::component;

int	main()
{
  indie::system::Collision col;
  indie::system::MeshRenderer col2;
  indie::init(); // For now: registers all factories
  indie::system::MainMenu		manu;

  indie::engine::contextManager().push(indie::context::MAIN_MENU);
  indie::engine::contextManager().push(indie::context::GAME);

  ecs::Entity box = indie::engine::entityManager().create(indie::entity::BOX);
  ecs::Entity cam = indie::engine::entityManager().create(indie::entity::CAMERA);

  indie::engine::entityManager().getComponent<Transform>(box)->position
    = irr::core::vector3df(0, 0, 0);
  indie::engine::entityManager().getComponent<Transform>(box)->rotation
    = irr::core::vector3df(0, 0, 0);
  indie::engine::entityManager().getComponent<Transform>(box)->scale
    = irr::core::vector3df(1, 1, 1);
  indie::engine::entityManager().getComponent<Transform>(cam)->position
    = irr::core::vector3df(0, 5, 0);
  indie::engine::entityManager().getComponent<Camera>(cam)->lookat
    = irr::core::vector3df(0, 0, 0);

  while (indie::gfx::device()->run())
    {
      indie::engine::inputReceiver().disableInputHandling();
      indie::gfx::videoDriver()->beginScene(true, true,
					    irr::video::SColor(255, 255, 255, 255));
      indie::engine::systemManager().update();
      indie::gfx::sceneManager()->drawAll();
      indie::gfx::videoDriver()->endScene();
      indie::engine::inputReceiver().enableInputHandling();
    }
  indie::engine::inputReceiver().disableInputHandling();
  indie::gfx::device()->drop();
  return 0;
}
