#include <iostream>
#include "irrlicht.h"
#include "ecs.hpp"
#include "engine.hpp"
#include "ESystem.hpp"
#include "FeedFactory.hpp"

int main()
{
  irr::IrrlichtDevice *device =
    irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 968), 16, false);
  indie::engine::provideDevice(device);
  indie::system::feedFactory();
  // CODE ABOVE ABSOLUTLY NECESSARY BEFORE ANYTHING ELSE

  ecs::ContextManager::Context			ctx = {{indie::system::INPUT,
							true}};
  indie::engine::contextManager().push(&ctx);

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
    device->drop();
  return 0;
}
