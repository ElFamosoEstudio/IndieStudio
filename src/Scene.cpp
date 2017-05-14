//
// Scene.cpp for bomberman in /home/akkari_a/work/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 01:18:50 2017 Adam Akkari
// Last update Sun May 14 02:44:29 2017 Adam Akkari
//

#include "Scene.hh"
#include "RessourcesLocator.hh"

Scene::Scene(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver)
  : _sceneManager(device->getSceneManager()), _driver(driver)
{
  RessourcesLocator::setSceneManager(_sceneManager);
  RessourcesLocator::setVideoDriver(_driver);
}

void	Scene::update()
{
  _driver->beginScene(true, true, irr::video::SColor(0, 255, 255, 255));

  //update les gameObjects
  
  _sceneManager->drawAll();
  _driver->endScene();
}

Scene::~Scene()
{
  RessourcesLocator::setSceneManager(nullptr);
}
