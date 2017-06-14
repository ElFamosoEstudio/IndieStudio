//
// registerAllContexts.hpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed Jun 14 03:59:36 2017 Noam Silvy
// Last update Wed Jun 14 13:58:52 2017 Noam Silvy
//

#include "ecs.hpp"
#include "EContext.hpp"

namespace indie
{
  namespace context
  {
    void		registerAllContexts()
    {
      engine::contextManager().registerContext(MAIN_MENU, {{system::INPUT, true}});
    }
  }
}
