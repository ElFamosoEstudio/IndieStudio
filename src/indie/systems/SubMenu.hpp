#pragma once

#include "indie.hpp"
#include "MainMenu.hpp"

namespace indie
{
  namespace system
  {
    class SubMenu : public ecs::ISystem
    {
      IGUIEnvironment		*_env;
      std::vector<IGUIButton*>	_btn;
      std::vector<IGUIImage*>	_img;
      int			_i;
    public:
      SubMenu();
      ~SubMenu();
      static ecs::ISystem	*create();
      virtual void		update(void) override;
      ecs::SysType		type(void) const override;
      IGUIButton		*addButton(int, int, int, int);
    };
  }
}
