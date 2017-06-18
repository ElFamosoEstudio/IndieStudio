#include "SubMenu.hpp"

using namespace indie::system;

ecs::ISystem	*SubMenu::create()
{
  return (new SubMenu);
}

ecs::SysType	SubMenu::type(void) const
{
  return (indie::system::SUB_MENU);
}

void		SubMenu::update(void)
{
  _env->drawAll();
}

SubMenu::SubMenu()
{
  ITexture	*text;
  ITexture	*img;
  IGUIButton	*btn;

  _env = indie::gfx::device()->getGUIEnvironment();
  text = indie::gfx::videoDriver()->getTexture("play.png");
  img = indie::gfx::videoDriver()->getTexture("play.jpg");
  _env->addImage(img, core::position2d<int>(0,0));
  btn = this->addButton(0, 0, 40, 40);
  btn->setImage(text);
}

SubMenu::~SubMenu()
{

}
