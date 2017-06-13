#include <iostream>
#include "irrlicht.h"
#include "ecs.hpp"
#include "SoundSystem.hpp"
#include "InputReceiver.hpp"
#include "Engine.hpp"

// struct CVelocity {int velocity;};
// struct CPosition {int x; int y;};
// struct CGraphics {std::string mesh;};

// indie::Engine::_device = nullptr;

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



class Sys : public ecs::ISystem
{
 public:
  void update() override {std::cout << "Sys update" << std::endl;}
  ecs::SysType type() const override {return 47;}
} sys;

int main()
{
  ecs::EntityManager<CVelocity, CPosition, CGraphics>	manager;
  ecs::Entity						id = manager.createEntity();
  CVelocity						comp;
  ecs::SystemManager				smgr;
  ecs::SystemFactory				sfact;
  ecs::ContextManager				cmgr(&smgr, &sfact);

  ecs::ContextManager::Context			ctx = {{2, true}, {1, true}};
  ecs::ContextManager::Context			ctxf = {{2, false}, {1, true}};
  ecs::ContextManager::Context			dis = {{1, true}};
  irr::IrrlichtDevice *device =
    irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 968), 16, false);
  // indie::Engine::initialize(device);
  // indie::Engine::entityManager().createEntity();
  // indie::Engine::systemManager().push(&sys);
  // indie::Engine::contextManager().push(new std::map<ecs::SysType, bool>{{1, true},{2, true}});
  // indie::Engine::eventManager().subscribe(42, [](ecs::Entity id){
  //     std::cout << "Received event" << id << std::endl;
  //   });
  // indie::Engine::eventManager().emit(42, 42);

  indie::InputReceiver* receiver = new indie::InputReceiver(device);
  device->setEventReceiver(receiver);


  // cmgr.push(&ctx);
  // cmgr.push(&dis, true);

  // std::cout << "presence " << smgr.isPresentSystem(1) << std::endl;
  // smgr.push(new ecs::SoundSystem, true);
  // std::cout << "state is " << smgr.getState(1) << std::endl;
  // smgr.setState(1, true);
  // std::cout << "state is " << smgr.getState(1) << std::endl;
  // std::cout << "presence " << smgr.isPresentSystem(1) << std::endl;
  // cmgr.push(&ctx);
  // cmgr.push(&ctxf);
  // cmgr.pop();
  // cmgr.pop();
  // smgr.update();
  // cmgr.pop();
  // smgr.update();
  // smgr.remove(1);
  // std::cout << "presence " << smgr.isPresentSystem(1) << std::endl;
  // std::cout << "state is " << smgr.getState(1) << std::endl;
  // smgr.update();

  indie::InputReceiver::Keyboard   keyboard = static_cast<indie::InputReceiver*>(receiver)->getKeyboard();
  // indie::InputReceiver::Keyboard   keyboard = indie::Engine::inputReceiver().getKeyboard();
    while(device->run())
      {
	// indie::Engine::inputReceiver().disableInputHandling();
	// indie::Engine::systemManager().update();
        // indie::Engine::inputReceiver().enableInputHandling();
	receiver->disableInputHandling();
	smgr.update();
	receiver->enableInputHandling();
      }
    device->drop();
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
