//
// init.cpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 04:09:06 2017 Noam Silvy
// Last update Fri Jun 16 04:09:37 2017 Noam Silvy
//

#include "indie.hpp"

void		indie::init()
{
  system::registerAllSystems();
  context::registerAllContexts();
  entity::registerAllEntities();
}
