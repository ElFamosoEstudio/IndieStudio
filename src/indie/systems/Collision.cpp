//
// Collision.cpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Fri Jun 16 17:56:19 2017 akram abd-ali
// Last update Wed Jun 21 04:55:46 2017 akram abd-ali
//

#include "irrlicht.h"
#include "Collision.hpp"
#include "indie.hpp"

indie::system::Collision::Collision()
{
  auto key = engine::eventManager().
    subscribe(event::REMOVE_SKEL, &indie::system::Collision::removeSkel, this);
  _eventKeys[event::REMOVE_SKEL] = key;
  key = engine::eventManager().
    subscribe(event::COL_ADD_ELEM, &indie::system::Collision::addElemToAnimators, this);
  _eventKeys[event::COL_ADD_ELEM] = key;
  key = engine::eventManager().
    subscribe(event::COL_ADD_OBS, &indie::system::Collision::addObsToAnimator, this);
  _eventKeys[event::COL_ADD_OBS] = key;
}

indie::system::Collision::~Collision()
{
}

void	indie::system::Collision::addElemToAnimators(ecs::Entity entity)
{
  auto& cur = engine::entityManager().getComponent<indie::component::Skeleton>(entity);
  if ((!cur) || (!cur->selector))
    return ;
  auto& skels = engine::entityManager().getAllComponents<indie::component::Skeleton>();
  irr::scene::ITriangleSelector* triangles = cur->selector;
  int i = 0;
  for (auto& it : skels)
    {
      auto id = it.first;
      auto const& skel = engine::entityManager().getComponent<indie::component::Skeleton>(id);
      if ((!skel) || (!skel->metaSelector) || (!skel->collider))
	continue ;
      irr::scene::IMetaTriangleSelector* metaTriangles = skel->metaSelector;
      metaTriangles->addTriangleSelector(triangles);
    }
}

void	indie::system::Collision::addObsToAnimator(ecs::Entity entity)
{
  auto& cur = engine::entityManager().getComponent<indie::component::Skeleton>(entity);
  if ((!cur) || (!cur->metaSelector))
    return ;
  irr::scene::IMetaTriangleSelector* metaTriangles = cur->metaSelector;
  auto& obstacles = engine::entityManager().getAllComponents<indie::component::TagObs>();
  if (obstacles.size() == 0)
    {
      engine::entityManager().addComponentEmplace<component::Timer>(entity, 50, event::COL_ADD_OBS);
      return ;
    }
  for (auto& it : obstacles)
    {
      auto id = it.first;
      auto const& skel = engine::entityManager().getComponent<indie::component::Skeleton>(id);
      if ((!skel) || (!skel->selector))
	continue ;
      metaTriangles->addTriangleSelector(skel->selector);
    }
}

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
  auto&	trans = engine::entityManager().getAllComponents<indie::component::Renderer3d>();

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
	  engine::eventManager().emit(event::COLLIDED, id);
	  ecs::Entity bis = -1;
	  for (auto const &itb : trans)
	    {
	      if (collidedNode == itb.second->mesh)
		{
		  bis = itb.first;
		  break ;
		}
	    }
	  engine::eventManager().emit(event::COLLIDED, bis);
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
