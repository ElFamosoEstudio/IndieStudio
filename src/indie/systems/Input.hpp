//
// Input.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/systems
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Sat Jun 17 08:51:52 2017 Noam Silvy
// Last update Sun Jun 18 01:53:13 2017 Noam Silvy
//

#ifndef INPUT_SYSTEM_HPP
# define INPUT_SYSTEM_HPP

# include <array>
# include "irrlicht.h"
# include "ecs.hpp"
# include "InputReceiver.hpp"
# include "Keymap.hpp"

namespace indie
{
  namespace system
  {
    class Input : public ecs::ISystem
    {
    public:
      using GamePadArray = std::array<InputState, component::GAMEPAD_KEYCODE_COUNT>;
    private:
      GamePadArray	_gamepad;
      InputReceiver	*_rcvr;
    public:
      Input();
      ~Input() = default;
      Input(Input const&) = delete;
      Input& operator=(Input const&) = delete;

      void		update() override;
      ecs::SysType	type() const override;
      static ISystem	*create();

    private:
      void		_updateGamePad(irr::u8 id);
      InputState	_getAxisInputState(irr::u8	id,
					   std::size_t	idx,
					   bool		isPositive);
      bool		_needToBreak(component::KeyMapState state, bool isMatch);
    };
  }
}

#endif //!INPUT_SYSTEM_HPP
