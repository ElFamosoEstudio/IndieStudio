//
// Skeleton.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Fri Jun 16 17:13:43 2017 akram abd-ali
// Last update Sun Jun 18 11:44:30 2017 akram abd-ali
//

#ifndef SKELETON_HPP
# define SKELETON_HPP

# include "irrlicht.h"

namespace indie
{
  namespace component
  {
    struct Skeleton
    {
      irr::scene::ITriangleSelector			*selector;
      irr::scene::IMetaTriangleSelector			*metaSelector;
      irr::scene::ISceneNodeAnimatorCollisionResponse	*collider;
      Skeleton()
	: selector(nullptr),
	  metaSelector(nullptr),
	  collider(nullptr) {}
      Skeleton(irr::scene::ISceneNode* node, bool collide = false)
	: metaSelector(nullptr),
	  collider(nullptr)
      {
	if (!node)
	  return ;
	selector = gfx::sceneManager()->createTriangleSelectorFromBoundingBox(node);
	node->setTriangleSelector(selector);
	if (!collide)
	  return ;
	metaSelector = gfx::sceneManager()->createMetaTriangleSelector();
	const irr::core::aabbox3df& box = node->getBoundingBox();
	collider = gfx::sceneManager()->
	  createCollisionResponseAnimator(selector, node, node->getScale()
					  * (box.MaxEdge-box.getCenter()),
					  irr::core::vector3df(0,0,0),
					  -node->getScale() * (box.getCenter()));

      }
    };
  }
}

#endif // SKELETON_HPP
