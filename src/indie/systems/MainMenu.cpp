//
// Menu.cpp for indie in /home/bento/tek2/IndieStudio/src/indie
//
// Made by Bento
// Login   <bento@epitech.net>
//
// Started on  Wed Jun 14 01:47:29 2017 Bento
// Last update Wed Jun 21 17:56:04 2017 akram abd-ali
//

#include "indie.hpp"
#include "MainMenu.hpp"

using namespace indie::system;

MainMenu::MainMenu(void)
{
  _env = indie::gfx::device()->getGUIEnvironment();
  _tex.push_back(indie::gfx::videoDriver()->getTexture("./img/mexi.jpg"));
  _tex.push_back(indie::gfx::videoDriver()->getTexture("./img/play.png"));
  _tex.push_back(indie::gfx::videoDriver()->getTexture("./img/option.png"));
  _tex.push_back(indie::gfx::videoDriver()->getTexture("./img/ex.png"));
  _env->addImage(_tex[0], core::position2d<int>(0,0));
  _btn.push_back(this->addButton(750, 215, 1130, 295));
  _btn[0]->setImage(_tex[1]);
  _btn.push_back(this->addButton(770, 400, 1120, 485));
  _btn[1]->setImage(_tex[2]);
  _btn.push_back(this->addButton(755, 605, 1130, 685));
  _btn[2]->setImage(_tex[3]);
  _env->drawAll();
}

MainMenu::~MainMenu()
{

}

IGUIButton	*MainMenu::addButton(int x1, int y1, int x2, int y2)
{
  return (_env->addButton(rect<s32>(x1, y1, x2, y2), 0, 0, NULL, NULL));
}

void		MainMenu::update(void)
{
  if (_btn[0]->isPressed())
    indie::engine::contextManager().push(indie::context::SUB_MENU);
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
