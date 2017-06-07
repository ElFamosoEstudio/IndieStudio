#include <iostream>
#include "EntityManager.hpp"
#include "EventManager.hpp"

struct CVelocity {int velocity;static const ecs::CTypeSize TYPE = 1;};
struct CPosition {int x; int y;static const ecs::CTypeSize TYPE = 4;};
struct CGraphics {std::string mesh;static const ecs::CTypeSize TYPE = 8;};

void toto(int a, int b)
{
  // std::cout << "Event 0:" << std::endl;
  // std::cout << "a: " << a << std::endl;
  // std::cout << "b: " << a << std::endl;
  std::cout << "Totooooooo" << std::endl;
}

int main()
{
  ecs::EntityManager<CVelocity, CPosition, CGraphics>	manager;
  ecs::Entity						id = manager.createEntity();
  CVelocity						comp;
  // EventManager<int>					eventManager;

  comp.velocity = 2;
  manager.addComponent(id, comp);
  manager.addComponent(id, CPosition());
  manager.addComponent(id, CGraphics());
  std::cout << manager.getComponent<CVelocity>(id).velocity << std::endl;
  manager.getComponent<CVelocity>(id).velocity = 10;
  std::cout << manager.getAllComponents<CVelocity>()[id].velocity << std::endl;
  manager.removeComponent<CVelocity>(id);
  manager.removeEntity(id);
  // manager.getComponent<CVelocity>(id).velocity = 10; // should fail
  auto lal = [](int a, int b) {
    std::cout << "Event 0:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << a << std::endl;
  };
  // eventManager.subscribe(0, [](int a, int b){
  //     std::cout << "Event 0:" << std::endl;
  //     std::cout << "a: " << a << std::endl;
  //     std::cout << "b: " << a << std::endl;
  //   });
  // eventManager.subscribe(1, [](std::string s){
  //     std::cout << "Event 1:" << std::endl;
  //     std::cout << "s: " << s << std::endl;
  //   });
  // eventManager.subscribe(0, toto);
  // eventManager.emit(0, 42, 84);
  return 0;
}
