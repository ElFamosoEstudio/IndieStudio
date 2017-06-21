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
  if (_btn[4]->isPressed())
    {
      indie::engine::contextManager().pop();
      return ;
    }
  if (_btn[5]->isPressed())
    {
      indie::engine::contextManager().push(indie::context::GAME);
      return ;
    }
  int	j = 0;
  for (auto &i: _btn)
    {
      if (i->isPressed())
	{
	  _i++;
	  if (_i % 2 == 0 && j < 4)
	    {
	      i->setImage(indie::gfx::videoDriver()->getTexture("./img/player.png"));
	      _img[j]->setImage(indie::gfx::videoDriver()->getTexture("./img/boy.png"));
	    }
	  else if (j < 4)
	    {
	      i->setImage(indie::gfx::videoDriver()->getTexture("./img/ia.png"));
	      _img[j]->setImage(indie::gfx::videoDriver()->getTexture("./img/bot.png"));
	    }
	}
      j += 1;
    }
  _env->drawAll();
}

SubMenu::SubMenu()
{
  _env = indie::gfx::device()->getGUIEnvironment();;
  IGUISkin	*skin = _env->getSkin();
  IGUIFont	*font = _env->getFont("myfont.xml");
  if (font)
    skin->setFont(font);
  skin->setFont(_env->getBuiltInFont(), EGDF_TOOLTIP);
  font->draw(L"Choose players and AI's.", rect<s32>(200,200, 200, 200), SColor(255, 255, 255, 255));
  ITexture *tex = indie::gfx::device()->getVideoDriver()
    ->getTexture("./img/tes.jpg");
  IGUIImage *image
    = _env->addImage(rect<s32>(0, 0, 1920, 1080));
  _img.push_back(_env->addImage(rect<s32>(250, 500, 515, 700)));
  _img.push_back(_env->addImage(rect<s32>(650, 500, 910, 700)));
  _img.push_back(_env->addImage(rect<s32>(1050, 500, 1305, 700)));
  _img.push_back(_env->addImage(rect<s32>(1450, 500, 1705, 700)));
  _img[0]->setImage(indie::gfx::device()->getVideoDriver()->getTexture("./img/boy.png"));
  _img[1]->setImage(indie::gfx::device()->getVideoDriver()->getTexture("./img/bot.png"));
  _img[2]->setImage(indie::gfx::device()->getVideoDriver()->getTexture("./img/bot.png"));
  _img[3]->setImage(indie::gfx::device()->getVideoDriver()->getTexture("./img/bot.png"));
  image->setImage(tex);
  image->setScaleImage(true);
  image->setMaxSize(dimension2d<u32>(1920, 1080));
  image->setAlignment(EGUIA_SCALE, EGUIA_SCALE,
                      EGUIA_SCALE, EGUIA_SCALE);
  _btn.push_back(this->addButton(200, 400, 495, 475));
  _btn.push_back(this->addButton(600, 400, 895, 475));
  _btn.push_back(this->addButton(1000, 400, 1295, 475));
  _btn.push_back(this->addButton(1400, 400, 1695, 475));
  _btn.push_back(this->addButton(0, 0, 245, 75));
  _btn.push_back(this->addButton(1300, 800, 1595, 875));
  _btn[0]->setImage(indie::gfx::videoDriver()->getTexture("./img/player.png"));
  _btn[1]->setImage(indie::gfx::videoDriver()->getTexture("./img/ia.png"));
  _btn[2]->setImage(indie::gfx::videoDriver()->getTexture("./img/ia.png"));
  _btn[3]->setImage(indie::gfx::videoDriver()->getTexture("./img/ia.png"));
  _btn[4]->setImage(indie::gfx::videoDriver()->getTexture("./img/back.png"));
  _btn[5]->setImage(indie::gfx::videoDriver()->getTexture("./img/launch.png"));
  _i = 0;
}

SubMenu::~SubMenu()
{
  // _env->clear();
}

IGUIButton	*SubMenu::addButton(int x1, int y1, int x2, int y2)
{
  return (_env->addButton(rect<s32>(x1, y1, x2, y2), 0, 0, NULL, NULL));
}
