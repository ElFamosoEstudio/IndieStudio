#include "engine.hpp"
#include "system.hpp"

void        indie::system::registerAllSystems()
{
  indie::engine::systemManager().registerSystem(indie::system::COLLISION,
						&indie::system::Collision::create);
  indie::engine::systemManager().registerSystem(indie::system::BOMB,
						&indie::system::Bomb::create);
  indie::engine::systemManager().registerSystem(indie::system::EXPLOSION,
						&indie::system::Bomb::create);
  indie::engine::systemManager().registerSystem(indie::system::MESH_RENDERER,
						&indie::system::MeshRenderer::create);
  indie::engine::systemManager().registerSystem(indie::system::CAMERA_SYSTEM,
						&indie::system::CameraSystem::create);
  indie::engine::systemManager().registerSystem(indie::system::SUB_MENU,
						&indie::system::SubMenu::create);
  indie::engine::systemManager().registerSystem(indie::system::MAIN_MENU,
						&indie::system::MainMenu::create);
  indie::engine::systemManager().registerSystem(indie::system::MAP_GENERATOR,
						&indie::system::MapGenerator::create);
}
