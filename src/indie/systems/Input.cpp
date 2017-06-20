//
// Input.cpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/systems
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Sat Jun 17 08:51:46 2017 Noam Silvy
// Last update Tue Jun 20 22:55:53 2017 Noam Silvy
//

#include <memory>
#include "Input.hpp"
#include "indie.hpp"

constexpr float ABS(float value) { return (value > 0. ? value : -(value)); }
constexpr float DEAD_POINT = 0.3;

using namespace indie;
using namespace indie::system;

Input::		Input()
  : _rcvr(std::addressof(engine::inputReceiver()))
{
  for (auto& elem : _gamepad)
    elem = InputState::UP;
}

//----- ISystem Interface -----//

void		Input::update()
{
  auto&		comps = engine::entityManager().getAllComponents<component::KeyMaps>();

  for (auto& comp : comps)
    {
      bool	isGamePad = (comp.second->id != component::KEYBOARD_ID);
      if (isGamePad)
        _updateGamePad(comp.second->id);
      for (auto const& keymap : comp.second->keymaps)
	{
	  bool isAnyMatch = false;
	  for (auto const& eventStateKeys : keymap.first) {
	    bool isMatch = false;
	    for (auto& key : eventStateKeys.second.second) {
	      if (isGamePad)
		isMatch |= (_gamepad[key] == eventStateKeys.second.first);
	      else
		isMatch |= _rcvr->isKeyState(key, eventStateKeys.second.first);
	    }
	    if (isMatch) {
	      isAnyMatch = true;
	      engine::eventManager().emit(eventStateKeys.first, comp.first);
	    }
	  }
	  if (_needToBreak(keymap.second, isAnyMatch))
	    break ;
	}
    }
}

ecs::SysType		Input::type() const { return (INPUT); }

ecs::ISystem*		Input::create() { return (new indie::system::Input); }

//----- Helpers -----//

bool			Input::_needToBreak(component::KeyMapState state, bool isMatch)
{
  bool			ret = false;

  if (state == component::KeyMapState::BLOCK)
    ret = true;
  else if (state == component::KeyMapState::NORMAL)
    {
      if (isMatch)
	ret = true;
      else
	ret = false;
    }
  else if (state == component::KeyMapState::NON_BLOCK)
    ret = false;
  return (ret);
}

indie::InputState	Input::_getAxisInputState(irr::u8	id,
						  std::size_t	idx,
						  bool		isPositive)
{
  float			axis;

  if (!_rcvr->getGamePadAxis(id, idx, &axis))
    return (InputState::UP);
   if (ABS(axis) <= DEAD_POINT)
    return (InputState::UP);
  return ((isPositive && axis > 0) ? InputState::DOWN :
	  ((!isPositive && axis < 0) ? InputState::DOWN : InputState::UP));
}

using namespace indie::component;
void	        Input::_updateGamePad(irr::u8 id)
{
  bool		positive = true;
  std::size_t	i;

  for (i = 0; i < GAMEPAD_BUTTON_COUNT; i++) {
    for (InputState state = InputState::UP; state < InputState::RELEASED;) {
      if (_rcvr->isGamePadButtonState(id, i, state))
	_gamepad[i] = state;
      state = static_cast<InputState>((int)state + 1);
    }
  }
  auto idx = 0;
  for (; i < GAMEPAD_KEYCODE_COUNT; i++) {
    _gamepad[i] = _getAxisInputState(id, idx, positive = !positive);
    if ((i - GAMEPAD_BUTTON_COUNT) % 2 == 1)
      idx += 1;
  }
}
