//
// InputReceiver.cpp for indie studio in /home/silvy_n/projects/IndieStudio/src
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Sun Jun 11 10:31:20 2017 Noam Silvy
// Last update Wed Jun 14 01:48:01 2017 Noam Silvy
//

#include <unistd.h>
#include <iostream>
#include "InputReceiver.hpp"

using namespace indie;

InputReceiver::InputReceiver(irr::IrrlichtDevice *device)
  : _device(device), _isBlocked(false)
{
  _keyboard.fill(InputState::UP);
  updateGamePads();
  device->setEventReceiver(this); // last instruction!
}

void	InputReceiver::Gamepad::update(irr::u32 axes)
{
  this->buttons.fill(InputState::UP);
  this->oldButtons = 0;
  this->pov.fill(InputState::UP);
  auto axes_size = static_cast<std::vector<float>::size_type>(axes);
  this->axes.resize(axes_size);
  this->axes.assign(axes_size, 0.0f);
}

void	InputReceiver::updateGamePads()
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

bool	InputReceiver::OnEvent(irr::SEvent const& event)
{
  if (_isBlocked) return false;
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    return (_onEventKeyboard(event.KeyInput));
  else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT)
    return (_onEventJoystick(event.JoystickEvent));
  return (false);
}

bool	InputReceiver::_onEventKeyboard(irr::SEvent::SKeyInput const& input)
{
  if (input.PressedDown)
    _keyboard[input.Key] = ((_keyboard[input.Key] != InputState::DOWN) ?
			    InputState::PRESSED : InputState::DOWN);
  else if (_keyboard[input.Key] != InputState::UP)
    _keyboard[input.Key] = InputState::RELEASED;
  return (true);
}

void	InputReceiver::_updateJoystickButtons(irr::SEvent::SJoystickEvent const& event)
{
  irr::u32 buttons = event.ButtonStates;

  if (buttons == _gamePads[event.Joystick].oldButtons)
    return ;
  _gamePads[event.Joystick].oldButtons = buttons;
  auto& gamePadButtons = _gamePads[event.Joystick].buttons;
  for (auto i = 0; i < NUMBER_OF_BUTTONS; i++)
    {
      if (buttons & (1 << i))
  	gamePadButtons[i] = (gamePadButtons[i] != InputState::DOWN) ?
  	  InputState::PRESSED : InputState::DOWN;
      else if (gamePadButtons[i] != InputState::UP)
  	gamePadButtons[i] = InputState::RELEASED;
    }
}

void	InputReceiver::_updateJoystickAxes(irr::SEvent::SJoystickEvent const& event)
{
  for (int i = 0, numAxes = 8; i < numAxes; ++i)
    _gamePads[event.Joystick].axes[i] = event.Axis[i] / MAX_S16;
}

bool	InputReceiver::_onEventJoystick(irr::SEvent::SJoystickEvent const& event)
{
  _updateJoystickButtons(event);
  // _updateJoystickPov(event);
  _updateJoystickAxes(event);
  return (true);
}

bool InputReceiver::isKeyState(std::size_t key, InputState state)
{
  if (key >= irr::KEY_KEY_CODES_COUNT)
    return (false);
  return (_keyboard[key] == state);
}

bool InputReceiver::isGamePadButtonState(irr::u8 gPID, std::size_t button, InputState state)
{
  if (button >= NUMBER_OF_BUTTONS)
    return (false);
  auto const& it = _gamePads.find(gPID);
  if (it == _gamePads.end())
    return (false);
  return ((it->second).buttons[button] == state);
}

bool InputReceiver::getGamePadAxis(irr::u8 gPID, size_t numAxis, float *axis)
{
  auto const& it = _gamePads.find(gPID);
  if (it == _gamePads.end())
    return (false);
  if (numAxis >= (it->second).axes.size())
    return (false);
  *axis = (it->second).axes[numAxis];
  return (true);
}

indie::InputReceiver::Keyboard&	InputReceiver::getKeyboard()
{
  return _keyboard;
}

void indie::InputReceiver::enableInputHandling()
{
  for (int i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
    {
      if (_keyboard[i] == InputState::RELEASED)
	_keyboard[i] = InputState::UP;
      if (_keyboard[i] == InputState::PRESSED)
	_keyboard[i] = InputState::DOWN;
    }
  for (auto& elem : _gamePads)
    {
      auto& gamePad = elem.second.buttons;
      for (int i = 0; i < NUMBER_OF_BUTTONS; ++i)
	{
	  if (gamePad[i] == InputState::RELEASED)
	    gamePad[i] = InputState::UP;
	  if (gamePad[i] == InputState::PRESSED)
	    gamePad[i] = InputState::DOWN;
	}
    }
  _isBlocked = false;
}

void indie::InputReceiver::disableInputHandling()
{
  _isBlocked = true;
}

void	InputReceiver::_updateJoystickPovNative(irr::SEvent::SJoystickEvent const& event)
{
  // static const std::vector<std::pair<PovDir, std::pair<irr::u16, irr::u16>>> angles{
  //   {POV_UP, {0, 45}},
  //   {POV_UP, {315, 360}},
  //   {POV_DOWN, {135, 225}},
  //   {POV_LEFT, {45, 135}},
  //   {POV_RIGHT, {225, 315}}
  // };
  // irr::u16		angle;

  // angle = event.POV / 100;
  // for (auto const& dir : angles)
  //   if (angle >= dir.second.first
  // 	&& angle < dir.second.second)
  //     _gamePads[event.Joystick].pov[dir.first] = InputState::DOWN;
}

void	InputReceiver::_updateJoystickPovWithAxes(irr::SEvent::SJoystickEvent const& event)
{
  // static constexpr irr::s16 MAX_S16 = std::numeric_limits<irr::s16>::max();
  // float axis_x = event.Axis[irr::SEvent::SJoystickEvent::AXIS_U] /
  //   static_cast<float>(MAX_S16);
  // float axis_y = event.Axis[irr::SEvent::SJoystickEvent::AXIS_V] /
  //   static_cast<float>(MAX_S16);

  // if (axis_x > AXE_THRESHOLD)
  //   _gamePads[event.Joystick].pov[POV_RIGHT] = InputState::DOWN;
  // else if (axis_x < -(AXE_THRESHOLD))
  //   _gamePads[event.Joystick].pov[POV_LEFT] = InputState::DOWN;
  // if (axis_y < -(AXE_THRESHOLD))
  //   _gamePads[event.Joystick].pov[POV_UP] = InputState::DOWN;
  // else if (axis_y > AXE_THRESHOLD)
  //   _gamePads[event.Joystick].pov[POV_DOWN] = InputState::DOWN;
}

void	InputReceiver::_updateJoystickPov(irr::SEvent::SJoystickEvent const& event)
{
  // auto const&	info = _gamePadsInfo[event.Joystick];

  // if (info.PovHat == irr::SJoystickInfo::POV_HAT_PRESENT
  //     && event.POV != std::numeric_limits<decltype(event.POV)>::max())
  //   _updateJoystickPovNative(event);
  // else if (info.PovHat == irr::SJoystickInfo::POV_HAT_UNKNOWN)
  //   _updateJoystickPovWithAxes(event);
}
