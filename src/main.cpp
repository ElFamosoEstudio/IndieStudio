//
// main.cpp for indie studio in /home/silvy_n/projects/cpp_indie_studio/irrlicht-1.8.4
//
// Made by Noam SILVY
// Login   <silvy_n@epitech.net>
//
// Started on  Sun May 07 17:50:33 2017 Noam SILVY
// Last update Mon May 15 16:26:30 2017 Adam Akkari
//

#include <irrlicht.h>
#include "Scene.hh"
#include "ScenesList.hh"
#include "RessourcesLocator.hh"
#include "InputManager.hh"

int				main(void)
{
  InputManager::initialize();

  irr::core::dimension2d<unsigned int> dim(640, 480);
  irr::IrrlichtDevice		*device = irr::createDevice
    (irr::video::EDT_OPENGL, dim, 32, false, true, false, InputManager::getReceiver());
  irr::video::IVideoDriver	*video = device->getVideoDriver();
  Scene		*test = new Scene(device, video);

  loadTest(test);
  while (device->run())
    test->update();
  return (0);
}
