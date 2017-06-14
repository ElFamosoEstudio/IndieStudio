//
// FeedFactory.cpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/systems
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed Jun 14 02:11:12 2017 Noam Silvy
// Last update Wed Jun 14 02:26:24 2017 Noam Silvy
//

#ifndef FEED_FACTORY_HPP
# define FEED_FACTORY_HPP

#include "engine.hpp"
#include "Input.hpp"

namespace indie
{
  namespace system
  {
    void	feedFactory()
    {
      engine::systemFactory().registerSystem(INPUT, &Input::create);
    }
  }
}

#endif //!FEED_FACTORY_HPP
