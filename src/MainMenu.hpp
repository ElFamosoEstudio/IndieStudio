//
// Menu.hpp for indie in /home/bento/tek2/IndieStudio/src/indie
//
// Made by Bento
// Login   <bento@epitech.net>
//
// Started on  Wed Jun 14 01:23:35 2017 Bento
// Last update Sun Jun 18 18:32:13 2017 Bento
//

#pragma once

# include <irrlicht.h>
# include <iostream>
# include <list>
# include "ecs.hpp"

using namespace irr;
using namespace gui;
using namespace video;
using namespace core;

namespace indie
{
  namespace system
  {
    class MainMenu : public ecs::ISystem
    {
      IGUIEnvironment		*_env;
      IGUISkin			*_skin;
      std::vector<IGUIButton *>	_btn;
      std::vector<ITexture *>	_tex;
    public:
      MainMenu();
      ~MainMenu();
      static ISystem	*create();
      virtual void	update(void) override;
      ecs::SysType	type(void) const override;
      IGUIButton	*addButton(int, int, int, int);
    };
  };
};
