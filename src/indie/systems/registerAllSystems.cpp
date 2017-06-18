//
// FeedFactory.cpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/systems
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed Jun 14 02:11:12 2017 Noam Silvy
// Last update Sun Jun 18 18:43:20 2017 Noam Silvy
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
						&indie::system::Bomb::create);
  indie::engine::systemManager().registerSystem(indie::system::MESH_RENDERER,
						&indie::system::MeshRenderer::create);
  indie::engine::systemManager().registerSystem(indie::system::CAMERA_SYSTEM,
						&indie::system::CameraSystem::create);
  indie::engine::systemManager().registerSystem(indie::system::MAP_GENERATOR,
						&indie::system::MapGenerator::create);
  indie::engine::systemManager().registerSystem(indie::system::INPUT,
						&indie::system::Input::create);
  indie::engine::systemManager().registerSystem(indie::system::MOVEMENT,
						&indie::system::Movement::create);
  indie::engine::systemManager().registerSystem(indie::system::ANIMATION,
						&indie::system::AnimationSystem::create);
}
