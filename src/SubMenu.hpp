#pragma once

#include "indie.hpp"
#include "MainMenu.hpp"

// using namespace irr;
// using namespace gui;
// using namespace video;
// using namespace core;

namespace indie
{
  namespace system
  {
    class SubMenu : public MainMenu
    {
      IGUIEnvironment	*_env;
    public:
      SubMenu();
      ~SubMenu();
      static ecs::ISystem	*create();
      virtual void		update(void) override;
      ecs::SysType		type(void) const override;
    };
  }
}
