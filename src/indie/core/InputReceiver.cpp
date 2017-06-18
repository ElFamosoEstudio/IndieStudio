//
// InputReceiver.cpp for indie studio in /home/silvy_n/projects/IndieStudio/src
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Sun Jun 11 10:31:20 2017 Noam Silvy
// Last update Sun Jun 18 07:18:17 2017 Noam Silvy
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
  _device->setEventReceiver(this); // last instruction!
}

void	InputReceiver::Gamepad::update(irr::u32 axes)
{
  this->buttons.fill(InputState::UP);
  this->oldButtons = 0;
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
    for (irr::u32 idx = 0; idx < size; idx++)
      _gamePads[gamePadsInfoArray[idx].Joystick].update(gamePadsInfoArray[idx].Axes);
  }
}

bool	InputReceiver::OnEvent(irr::SEvent const& event)
{
  if (_isBlocked) return false;
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    return (_onEventKeyboard(event.KeyInput));
  else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
	   && (_gamePadsSupported))
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
  for (int i = 0, numAxes = _gamePads[event.Joystick].axes.size(); i < numAxes; ++i) {
    _gamePads[event.Joystick].axes[i] = event.Axis[i] / MAX_S16;
  }
}

bool	InputReceiver::_onEventJoystick(irr::SEvent::SJoystickEvent const& event)
{
  _updateJoystickButtons(event);
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
