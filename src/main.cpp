#include <iostream>
#include "EntityManager.hpp"

struct CVelocity {int velocity;static const ecs::CTypeSize TYPE = 1;};
struct CPosition {int x; int y;static const ecs::CTypeSize TYPE = 4;};
struct CGraphics {std::string mesh;static const ecs::CTypeSize TYPE = 8;};

int main()
{
  ecs::EntityManager<CVelocity, CPosition, CGraphics>	manager;
  ecs::Entity						id = manager.createEntity();
  CVelocity						comp;

  comp.velocity = 2;
  manager.addComponent(id, comp);
  std::cout << manager.getComponent<CVelocity>(id).velocity << std::endl;
  manager.getComponent<CVelocity>(id).velocity = 10;
  std::cout << manager.getAllComponents<CVelocity>()[id].velocity << std::endl;
  return 0;
}
