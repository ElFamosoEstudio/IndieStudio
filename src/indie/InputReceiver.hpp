//
// InputReceiver.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Sun Jun 11 00:24:41 2017 Noam Silvy
// Last update Sun Jun 11 10:50:29 2017 Noam Silvy
//

#ifndef INPUT_RECEIVER_HPP
# define INPUT_RECEIVER_HPP

# include <array>
# include <vector>
# include <utility>
# include <map>
# include <limits>
# include "IrrlichtDevice.h"
# include "IEventReceiver.h"

namespace indie
{
  class InputReceiver : public irr::IEventReceiver
  {
  public:
    enum class InputState { UP = 0, DOWN, PRESSED, RELEASED };
    enum PovDir
      {
	POV_UP,
	POV_DOWN,
	POV_LEFT,
	POV_RIGHT,
	NUMBER_OF_POV
      };
  private:
    static constexpr float AXE_THRESHOLD = 0.05f;
    static constexpr size_t NUMBER_OF_BUTTONS = irr::SEvent::SJoystickEvent::NUMBER_OF_BUTTONS;
    using Keyboard = std::array<InputState, irr::KEY_KEY_CODES_COUNT>;

    struct Gamepad
    {
      std::array<InputState, NUMBER_OF_BUTTONS>	buttons;
      std::array<InputState, NUMBER_OF_POV>	pov;
      std::vector<float>			axes;

      void update(irr::u32 axes);
    };

  private:
    irr::IrrlichtDevice				*_device;
    bool					_isBlocked;
    Keyboard					_keyboard;
    std::map<irr::u8, irr::SJoystickInfo>	_gamePadsInfo;
    std::map<irr::u8, Gamepad>			_gamePads;
    bool					_gamePadsSupported;

  public:
    InputReceiver() = delete;
    InputReceiver(irr::IrrlichtDevice *device);

    void updateGamePads();
    bool OnEvent(irr::SEvent const& event);

  private:
    bool _onEventKeyboard(irr::SEvent::SKeyInput const& input);
    void _updateJoystickButtons(irr::SEvent::SJoystickEvent const& event);
    void _updateJoystickPovNative(irr::SEvent::SJoystickEvent const& event);
    void _updateJoystickPovWithAxes(irr::SEvent::SJoystickEvent const& event);
    void _updateJoystickPov(irr::SEvent::SJoystickEvent const& event);
    void _updateJoystickAxes(irr::SEvent::SJoystickEvent const& event);
    bool _onEventJoystick(irr::SEvent::SJoystickEvent const& event);
  };
}

#endif //!INPUT_RECEIVER_HPP
