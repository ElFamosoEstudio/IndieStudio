#include "indie.hpp"
#include "OverMenu.hpp"

using namespace indie::system;

OverMenu::OverMenu()
{
  _env = indie::gfx::device()->getGUIEnvironment();
  ITexture *tex = indie::gfx::videoDriver()->getTexture("./over.jpg");
  IGUIImage *img = _env->addImage(rect<s32>(0,0,1920,1080));
  img->setImage(tex);
  img->setScaleImage(true);
  img->setMaxSize(dimension2d<u32>(1920, 1080));
  img->setAlignment(EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE, EGUIA_SCALE);
  _btn[0] = this->addButton(250, 600, 450, 650);
  _btn[0]->setImage(indie::gfx::videoDriver()->getTexture("./img/ctn.png"));
  _btn[1] = this->addButton(700, 600, 900, 650);
  _btn[1]->setImage(indie::gfx::videoDriver()->getTexture("./img/exit.png"));
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
  if (_btn[0]->isPressed())
    indie::engine::contextManager().push(indie::context::SUB_MENU);
  if (_btn[1]->isPressed())
    indie::gfx::device()->closeDevice();
  _env->drawAll();
}

ecs::SysType	OverMenu::type() const
{
  return (indie::system::OVER_MENU);
}

ecs::ISystem	*OverMenu::create()
{
  return (new OverMenu);
}
