#pragma once

# include <irrlicht.h>
# include <array>
# include "ecs.hpp"

using namespace irr;
using namespace gui;
using namespace video;
using namespace core;

namespace indie
{
  namespace system
  {
    class OverMenu : public ecs::ISystem
    {
      std::array<IGUIImage*, 1>		_txt;
      std::array<IGUIButton*, 2>	_btn;
      IGUIEnvironment			*_env;
    public:
      OverMenu();
      ~OverMenu();
      IGUIButton	*addButton(int, int, int, int);
      void		update() override;
      ecs::SysType	type(void) const override;
      static ISystem	*create();
    };
  }
}
