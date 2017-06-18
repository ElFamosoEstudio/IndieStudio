//
// LuaScript.hpp for  in /home/julien/C++/IndieStudio/src/indie/components
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sat Jun 17 21:33:38 2017 julien
// Last update Sun Jun 18 20:50:57 2017 Adam Akkari
//

#ifndef LUASCRIPT_HPP
# define LUASCRIPT_HPP

# include <lua.hpp>
# include <iostream>

namespace indie
{
  namespace component
  {
    struct LuaScript
    {
      LuaScript() = default;
      lua_State		*L;
      std::string	function = "ai";
      std::string	filepath = "LuaSCript/ai.lua";
    };
  }
}

#endif // LUASCRIPT_HPP
