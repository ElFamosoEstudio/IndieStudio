//
// RessourcesLocator.cpp for bomberman in /home/akkari_a/work/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 01:40:34 2017 Adam Akkari
// Last update Sun May 14 02:42:00 2017 Adam Akkari
//

#include "RessourcesLocator.hh"

irr::scene::ISceneManager	*RessourcesLocator::_sceneManager = nullptr;
irr::video::IVideoDriver	*RessourcesLocator::_videoDriver = nullptr;

irr::scene::ISceneManager	*RessourcesLocator::getSceneManager()
{
  return (_sceneManager);
}

irr::video::IVideoDriver	*RessourcesLocator::getVideoDriver()
{
  return (_videoDriver);
}

void	RessourcesLocator::setSceneManager(irr::scene::ISceneManager *scene)
{
  _sceneManager = scene;
}

void	RessourcesLocator::setVideoDriver(irr::video::IVideoDriver *driver)
{
  _videoDriver = driver;
}
