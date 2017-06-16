//
// Keymap.hpp for indie studio in /home/silvy_n/projects/IndieStudio/src/indie/components
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Fri Jun 16 21:05:04 2017 Noam Silvy
// Last update Fri Jun 16 21:07:21 2017 Noam Silvy
//

#ifndef KEYMAP_HPP
# define KEYMAP_HPP

# include <stack>

namespace indie
{
  namespace component
  {
    struct Keymap
    {
      std::map<>
    };

    struct Keymaps
    {
      std::stack<Keymap>	keymaps;
    };
  }
}

#endif KEYMAP_HPP
