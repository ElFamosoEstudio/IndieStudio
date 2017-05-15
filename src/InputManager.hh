//
// InputManager.hh for bomberman in /home/akkari_a/work/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Mon May 15 01:01:07 2017 Adam Akkari
// Last update Mon May 15 16:28:11 2017 Adam Akkari
//

#ifndef INPUTMANAGER
# define INPUTMANAGER

# include <irrlicht.h>
# include <string>
# include <map>

class	InputManager
{
  class	EventReceiver : public irr::IEventReceiver
  {
  private:
    bool	_keyIsDown[irr::KEY_KEY_CODES_COUNT];

  public:
    EventReceiver();
    virtual bool	OnEvent(const irr::SEvent &event);
    virtual bool	isKeyDown(irr::EKEY_CODE keyCode) const;
  };
  
private:
  static std::map<std::string, irr::EKEY_CODE>	_keymap;
  static EventReceiver				*_receiver;

public:
  static void		initialize();
  static EventReceiver	*getReceiver();
  static bool		isKeyDown(std::string const &key);
};

#endif //INPUTMANAGER
