//
// Camera.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/components
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Fri Jun 16 19:53:30 2017 Adam Akkari
// Last update Fri Jun 16 20:20:53 2017 Adam Akkari
//

#ifndef CAMERA_HPP
# define CAMERA_HPP

namespace indie
{
  namespace component
  {
    struct Camera
    {
      Camera()
	: camera(gfx::sceneManager()->addCameraSceneNode
		 (0, irr::core::vector3df(0,0,0),
		  irr::core::vector3df(0,0,0), -1))
      {}
      irr::scene::ICameraSceneNode	*camera;
    };
  }
}

#endif // CAMERA_HPP
