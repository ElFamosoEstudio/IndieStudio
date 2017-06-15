#include <iostream>
#include "irrlicht.h"
#include "ecs.hpp"
#include "engine.hpp"
#include "system.hpp"
#include "context.hpp"
#include "entity.hpp"

void init(irr::IrrlichtDevice *device)
{
  indie::engine::provideDevice(device);
  indie::system::registerAllSystems();
  indie::context::registerAllContexts();
  indie::entity::registerAllEntities();
}

int main()
{
  irr::IrrlichtDevice *device =
    irr::createDevice(irr::video::EDT_OPENGL,
		      irr::core::dimension2d<irr::u32>(1920, 968), 16, false);
  init(device);
  // CODE ABOVE ABSOLUTLY NECESSARY BEFORE ANYTHING ELSE

  indie::engine::contextManager().push(indie::context::MAIN_MENU);

  while (device->run())
      {
	indie::engine::inputReceiver().disableInputHandling();
	indie::engine::systemManager().update();
        indie::engine::inputReceiver().enableInputHandling();	
      }
  indie::engine::inputReceiver().disableInputHandling();
  device->drop();
  return 0;
}
