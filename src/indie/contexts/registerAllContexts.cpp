//
// registerAllContexts.hpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed Jun 14 03:59:36 2017 Noam Silvy
// Last update Fri Jun 16 23:57:38 2017 Adam Akkari
//

#include "ecs.hpp"
#include "engine.hpp"
#include "context.hpp"
#include "system.hpp"

void		indie::context::registerAllContexts()
{
  indie::engine::contextManager().registerContext(MAIN_MENU, {{indie::system::COLLISION, true}});
  indie::engine::contextManager().registerContext(GAME,{
      {indie::system::COLLISION, true},
	{indie::system::MESH_RENDERER, true},
	  {indie::system::CAMERA_SYSTEM, true}});
  //TODO: trouver comment indenter ça proprement
}
