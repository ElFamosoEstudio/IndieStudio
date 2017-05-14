//
// Scene.hh for bomberman in /home/akkari_a/work/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 01:15:36 2017 Adam Akkari
// Last update Sun May 14 23:28:36 2017 Adam Akkari
//

#ifndef SCENE
# define SCENE

# include <vector>
# include <ISceneManager.h>
# include <IVideoDriver.h>
# include <IrrlichtDevice.h>
# include "GameObject.hpp"
# include "Renderer.hh"

class	Scene
{
private:
  irr::scene::ISceneManager	*_sceneManager;
  irr::video::IVideoDriver	*_driver;
  std::vector<GameObject*>	_objects;
  std::vector<Renderer*>	_renderers;

public:
  Scene(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver);
  void	addGameObject(GameObject *obj);
  void	removeGameObject(GameObject *obj);
  void	addRenderer(Renderer *rdr);
  void	removeRenderer(Renderer *rdr);
  void	update();
  ~Scene();
};

#endif //SCENE
