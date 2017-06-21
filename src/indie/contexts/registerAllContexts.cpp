//
// registerAllContexts.hpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed Jun 14 03:59:36 2017 Noam Silvy
// Last update Wed Jun 21 17:47:19 2017 akram abd-ali
//

#include "ecs.hpp"
#include "engine.hpp"
#include "context.hpp"
#include "system.hpp"

void		indie::context::registerAllContexts()
{
  indie::engine::contextManager().registerContext(SUB_MENU, {{indie::system::SUB_MENU, true},
	{indie::system::MAIN_MENU, false}});
  indie::engine::contextManager().registerContext(MAIN_MENU, {{indie::system::MAIN_MENU, true}});
  indie::engine::contextManager().registerContext(OVER_MENU, {{indie::system::OVER_MENU, true}});

  ecs::Context	game = {
    {indie::system::SUB_MENU, false},
    {indie::system::INPUT, true},
    {indie::system::COLLISION, true},
    {indie::system::ANIMATION, true},
    {indie::system::MESH_RENDERER, true},
    {indie::system::CAMERA_SYSTEM, true},
    {indie::system::MAP_GENERATOR, true},
    {indie::system::SPAWN, true},
    {indie::system::BOMB, true},
    {indie::system::EXPLOSION, true},
    {indie::system::MOVEMENT, true},
    {indie::system::SYSTIME, true},
    {indie::system::DIE, true},
    {indie::system::BONUS_SYSTEM, true}
  };

  indie::engine::contextManager().registerContext(GAME, game);
}
