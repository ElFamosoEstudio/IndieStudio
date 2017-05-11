//
// main.cpp for indie studio in /home/silvy_n/projects/cpp_indie_studio/irrlicht-1.8.4
//
// Made by Noam SILVY
// Login   <silvy_n@epitech.net>
//
// Started on  Sun May 07 17:50:33 2017 Noam SILVY
// Last update Thu May 11 19:18:00 2017 Noam SILVY
//

#include <irrlicht.h>

int                 main(void)
{
  int				a;
  int				b;
  irr::core::dimension2d<unsigned int> dim(640, 480);
  irr::IrrlichtDevice		*device = irr::createDevice(
      irr::video::EDT_OPENGL, dim);
  irr::video::IVideoDriver	*video = device->getVideoDriver();
  irr::scene::ISceneManager	*sm = device->getSceneManager();

  // irr::scene::ISceneNode       *cube = sm->addCubeSceneNode();

  // cube->setPosition(irr::core::vector3df(0, 0, 5));
  // cube->setScale(irr::core::vector3df(25, 1, 1));
  while (device && device->run())
  {
    video->beginScene(true, true, irr::video::SColor(255, 0, 0, 255));
    sm->drawAll();
    video->endScene();
  }
  return (0);
}
