//
// ASystem.hpp for indie in /home/silvy_n/projects/IndieStudio/src/indie/systems
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Sun Jun 18 20:33:32 2017 Noam Silvy
// Last update Sun Jun 18 21:10:40 2017 Noam Silvy
//

#ifndef ASYSTEM_HPP
# define ASYSTEM_HPP

# include <unordered_map>
# include "ISystem.hpp"
# include "engine.hpp"

namespace indie
{
  namespace system
  {
    class ASystem : public ecs::ISystem
    {
    protected:
      std::unordered_map<ecs::EventTypeDefault, ecs::EventKey>	_eventKeys;
    public:
      virtual void			update() = 0;
      virtual ecs::SysType		type() const = 0;
      virtual void			unsubscribe()
      {
        for (auto const& key : _eventKeys)
          indie::engine::eventManager().unsubscribe(key.first, key.second);
      }
    };
  }
}

#endif //!ASYSTEM_HPP
