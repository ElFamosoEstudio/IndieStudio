//
// EventManager.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Thu Jun  8 01:13:05 2017 akram abd-ali
// Last update Thu Jun 15 03:56:20 2017 akram abd-ali
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
  template<typename EventType = EventTypeDefault>
  class EventManager
  {
    class Event
    {
    private:
      std::map<EventKey, std::function<void(Entity)>>	_callbacks;
      EventKey						_nextKey;
    public:
      Event() = default;
      Event(std::function<void(Entity)> &&callback, EventKey& key) {
	key = subscribe(std::move(callback));
      }
      ~Event() = default;
      Event(Event const&) = delete;
      Event& operator=(Event const&) = delete;
    public:
      void	callback(Entity id)
      {
	for (auto const& callback : _callbacks)
	  callback.second(id);
      }
      EventKey	subscribe(std::function<void(Entity)> &&callback)
      {
	_callbacks[_nextKey] = (std::forward<std::function<void(Entity)>>(callback));
	return (_nextKey++);
      }
      void	unsubscribe(EventKey key)
      {
	auto const &it = _callbacks.find(key);
	if (it == _callbacks.end())
	  return ;
	_callbacks.erase(it);
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
      auto const &it = _events.find(evName);
      if (it != _events.end())
	it->second->callback(id);
    }

    EventKey	subscribe(EventType const& evName,
			  std::function<void(Entity)> callback)
    {
      EventKey	key;

      auto const &it = _events.find(evName);
      if (it != _events.end())
	key = it->second->subscribe(std::move(callback));
      else
	_events.emplace(std::make_pair(evName,
				       std::make_unique<Event>(std::move(callback), key)));
      return key;
    }

    template<typename Type>
    EventKey	subscribe(EventType const& evName,
			  void (Type::*callback)(Entity),
			  Type *that)
    {
      std::function<void(Entity)> func = std::bind(callback,
						   that,
						   std::placeholders::_1);
      return subscribe(evName, std::move(func));
    }
    void	unsubscribe(EventType const& evName, EventKey key)
    {
      auto const &it = _events.find(evName);
      if (it == _events.end())
	return ;
      it->second->unsubscribe(key);
    }
  };
}

#endif		// !EVENT_MANAGER_HPP
