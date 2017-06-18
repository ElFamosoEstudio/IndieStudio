#include "indie.hpp"
#include "OverMenu.hpp"

using namespace indie::system;

OverMenu::OverMenu()
{
  _btn[0] = this->addButton(0, 0, 200, 50);
  _btn[1] = this->addButton(10, 0, 210, 50);
  _txt[0] = indie::gfx::videoDriver()->getTexture("./img/ctn.jpg");
}

OverMenu::~OverMenu()
{

}

IGUIButton      *OverMenu::addButton(int x1, int y1, int x2, int y2)
{
  return (_env->addButton(rect<s32>(x1, y1, x2, y2), 0, 0, NULL, NULL));
}

void		OverMenu::update()
{

}

ecs::SysType	OverMenu::type() const
{
  return (indie::system::OVER_MENU);
}

ecs::ISystem	*OverMenu::create()
{
  return (new OverMenu);
}
