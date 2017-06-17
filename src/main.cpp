#include <iostream>
#include "irrlicht.h"
#include "indie.hpp"

using namespace indie::component;

void	map()
{
  unsigned int size_x = 9;
  unsigned int size_y = 9;
  static std::list<ecs::Entity> *walls = new std::list<ecs::Entity>;
  
  indie::engine::entityManager().create
    (indie::entity::BOX, Transform(-1, -1, 0));
  indie::engine::entityManager().create
    (indie::entity::BOX, Transform(size_x, -1, 0));
  indie::engine::entityManager().create
    (indie::entity::BOX, Transform(-1, size_y, 0));
  indie::engine::entityManager().create
    (indie::entity::BOX, Transform(size_x, size_y, 0));
  for (unsigned int i = 0; i < size_x; i++)
    {
      indie::engine::entityManager().create
	(indie::entity::BOX, Transform(i, -1, 0));
      indie::engine::entityManager().create
	(indie::entity::BOX, Transform(i, size_y, 0));
    }
  for (unsigned int j = 0; j < size_y; j++)
    {
      indie::engine::entityManager().create
	(indie::entity::BOX, Transform(-1, j, 0));
      indie::engine::entityManager().create
	(indie::entity::BOX, Transform(size_x, j, 0));
    }
}

int	main()
{
  indie::system::Collision col;
  indie::system::MeshRenderer col2;
  indie::init(); // For now: registers all factories

  indie::engine::contextManager().push(indie::context::GAME);

  ecs::Entity bite = indie::engine::entityManager().create
    (indie::entity::BOX, Transform(-1, -1, 0));
  ecs::Entity cam = indie::engine::entityManager().create(indie::entity::CAMERA);
  
  indie::engine::entityManager().getComponent<Transform>(cam)->position
    = irr::core::vector3df(0, -1, 10);
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
