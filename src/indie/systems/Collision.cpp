//
// Collision.cpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Fri Jun 16 17:56:19 2017 akram abd-ali
// Last update Sun Jun 18 15:08:25 2017 akram abd-ali
//

#include "irrlicht.h"
#include "Collision.hpp"
#include "indie.hpp"

indie::system::Collision::Collision()
{
  auto key = engine::eventManager().
    subscribe(event::REMOVE_SKEL, &indie::system::Collision::removeSkel, this);
  _subKeys[event::REMOVE_SKEL] = key;
  key = engine::eventManager().
    subscribe(event::COL_ADD_BOMB, &indie::system::Collision::addBombsToAnimator, this);
  _subKeys[event::COL_ADD_BOMB] = key;
}

indie::system::Collision::~Collision()
{
  // for (auto const& it : _subKeys)
  //   engine::eventManager().unsubscribe(it.first, it.second);
}

void	indie::system::Collision::addBombsToAnimator(ecs::Entity entity)
{
  auto& cur = engine::entityManager().getComponent<indie::component::Skeleton>(entity);
  if ((!cur) || (!cur->metaSelector))
    return ;
  irr::scene::IMetaTriangleSelector* metaTriangles = cur->metaSelector;
  auto& bombs = engine::entityManager().getAllComponents<indie::component::BombInfo>();
  for (auto& it : bombs)
    {
      auto id = it.first;
      auto const& skel = engine::entityManager().getComponent<indie::component::Skeleton>(id);
      if ((!skel) || (!skel->selector))
	continue ;
      metaTriangles->addTriangleSelector(skel->selector);
    }
}

// void	indie::system::Collision::addBoxexToAnimator(ecs::Entity entity)
// {
//   auto& cur = engine::entityManager().getComponent<indie::component::Skeleton>(entity);
//   if ((!cur) || (!cur->metaSelector))
//     return ;
//   irr::scene::IMetaTriangleSelector* metaTriangles = cur->metaSelector;
//   auto& bombs = engine::entityManager().getAllComponents<indie::component::BombInfo>();
//   for (auto& it : bombs)
//     {
//       auto id = it.first;
//       auto const& skel = engine::entityManager().getComponent<indie::component::Skeleton>(id);
//       if ((!skel) || (!skel->selector))
// 	continue ;
//       metaTriangles->addTriangleSelector(skel->selector);
//     }
// }

void	indie::system::Collision::removeSkel(ecs::Entity entity)
{
  auto& cur = engine::entityManager().getComponent<indie::component::Skeleton>(entity);
  if ((!cur) || (!cur->selector))
    return ;
  auto&	skels = engine::entityManager().getAllComponents<indie::component::Skeleton>();
  for (auto& it : skels)
    {
      auto& skel = it.second;
      irr::scene::IMetaTriangleSelector *metaTriangles = skel->metaSelector;
      if (metaTriangles != nullptr)
	metaTriangles->removeTriangleSelector(cur->selector);
    }
  if (cur->metaSelector)
    cur->metaSelector->removeAllTriangleSelectors();
  if (cur->collider)
    cur->collider->drop();
  cur->selector->drop();
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
