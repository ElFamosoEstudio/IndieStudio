//
// Keymap.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/components
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 21:05:04 2017 Noam Silvy
// Last update Sun Jun 18 12:17:58 2017 Noam Silvy
//

#ifndef KEYMAP_HPP
# define KEYMAP_HPP

# include <cstddef>
# include <map>
# include <vector>
# include <limits>
# include <deque>
# include "irrlicht.h"
# include "InputReceiver.hpp"
# include "event.hpp"

namespace indie
{
  namespace component
  {
    enum class KeyMapState
      {
	BLOCK,
	NORMAL,
	NON_BLOCK
      };

    // Don't change the order!
    enum class GamepadKeyCode
      {
	BUTTON1,
	BUTTON2,
	BUTTON3,
	BUTTON4,
	LB,
	RB,
        LLEFT,
	LRIGHT,
	LUP,
        LDOWN,
	LT,
	RT,
        RLEFT,
	RRIGHT,
	RUP,
        RDOWN,
	COUNT
      };

    constexpr auto GAMEPAD_BUTTON_COUNT = static_cast<std::size_t>(GamepadKeyCode::LLEFT);
    constexpr auto GAMEPAD_KEYCODE_COUNT = static_cast<std::size_t>(GamepadKeyCode::COUNT);

    using KeyType = std::uint32_t;
    using AssStateKeyTypes = std::pair<InputState, std::vector<KeyType>>;
    using AssEventAssStateKeyTypes = std::pair<event::EEvent, AssStateKeyTypes>;
    using KeyMap = std::vector<AssEventAssStateKeyTypes>;

    constexpr static irr::u8 KEYBOARD_ID = -1;

    struct KeyMaps
    {
      std::deque<std::pair<KeyMap, KeyMapState>>	keymaps;
      irr::u8						id;
    };
  }
}

#endif //!KEYMAP_HPP

// component::KeyMaps   mapStack;
// component::KeyMap	map = {{event::GO_RIGHT,
// 				{InputState::DOWN,
// 				 {static_cast<component::KeyType>(component::
// 								  GamepadKeyCode::LRIGHT)}}},
// 			       {event::GO_LEFT,
// 				{InputState::DOWN,
// 				 {static_cast<component::KeyType>(component::
// 								  GamepadKeyCode::LLEFT)}}},
// 			       {event::GO_UP,
// 				{InputState::DOWN,
// 				 {static_cast<component::KeyType>(component::
// 								  GamepadKeyCode::LUP)}}},
// 			       {event::GO_DOWN,
// 				{InputState::DOWN,
// 				 {static_cast<component::KeyType>(component::
// 								  GamepadKeyCode::LDOWN)}}}};

// mapStack.id = 0;
// mapStack.keymaps.push_front({map, indie::component::KeyMapState::NORMAL});
// entityManager.addComponent(id, mapStack);

// std::cout << "CREATED CollisionSystem" << std::endl;
// indie::engine::eventManager().subscribe(indie::event::GO_RIGHT, [](ecs::Entity id){
//     std::cout << "RECEIVED GO_RIGHT from " << id << std::endl;
//   });
// indie::engine::eventManager().subscribe(indie::event::GO_LEFT, [](ecs::Entity id){
//     std::cout << "RECEIVED GO_LEFT from " << id << std::endl;
//   });
// indie::engine::eventManager().subscribe(indie::event::GO_UP, [](ecs::Entity id){
//     std::cout << "RECEIVED GO_UP from " << id << std::endl;
//   });
// indie::engine::eventManager().subscribe(indie::event::GO_DOWN, [](ecs::Entity id){
//     std::cout << "RECEIVED GO_DOWN from " << id << std::endl;
//   });
