//
// Collision.cpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Fri Jun 16 17:56:19 2017 akram abd-ali
// Last update Sat Jun 17 09:58:13 2017 akram abd-ali
//

#include "irrlicht.h"
#include "Collision.hpp"
#include "indie.hpp"

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
