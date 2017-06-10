#include <iostream>
#include "EntityManager.hpp"
#include "EventManager.hpp"
#include "SystemManager.hpp"
#include "SoundSystem.hpp"
#include "ContextManager.hpp"
#include "SystemFactory.hpp"

struct CVelocity {int velocity;};
struct CPosition {int x; int y;};
struct CGraphics {std::string mesh;};

void	toto(uint32_t ha)
{
  std::cout << "toto " << ha << std::endl;
}

class A
{
public:
  A()
  {

  }
  void	fctA(uint32_t i)
  {
    std::cout << "fctA " << i << std::endl;
  }
  void	fctAA(uint32_t i, uint32_t j)
  {
    std::cout << "fctA " << i << " " << j << std::endl;
  }
};


class B
{
public:
  B()
  {
    // EventManager *e = EventManager::Instance();
    // e->emit("manger");
  }
  void	fctA(uint32_t i)
  {
    std::cout << "fctA " << i << std::endl;
  }
  void	fctAA(uint32_t i, uint32_t j)
  {
    std::cout << "fctA " << i << " " << j << std::endl;
  }
};


int main()
{
  ecs::EntityManager<CVelocity, CPosition, CGraphics>	manager;
  ecs::Entity						id = manager.createEntity();
  CVelocity						comp;
  ecs::SystemManager				smgr;
  ecs::SystemFactory				sfact;
  ecs::ContextManager				cmgr(&smgr, &sfact);

  ecs::ContextManager::Context			ctx = {{2, true}};
  ecs::ContextManager::Context			ctxf = {{2, false}};

  cmgr.push(&ctx);
  std::cout << "presence " << smgr.isPresentSystem(1) << std::endl;
  smgr.push(new ecs::SoundSystem, true);
  std::cout << "state is " << smgr.getState(1) << std::endl;
  smgr.setState(1, true);
  std::cout << "state is " << smgr.getState(1) << std::endl;
  std::cout << "presence " << smgr.isPresentSystem(1) << std::endl;
  cmgr.push(&ctx);
  cmgr.push(&ctxf);
  cmgr.pop();
  cmgr.pop();
  smgr.update();
  cmgr.pop();
  smgr.update();
  smgr.remove(1);
  std::cout << "presence " << smgr.isPresentSystem(1) << std::endl;
  std::cout << "state is " << smgr.getState(1) << std::endl;
  smgr.update();

  // comp.velocity = 2;
  // manager.addComponent(id, comp);
  // manager.addComponent(id, CPosition());
  // manager.addComponent(id, CGraphics());
  // std::cout << manager.getComponent<CVelocity>(id).velocity << std::endl;
  // manager.getComponent<CVelocity>(id).velocity = 10;
  // std::cout << manager.getAllComponents<CVelocity>()[id].velocity << std::endl;
  // manager.removeComponent<CVelocity>(id);
  // manager.removeEntity(id);
  // manager.getComponent<CVelocity>(id).velocity = 10; // should fail
  // auto lal = [](int a, int b) {
  //   std::cout << "Event 0:" << std::endl;
  //   std::cout << "a: " << a << std::endl;
  //   std::cout << "b: " << a << std::endl;
  // };
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



  // A alpha;
  // ecs::EventManager<int> *f = new ecs::EventManager<int>;

  // std::cout << "subscribed elem " <<   f->subscribe(2, toto) << std::endl;
  // std::cout << "subscribed elem " <<   f->subscribe(43, toto) << std::endl;
  // std::cout << "subscribed elem " <<   f->subscribe(43, &A::fctA, &alpha) << std::endl;
  // f->unsubscribe(43, 0);
  // f->unsubscribe(43, 1);
  // f->emit(43, 28);

  // auto l = [](uint32_t var){std::cout << "jaja lvalue " << var << std::endl;};
  // std::cout << "subscribed elem " <<   f->subscribe(43, [](uint32_t var){std::cout << "jaja " << var << std::endl;}) << std::endl;
  // std::cout << "subscribed elem " <<   f->subscribe(43, l) << std::endl;
  // f->emit(43, 5);
  return 0;
}
