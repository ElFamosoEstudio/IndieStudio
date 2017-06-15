//
// FeedFactory.cpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/systems
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed Jun 14 02:11:12 2017 Noam Silvy
// Last update Thu Jun 15 20:34:33 2017 Noam Silvy
//

#include "engine.hpp"
#include "system.hpp"
#include "Input.hpp"

void        indie::system::registerAllSystems()
{
  indie::engine::systemManager().registerSystem(indie::system::INPUT, &indie::system::Input::create);
}
