//
// Animation.cpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Sun Jun 18 18:38:20 2017 Noam Silvy
// Last update Sun Jun 18 19:18:39 2017 Noam Silvy
//

#include "AnimationSystem.hpp"

indie::system::AnimationSystem()
{
  constexpr const std::array<event::EEvent, 3> events = {
    event::MOVED, event::STOPED, event::BORED
  };
  for (auto const& event : events)
    {
      auto key = engine::eventManager().subscribe(event, [this, event](ecs::Entity id){
	  this->_tasks.push(std::make_pair(event, id));
	});
      _eventKeys.push_back(key);
    }
}

ecs::SysType	indie::system::AnimationSystem::type() { return (system::ANIMATION); }

ecs::ISystem	*indie::system::AnimationSystem::create() { return (new AnimationSystem); }

void		indie::system::AnimationSystem::update()
{
}
