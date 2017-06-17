//
// Menu.cpp for indie in /home/bento/tek2/IndieStudio/src/indie
//
// Made by Bento
// Login   <bento@epitech.net>
//
// Started on  Wed Jun 14 01:47:29 2017 Bento
// Last update Sat Jun 17 23:03:47 2017 Bento
//

#include "indie.hpp"
#include "Menu.hpp"

using namespace indie::system;

MainMenu::MainMenu(void)
{
  _env = indie::gfx::device()->getGUIEnvironment();
  _tex.push_back(indie::gfx::videoDriver()->getTexture("./mexi.jpg"));
  _tex.push_back(indie::gfx::videoDriver()->getTexture("./play.png"));
  _tex.push_back(indie::gfx::videoDriver()->getTexture("./option.png"));
  _tex.push_back(indie::gfx::videoDriver()->getTexture("./exit.png"));
  _env->addImage(_tex[0], core::position2d<int>(0,0));
  _btn.push_back(this->addButton(750, 215, 1130, 300));
  _btn[0]->setImage(_tex[1]);
  _btn.push_back(this->addButton(750, 400, 1170, 485));
  _btn[1]->setImage(_tex[2]);
  _btn.push_back(this->addButton(760, 600, 1130, 685));
  _btn[2]->setImage(_tex[3]);
  _skin = _env->getSkin();
  this->setFont(getFont("./myfont.xml"), 0);
}

MainMenu::~MainMenu()
{

}

IrrlichtDevice		*MainMenu::getResizedDevice()
{
  IrrlichtDevice	*nulldevice = createDevice(video::EDT_NULL);

  core::dimension2d<u32> deskres = nulldevice->getVideoModeList()->getDesktopResolution();
  std::cout << deskres.Height << std::endl;
  IrrlichtDevice	*newDevice = createDevice(irr::video::EDT_DIRECT3D9, deskres, 16, false);
  return (newDevice);
}

IGUIFont	*MainMenu::getFont(std::string const&path)
{
  return (_env->getFont(path.c_str()));
}

void     	MainMenu::setFont(IGUIFont *font, short btn)
{
  short		idx;

  if (!font)
    return ;
  idx = 0;
  for (auto const&i: _btn)
    {
      if (idx == btn)
	break;
      idx += 1;
    }
  _btn[idx]->setOverrideFont(font);
  _skin->setFont(font);
}

IGUIButton	*MainMenu::addButton(int x1, int y1, int x2, int y2)
{
  return (_env->addButton(rect<s32>(x1, y1, x2, y2), 0, 0, NULL, NULL));
}

void		MainMenu::update(void)
{
  // this->getResizedDevice();
  if (_btn[0]->isPressed())
    std::cout << "Play" << std::endl;
  if (_btn[2]->isPressed())
    indie::gfx::device()->closeDevice();
  _env->drawAll();
}

ecs::SysType	MainMenu::type(void) const
{
  return (indie::system::MAIN_MENU);
}

ecs::ISystem	*MainMenu::create()
{
  return (new MainMenu);
}
