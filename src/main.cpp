#include <iostream>
#include "irrlicht.h"
#include "ecs.hpp"
#include "engine.hpp"
#include "ESystem.hpp"
#include "registerAllSystems.hpp"
#include "registerAllContexts.hpp"

void init(irr::IrrlichtDevice *device)
{
  indie::engine::provideDevice(device);
  indie::system::registerAllSystems();
  indie::context::registerAllContexts();
}

int main()
{
  irr::IrrlichtDevice *device =
    irr::createDevice(irr::video::EDT_OPENGL,
		      irr::core::dimension2d<irr::u32>(1920, 968), 16, false);
  init(device);
  // CODE ABOVE ABSOLUTLY NECESSARY BEFORE ANYTHING ELSE

  indie::engine::contextManager().push(indie::context::MAIN_MENU);

  auto id = indie::engine::entityManager().createEntity();
  indie::engine::eventManager().subscribe(42, [](ecs::Entity id){
      std::cout << "Received event" << id << std::endl;
    });
  indie::engine::eventManager().emit(42, id);

  indie::InputReceiver::Keyboard   keyboard = indie::engine::inputReceiver().getKeyboard();

  while(device->run())
      {
	indie::engine::inputReceiver().disableInputHandling();
	indie::engine::systemManager().update();
        indie::engine::inputReceiver().enableInputHandling();
      }
  indie::engine::inputReceiver().disableInputHandling();
  device->drop();
  return 0;
}
