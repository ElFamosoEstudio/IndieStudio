#include "ecs.hpp"
#include "engine.hpp"
#include "context.hpp"
#include "system.hpp"

void		indie::context::registerAllContexts()
{
  indie::engine::contextManager().registerContext(SUB_MENU, {{indie::system::SUB_MENU, true}, {indie::system::MAIN_MENU, false}});
  indie::engine::contextManager().registerContext(MAIN_MENU, {{indie::system::MAIN_MENU, true}});
  indie::engine::contextManager().registerContext(GAME,{
      {indie::system::COLLISION, true},
	{indie::system::MESH_RENDERER, true},
	  {indie::system::CAMERA_SYSTEM, true},
	    {indie::system::MAP_GENERATOR, true}
    });
  //TODO: trouver comment indenter ça proprement
}
