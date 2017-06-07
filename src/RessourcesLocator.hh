//
// RessourcesLocator.hh for bomberman in /home/akkari_a/work/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 00:46:21 2017 Adam Akkari
// Last update Wed Jun  7 10:10:34 2017 Adam Akkari
//

#ifndef RESSOURCESLOCATOR
# define RESSOURCESLOCATOR

# include <ISceneManager.h>
# include <IVideoDriver.h>
# include "Scene.hh"

class	RessourcesLocator
{
private:
  static irr::scene::ISceneManager	*_sceneManager;
  static irr::video::IVideoDriver	*_videoDriver;
  static Scene				*_scene;

public:
  static irr::scene::ISceneManager	*getSceneManager();
  static irr::video::IVideoDriver	*getVideoDriver();
  static Scene				*getScene();
  static void				setSceneManager(irr::scene::ISceneManager *scene);
  static void				setVideoDriver(irr::video::IVideoDriver *driver);
  static void				setScene(Scene *scene);
};

#endif //RESSOURCESLOCATOR
