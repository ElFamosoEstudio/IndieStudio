//
// InputManager.hh for bomberman in /home/akkari_a/work/IndieStudio/src
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Mon May 15 01:01:07 2017 Adam Akkari
// Last update Mon May 15 01:17:47 2017 Adam Akkari
//

#ifndef INPUTMANAGER
# define INPUTMANAGER

# include <irrlicht.h>
# include <string>
# include <map>

class	InputManager
{
private:
  static std::map<std::string, irr::EKEY_CODE>	keymap;

public:
  static bool	isKeyDown(std::string const &key);
};

#endif //INPUTMANAGER
