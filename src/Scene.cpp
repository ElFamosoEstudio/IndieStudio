//
// Scene.cpp for bomberman in /home/akkari_a/work/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 01:18:50 2017 Adam Akkari
// Last update Mon May 15 00:17:00 2017 Adam Akkari
//

#include <algorithm>
#include "Scene.hh"
#include "RessourcesLocator.hh"

Scene::Scene(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver)
  : _sceneManager(device->getSceneManager()), _driver(driver)
{
  RessourcesLocator::setSceneManager(_sceneManager);
  RessourcesLocator::setVideoDriver(_driver);
  RessourcesLocator::setScene(this);
}

void	Scene::addGameObject(GameObject *obj)
{
  _objects.push_back(obj);
}

void	Scene::removeGameObject(GameObject *obj)
{
  _objects.erase(std::find(_objects.begin(), _objects.end(), obj));
}

void	Scene::addRenderer(Renderer *rdr)
{
  _renderers.push_back(rdr);
}

void	Scene::removeRenderer(Renderer *rdr)
{
  _renderers.erase(std::find(_renderers.begin(), _renderers.end(), rdr));
}

void	Scene::update()
{
  _driver->beginScene(true, true, irr::video::SColor(0, 255, 255, 255));

  for (auto idx:_renderers)
    idx->update();
  for (auto idx:_objects)
    idx->update();
  
  _sceneManager->drawAll();
  _driver->endScene();
}

Scene::~Scene()
{
  RessourcesLocator::setSceneManager(nullptr);
  RessourcesLocator::setScene(nullptr);
}
