//
// Skeleton.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Fri Jun 16 17:13:43 2017 akram abd-ali
// Last update Fri Jun 16 22:06:02 2017 akram abd-ali
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
      irr::scene::ITriangleSelector	*selector;
      irr::scene::IMetaTriangleSelector	*metaSelector;
      irr::scene::ISceneNodeAnimatorCollisionResponse *collider;
    };
  }
}

#endif // SKELETON_HPP
