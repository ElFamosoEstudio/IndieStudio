//
// RessourcesLocator.hh for bomberman in /home/akkari_a/work/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 00:46:21 2017 Adam Akkari
// Last update Sun May 14 02:40:14 2017 Adam Akkari
//

#ifndef RESSOURCESLOCATOR
# define RESSOURCESLOCATOR

# include <IVideoDriver.h>
# include <ISceneManager.h>

class	RessourcesLocator
{
private:
  static irr::scene::ISceneManager	*_sceneManager;
  static irr::video::IVideoDriver	*_videoDriver;

public:
  static irr::scene::ISceneManager	*getSceneManager();
  static irr::video::IVideoDriver	*getVideoDriver();
  static void				setSceneManager(irr::scene::ISceneManager *scene);
  static void				setVideoDriver(irr::video::IVideoDriver *driver);
};

#endif //RESSOURCESLOCATOR
