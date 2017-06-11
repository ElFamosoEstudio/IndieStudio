//
// InputReceiver.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Sun Jun 11 00:24:41 2017 Noam Silvy
// Last update Sun Jun 11 08:15:47 2017 Noam Silvy
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
      std::array<InputState, NUMBER_OF_BUTTONS>		buttons;
      std::array<InputState, NUMBER_OF_POV>		pov;
      std::vector<float>				axes;

      void update(irr::u32 axes)
      {
        this->buttons.fill(InputState::UP);
        this->pov.fill(InputState::UP);
	auto axes_size = static_cast<std::vector<float>::size_type>(axes);
	this->axes.resize(axes_size);
	this->axes.assign(axes_size, 0.0f);
      }
    };

  private:
    irr::IrrlichtDevice				*_device;
    bool					_isBlocked;
    Keyboard					_keyboard;
    std::map<irr::u8, irr::SJoystickInfo>	_gamePadsInfo;
    std::map<irr::u8, Gamepad>			_gamePads;
    bool					_gamePadsSupported;

  public:
    // device must not be null
    InputReceiver(irr::IrrlichtDevice *device)
      : _device(device), _isBlocked(false)
    {
      _keyboard.fill(InputState::UP);
      updateGamePads();
    }

    void updateGamePads()
    {
      irr::core::array<irr::SJoystickInfo>	gamePadsInfoArray;

      if (_gamePadsSupported = _device->activateJoysticks(gamePadsInfoArray)) {
	auto size = gamePadsInfoArray.size();
	_gamePads.clear();
	_gamePadsInfo.clear();
	for (irr::u32 idx = 0; idx < size; idx++) {
	  _gamePadsInfo[gamePadsInfoArray[idx].Joystick] = gamePadsInfoArray[idx];
	  _gamePads[_gamePadsInfo[idx].Joystick].update(gamePadsInfoArray[idx].Axes);
	}
      }
    }

    bool OnEvent(irr::SEvent const& event)
    {
      if (_isBlocked) return false;
      if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        return (_onEventKeyboard(event.KeyInput));
      else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT)
        return (_onEventJoystick(event.JoystickEvent));
      return (false);
    }

  private:
    bool _onEventKeyboard(irr::SEvent::SKeyInput const& input)
    {
      if (input.PressedDown)
	_keyboard[input.Key] = ((_keyboard[input.Key] != InputState::DOWN) ?
					 InputState::PRESSED : InputState::DOWN);
      else if (_keyboard[input.Key] != InputState::UP)
	_keyboard[input.Key] = InputState::RELEASED;
      return (true);
    }

    bool _onEventJoystick(irr::SEvent::SJoystickEvent const& event)
    {
      _updateJoystickButtons(event);
      _updateJoystickPov(event);
      _updateJoystickAxes(event);
      return (true);
    }

    void _updateJoystickButtons(irr::SEvent::SJoystickEvent const& event)
    {
      auto buttons = event.ButtonStates;

      for (auto i = 0; i < NUMBER_OF_BUTTONS; i++)
	{
	  auto& gamePadButtons = _gamePads[event.Joystick].buttons;
	  if (buttons & (1 << i))
	    gamePadButtons[i] = (gamePadButtons[i] != InputState::DOWN) ?
	      InputState::PRESSED : InputState::DOWN;
	  else if (gamePadButtons[i] != InputState::UP)
	    gamePadButtons[i] = InputState::RELEASED;
	}
    }
    void _updateJoystickPov(irr::SEvent::SJoystickEvent const& event)
    {
      auto const&	info = _gamePadsInfo[event.Joystick];

      if (info.PovHat == irr::SJoystickInfo::POV_HAT_PRESENT
	  && event.POV != std::numeric_limits<decltype(event.POV)>::max())
	_updateJoystickPovNative(event);
      else if (info.PovHat == irr::SJoystickInfo::POV_HAT_UNKNOWN)
	_updateJoystickPovWithAxes(event);
    }

    void _updateJoystickPovNative(irr::SEvent::SJoystickEvent const& event)
    {
      static const std::vector<std::pair<PovDir, std::pair<irr::u16, irr::u16>>> angles{
        {POV_UP, {0, 45}},
        {POV_UP, {315, 360}},
        {POV_DOWN, {135, 225}},
        {POV_LEFT, {45, 135}},
        {POV_RIGHT, {225, 315}}
      };
      irr::u16		angle;

      angle = event.POV / 100;
      for (auto const& dir : angles)
	if (angle >= dir.second.first
	    && angle < dir.second.second)
	  _gamePads[event.Joystick].pov[dir.first] = InputState::DOWN;
    }

    void _updateJoystickPovWithAxes(irr::SEvent::SJoystickEvent const& event)
    {
      static constexpr irr::s16 MAX_S16 = std::numeric_limits<irr::s16>::max();
      float axis_x = event.Axis[irr::SEvent::SJoystickEvent::AXIS_U] /
	static_cast<float>(MAX_S16);
      float axis_y = event.Axis[irr::SEvent::SJoystickEvent::AXIS_V] /
	static_cast<float>(MAX_S16);

      if (axis_x > AXE_THRESHOLD)
	_gamePads[event.Joystick].pov[POV_RIGHT] = InputState::DOWN;
      else if (axis_x < -(AXE_THRESHOLD))
	_gamePads[event.Joystick].pov[POV_LEFT] = InputState::DOWN;
      if (axis_y > AXE_THRESHOLD)
	_gamePads[event.Joystick].pov[POV_UP] = InputState::DOWN;
      else if (axis_y < -(AXE_THRESHOLD))
	_gamePads[event.Joystick].pov[POV_DOWN] = InputState::DOWN;
    }

    void _updateJoystickAxes(irr::SEvent::SJoystickEvent const& event)
    {

    }

  };
}

#endif //!INPUT_RECEIVER_HPP
