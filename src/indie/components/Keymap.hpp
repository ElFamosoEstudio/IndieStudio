//
// Keymap.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/components
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 21:05:04 2017 Noam Silvy
// Last update Sat Jun 17 00:55:37 2017 Noam Silvy
//

#ifndef KEYMAP_HPP
# define KEYMAP_HPP

# include <map>
# include <stack>
# include "irrlicht.h"
# include "InputReceiver.hpp"

namespace indie
{
  namespace component
  {
    enum class KeymapState
      {
	BLOCK,
	NORMAL,
	NON_BLOCK
      };

    struct KeyboardKeymap
    {
      std::vector<std::multimap<irr::EKEY_CODE,
				InputReceiver::InputState,
				event::EEvent>>		keymap;
    };

    template<typename Keymap>
    struct Keymaps
    {
      std::stack<std::pair<Keymap, KeymapState>>	keymaps;
    };
  }
}

#endif KEYMAP_HPP
