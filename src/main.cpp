#include <iostream>
#include "irrlicht.h"
#include "indie.hpp"

int main()
{
  indie::init(); // For now: registers all factories

  indie::engine::contextManager().push(indie::context::MAIN_MENU);

  while (indie::gfx::device()->run())
      {
	indie::engine::inputReceiver().disableInputHandling();
	indie::engine::systemManager().update();
        indie::engine::inputReceiver().enableInputHandling();	
      }
  indie::engine::inputReceiver().disableInputHandling();
  indie::gfx::device()->drop();
  return 0;
}
