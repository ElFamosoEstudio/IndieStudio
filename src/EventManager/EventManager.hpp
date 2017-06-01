//
// EventManager.hpp for IndieStudio in /home/silvy_n/projects/IndieStudio/src/EventManager
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed May 31 17:42:20 2017 Noam Silvy
// Last update Thu Jun  1 06:43:48 2017 Noam Silvy
//

#include <map>
#include <vector>
#include <utility>
#include <memory>
#include <type_traits>

struct Callback
{
public:
  virtual ~Callback() {}
};

template<typename Func>
struct BaseCallback : Callback
{
  Func callback;
  explicit BaseCallback(Func&& f) : callback(std::forward<Func>(f)) {}
};

template<typename EventType>
class EventManager
{
private:
 std::map<EventType, std::vector<std::unique_ptr<Callback>>> _callbacks;

public:
  EventManager() = default;
  ~EventManager() = default;
  EventManager(EventManager const&) = delete;
  EventManager& operator=(EventManager const&) = delete;

  template<typename Func>
  void subscribe(EventType e, Func&& f)
  {
    _callbacks[e].push_back(std::make_unique<BaseCallback<Func>>(std::forward<Func>(f)));
  }

  template<typename ...Args>
  void emit(EventType e, Args&&... args)
  {
    using Func = void(typename std::remove_reference<Args>::type...);

    for (auto const &obj : _callbacks[e]) {
      Callback const &f = *obj;
      auto func = static_cast<BaseCallback<Func> const &>(f);
      // auto callback = static_cast<BaseCallback<Func> const&>(f).callback;
      // func.callback(std::forward<Args>(args)...);
    }
  }
};
