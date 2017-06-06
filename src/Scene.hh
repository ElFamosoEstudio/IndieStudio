//
// Scene.hh for bomberman in /home/akkari_a/work/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Sun May 14 01:15:36 2017 Adam Akkari
// Last update Tue Jun  6 10:49:56 2017 Adam Akkari
//

#ifndef SCENE
# define SCENE

# include <vector>
# include <algorithm>
# include <ISceneManager.h>
# include <IVideoDriver.h>
# include <IrrlichtDevice.h>
# include "GameObject.hpp"
# include "Renderer.hh"
# include "BoxCollider.hh"

class	Scene
{
private:
  irr::scene::ISceneManager	*_sceneManager;
  irr::video::IVideoDriver	*_driver;
  std::vector<GameObject*>	_objects;
  std::vector<Renderer*>	_renderers;
  std::vector<BoxCollider*>	_colliders;

public:
  Scene(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver);
  void	addGameObject(GameObject *obj)
  {_objects.push_back(obj);}
  void	removeGameObject(GameObject *obj)
  {_objects.erase(std::find(_objects.begin(), _objects.end(), obj));}
  void	addRenderer(Renderer *rdr)
  {_renderers.push_back(rdr);}
  void	removeRenderer(Renderer *rdr)
  {_renderers.erase(std::find(_renderers.begin(), _renderers.end(), rdr));}
  void	addCollider(BoxCollider *coll)
  {_colliders.push_back(coll);}
  void	removeCollider(BoxCollider *coll)
  {_colliders.erase(std::find(_colliders.begin(), _colliders.end(), coll));}
  std::vector<BoxCollider*> const	&getColliders()
  {return (_colliders);}
  void	update();
  ~Scene();
};

#endif //SCENE
