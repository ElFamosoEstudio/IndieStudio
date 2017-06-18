//
// init.cpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 04:09:06 2017 Noam Silvy
// Last update Sun Jun 18 01:54:53 2017 Noam Silvy
//

#include "engine.hpp"
#include "system.hpp"
#include "context.hpp"
#include "entity.hpp"

void		indie::init()
{
  system::registerAllSystems();
  context::registerAllContexts();
  entity::registerAllEntities();
}
