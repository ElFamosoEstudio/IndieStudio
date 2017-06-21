//
// FeedFactory.cpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/systems
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed Jun 14 02:11:12 2017 Noam Silv
// Last update Wed Jun 21 17:38:09 2017 akram abd-ali
//

#include "engine.hpp"
#include "system.hpp"

void        indie::system::registerAllSystems()
{
  indie::engine::systemManager().registerSystem(indie::system::COLLISION,
						&indie::system::Collision::create);
  indie::engine::systemManager().registerSystem(indie::system::BOMB,
						&indie::system::Bomb::create);
  indie::engine::systemManager().registerSystem(indie::system::EXPLOSION,
						&indie::system::Explosion::create);
  indie::engine::systemManager().registerSystem(indie::system::MESH_RENDERER,
						&indie::system::MeshRenderer::create);
  indie::engine::systemManager().registerSystem(indie::system::CAMERA_SYSTEM,
						&indie::system::CameraSystem::create);
  indie::engine::systemManager().registerSystem(indie::system::SUB_MENU,
						&indie::system::SubMenu::create);
  indie::engine::systemManager().registerSystem(indie::system::MAIN_MENU,
						&indie::system::MainMenu::create);
  indie::engine::systemManager().registerSystem(indie::system::OVER_MENU,
						&indie::system::OverMenu::create);
  indie::engine::systemManager().registerSystem(indie::system::MAP_GENERATOR,
						&indie::system::MapGenerator::create);
  indie::engine::systemManager().registerSystem(indie::system::INPUT,
						&indie::system::Input::create);
  indie::engine::systemManager().registerSystem(indie::system::MOVEMENT,
						&indie::system::Movement::create);
  indie::engine::systemManager().registerSystem(indie::system::ANIMATION,
						&indie::system::AnimationSystem::create);
  indie::engine::systemManager().registerSystem(indie::system::SYSTIME,
						&indie::system::SysTime::create);
  indie::engine::systemManager().registerSystem(indie::system::SPAWN,
						&indie::system::Spawn::create);
  indie::engine::systemManager().registerSystem(indie::system::DIE,
						&indie::system::Die::create);
    indie::engine::systemManager().registerSystem(indie::system::BONUS_SYSTEM,
						  &indie::system::BonusSystem::create);
}
