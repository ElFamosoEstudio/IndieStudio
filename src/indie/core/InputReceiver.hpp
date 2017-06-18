//
// InputReceiver.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Sun Jun 11 00:24:41 2017 Noam Silvy
// Last update Fri Jun 16 23:06:42 2017 Noam Silvy
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
  enum class InputState { UP = 0, DOWN, PRESSED, RELEASED };

  class InputReceiver : public irr::IEventReceiver
  {
  public:
    using Keyboard = std::array<InputState, irr::KEY_KEY_CODES_COUNT>;
  private:
    static constexpr float AXE_THRESHOLD = 0.3f;
    static constexpr size_t NUMBER_OF_BUTTONS = irr::SEvent::SJoystickEvent::NUMBER_OF_BUTTONS;
    static constexpr irr::s16 MAX_S16 = std::numeric_limits<irr::s16>::max();

    struct Gamepad
    {
      std::array<InputState, NUMBER_OF_BUTTONS>	buttons;
      irr::u32					oldButtons;
      std::vector<float>			axes;
      void update(irr::u32 axes);
    };

  private:
    irr::IrrlichtDevice				*_device;
    bool					_isBlocked;
    Keyboard					_keyboard;
    std::map<irr::u8, Gamepad>			_gamePads;
    bool					_gamePadsSupported;

  public:
    InputReceiver() = delete;
    InputReceiver(irr::IrrlichtDevice *device);

    void updateGamePads();
    bool OnEvent(irr::SEvent const& event);
    bool isGamePadButtonState(irr::u8 gPID, std::size_t button, InputState state);
    bool isKeyState(std::size_t key, InputState state);
    bool getGamePadAxis(irr::u8 gPID, size_t numAxis, float *axis);
    void enableInputHandling();
    void disableInputHandling();
    void startEventProcess();
    void endEventProcess();
    Keyboard&	getKeyboard();
  private:
    bool _onEventKeyboard(irr::SEvent::SKeyInput const& input);
    void _updateJoystickButtons(irr::SEvent::SJoystickEvent const& event);
    void _updateJoystickAxes(irr::SEvent::SJoystickEvent const& event);
    bool _onEventJoystick(irr::SEvent::SJoystickEvent const& event);
  };
}

#endif //!INPUT_RECEIVER_HPP
