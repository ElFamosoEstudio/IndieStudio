//
// registerAllContexts.hpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed Jun 14 03:59:36 2017 Noam Silvy
// Last update Thu Jun 15 16:48:47 2017 Noam Silvy
//

#include "ecs.hpp"
#include "engine.hpp"
#include "EContext.hpp"
#include "ESystem.hpp"

void		indie::context::registerAllContexts()
{
  indie::engine::contextManager().registerContext(MAIN_MENU, {{indie::system::INPUT, true}});
}
