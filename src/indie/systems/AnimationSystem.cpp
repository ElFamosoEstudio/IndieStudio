//
// Animation.cpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Sun Jun 18 18:38:20 2017 Noam Silvy
// Last update Tue Jun 20 22:31:38 2017 Noam Silvy
//

#include "AnimationSystem.hpp"

indie::system::AnimationSystem::AnimationSystem()
{
  constexpr const std::array<event::EEvent, 3> events = {
    event::MOVED, event::STOPED, event::BORED
  };
  for (auto const& event : events)
    {
      auto key = engine::eventManager().subscribe(event, [this, event](ecs::Entity id){
	  this->_tasks.push(std::make_pair(event, id));
	});
      _eventKeys[event] = key;
    }
}

ecs::SysType	indie::system::AnimationSystem::type() const { return (system::ANIMATION); }

ecs::ISystem	*indie::system::AnimationSystem::create() { return (new AnimationSystem); }

void		indie::system::AnimationSystem::update()
{
  while (!_tasks.empty())
    {
      auto& task = _tasks.front();
      auto& anim = engine::entityManager().getComponent<component::Animation>(task.second);
      auto& rend = engine::entityManager().getComponent<component::Renderer3d>(task.second);
      if (anim && rend) {
        if (rend->mesh->getEndFrame() != anim->cursor[task.first].second)
	  rend->mesh->setFrameLoop(anim->cursor[task.first].first, anim->cursor[task.first].second);
      }
      _tasks.pop();
    }
}
