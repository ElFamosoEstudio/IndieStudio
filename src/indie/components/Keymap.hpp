//
// Keymap.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/components
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 21:05:04 2017 Noam Silvy
// Last update Sun Jun 18 00:51:20 2017 Noam Silvy
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

    enum class GamepadKeyCode
      {
	BUTTON1,
	BUTTON2,
	BUTTON3,
	BUTTON4,
	LB,
	RB,
	HOME,
        LLEFT,
	LRIGHT,
	LUP,
        LDOWN,
	LT,
	RT,
        RLEFT,
	RRIGHT,
	RUP,
        RDOWN
      };

    constexpr auto GAMEPAD_KEYCODE_COUNT = static_cast<
      std::size_t>(std::numeric_limits<GamepadKeyCode>::max());
    constexpr auto GAMEPAD_BUTTON_COUNT = static_cast<std::size_t>(GamepadKeyCode::HOME);

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
