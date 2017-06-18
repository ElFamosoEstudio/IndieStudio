//
// registerAllContexts.hpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed Jun 14 03:59:36 2017 Noam Silvy
// Last update Sun Jun 18 05:23:14 2017 Noam Silvy
//

#include "ecs.hpp"
#include "engine.hpp"
#include "context.hpp"
#include "system.hpp"

void		indie::context::registerAllContexts()
{
  ecs::Context	main_menu;
  ecs::Context	game = {{indie::system::INPUT, true},
			{indie::system::COLLISION, true},
			{indie::system::MESH_RENDERER, true},
			{indie::system::CAMERA_SYSTEM, true}};

  indie::engine::contextManager().registerContext(MAIN_MENU, main_menu);
  indie::engine::contextManager().registerContext(GAME, game);
}
