#include <iostream>
#include "irrlicht.h"
#include "indie.hpp"
#include <chrono>
#include <thread>

using namespace indie::component;

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds ms;
size_t FPS = 80;
size_t APS = 90;
Clock::time_point t0 = Clock::now();
size_t FPST = ((1.f / FPS) * 1000);
size_t APST = ((1.f / APS) * 1000);
size_t acc = 0;

int	main()
{
  indie::init(); // For now: registers all factories
  indie::engine::contextManager().push(indie::context::GAME);
  ecs::Entity map = indie::engine::entityManager().create(indie::entity::MAP, MapSettings(9,9));

  while (indie::gfx::device()->run())
    {
      Clock::time_point t1;
      t1 = Clock::now();
      size_t inter = std::chrono::duration_cast<ms>(t1 - t0).count();
      t0 = t1;

      acc += inter;
      if (inter <= FPST)
	{
	  size_t fps_sleep = ((1.f / FPS) * 1000) - inter;
	  std::this_thread::sleep_for (std::chrono::milliseconds(fps_sleep));
	}
      if (acc >= APST)
	{
	  acc -= APST;
	  indie::engine::systemManager().update();
	  indie::engine::contextManager().execute();
	}


      indie::engine::inputReceiver().disableInputHandling();
      indie::gfx::videoDriver()->beginScene(true, true,
					    irr::video::SColor(255, 255, 255, 255));
      indie::gfx::sceneManager()->drawAll();
      indie::gfx::videoDriver()->endScene();
      indie::engine::inputReceiver().enableInputHandling();
    }
  indie::engine::inputReceiver().disableInputHandling();
  indie::gfx::device()->drop();
  return 0;
}
