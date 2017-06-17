#include <iostream>
#include "irrlicht.h"
#include "indie.hpp"
#include "Menu.hpp"

int	main(void)
{
  indie::system::Collision col;
  indie::system::MeshRenderer col2;
  indie::init(); // For now: registers all factories
  indie::MainMenu		manu;

  indie::engine::contextManager().push(indie::context::GAME);

  while (indie::gfx::device()->run())
      {
	indie::engine::inputReceiver().disableInputHandling();
	indie::gfx::videoDriver()->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
	manu.update();
	indie::engine::systemManager().update();
	indie::gfx::sceneManager()->drawAll();
	indie::gfx::videoDriver()->endScene();
        indie::engine::inputReceiver().enableInputHandling();
      }
  indie::engine::inputReceiver().disableInputHandling();
  indie::gfx::device()->drop();
  return 0;
}
