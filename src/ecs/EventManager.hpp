//
// EventManager.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Thu Jun  8 01:13:05 2017 akram abd-ali
// Last update Thu Jun  8 01:22:19 2017 akram abd-ali
//

#ifndef		EVENT_MANAGER_HPP
# define	EVENT_MANAGER_HPP

# include <vector>
# include <map>
# include <functional>
# include <memory>
# include "ecs.hpp"

namespace		ecs
{
  template<typename EventType>
  class			EventManager
  {
    class		Event
    {
    private:
      std::vector<std::function<void(Entity)>> _callbacks;
    public:
      Event() = default;
      Event(std::function<void(Entity)> &&callback) {
	subscribe(std::move(callback));
      }
      ~Event() = default;
      Event(Event const&) = delete;
      Event& operator=(Event const&) = delete;
    public:
      void	callback(Entity id)
      {
	for (auto const& callback : _callbacks)
	  callback(id);
      }
      void	subscribe(std::function<void(Entity)> &&callback)
      {
	_callbacks.push_back(std::forward<std::function<void(Entity)>>(callback));
      }
    };

  private:
    static EventManager* _obj;
    std::map<EventType, std::unique_ptr<Event>> _events;
  public:
    EventManager() = default;
    ~EventManager() = default;
    EventManager(EventManager const&) = delete;
    EventManager& operator=(EventManager const&) = delete;
  public:
    void	emit(EventType const& evName, Entity id = 0)
    {
      auto it = _events.find(evName);
      if (it != _events.end())
	it->second->callback(id);
    }

    void	subscribe(EventType const& evName,
			  std::function<void(Entity)> callback)
    {
      auto it = _events.find(evName);
      if (it != _events.end())
	it->second->subscribe(std::move(callback));
      else
	_events.emplace(std::make_pair(evName,
				       std::make_unique<Event>(std::move(callback))));
    }

    template<typename Type>
    void	subscribe(EventType const& evName,
			  void (Type::*callback)(Entity),
			  Type *that)
    {
      std::function<void(Entity)> func = std::bind(callback,
						     that,
						     std::placeholders::_1);
      subscribe(evName, std::move(func));
    }
  };
}

#endif		// !EVENT_MANAGER_HPP
