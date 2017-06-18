#include <iostream>
#include "irrlicht.h"
#include "indie.hpp"

using namespace indie::component;

int	main()
{
  indie::system::Collision col;
  indie::system::MeshRenderer col2;
  indie::init(); // For now: registers all factories

  indie::engine::contextManager().push(indie::context::GAME);

  ecs::Entity map = indie::engine::entityManager().create(indie::entity::MAP, MapSettings(12,12));

  while (indie::gfx::device()->run())
    {
      indie::engine::inputReceiver().disableInputHandling();
      indie::gfx::videoDriver()->beginScene(true, true,
					    irr::video::SColor(255, 255, 255, 255));
      indie::engine::systemManager().update();
      indie::engine::contextManager().execute();
      indie::gfx::sceneManager()->drawAll();
      indie::gfx::videoDriver()->endScene();
      indie::engine::inputReceiver().enableInputHandling();
    }
  indie::engine::inputReceiver().disableInputHandling();
  indie::gfx::device()->drop();
  return 0;
}
