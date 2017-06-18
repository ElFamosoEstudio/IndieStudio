//
// Collision.cpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Fri Jun 16 17:56:19 2017 akram abd-ali
// Last update Sun Jun 18 04:05:34 2017 Noam Silvy
//

#include "irrlicht.h"
#include "Collision.hpp"
#include "indie.hpp"

indie::system::Collision::Collision()
{
  std::cout << "CREATED CollisionSystem" << std::endl;
  indie::engine::eventManager().subscribe(indie::event::GO_RIGHT, [](ecs::Entity id){
      std::cout << "RECEIVED GO_RIGHT from " << id << std::endl;
    });
  indie::engine::eventManager().subscribe(indie::event::GO_LEFT, [](ecs::Entity id){
      std::cout << "RECEIVED GO_LEFT from " << id << std::endl;
    });
  indie::engine::eventManager().subscribe(indie::event::GO_UP, [](ecs::Entity id){
      std::cout << "RECEIVED GO_UP from " << id << std::endl;
    });
  indie::engine::eventManager().subscribe(indie::event::GO_DOWN, [](ecs::Entity id){
      std::cout << "RECEIVED GO_DOWN from " << id << std::endl;
    });
}

void	indie::system::Collision::update() {
  auto&	skels = engine::entityManager().getAllComponents<indie::component::Skeleton>();

  for (auto& it : skels)
    {
      auto id = it.first;
      auto& skel = it.second;
      irr::scene::ISceneNode* collidedNode = nullptr;
      irr::scene::ISceneNodeAnimatorCollisionResponse *colAnimator = skel->collider;
      if ((colAnimator != nullptr)
	  && (colAnimator->collisionOccurred() == true)
	  && ((collidedNode = colAnimator->getCollisionNode()) != nullptr))
	{
	  engine::eventManager().emit(event::COLLIDED, collidedNode->getID());
	  engine::eventManager().emit(event::COLLIDED, id);
	}
    }
}

ecs::SysType	indie::system::Collision::type() const
{
  return (system::COLLISION);
}

ecs::ISystem	*indie::system::Collision::create()
{
  return new Collision;
}
