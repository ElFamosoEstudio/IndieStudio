//
// Scene.hh for bomberman in /home/akkari_a/work/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 01:15:36 2017 Adam Akkari
// Last update Sun May 14 02:38:40 2017 Adam Akkari
//

#ifndef SCENE
# define SCENE

# include <vector>
# include <ISceneManager.h>
# include <IVideoDriver.h>
# include <IrrlichtDevice.h>
# include "GameObject.hpp"

class	Scene
{
private:
  irr::scene::ISceneManager	*_sceneManager;
  irr::video::IVideoDriver	*_driver;
  std::vector<GameObject*>	_objects;

public:
  Scene(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver);
  void	update();
  ~Scene();
};

#endif //SCENE
