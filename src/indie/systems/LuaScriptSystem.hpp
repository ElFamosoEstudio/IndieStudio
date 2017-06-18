//
// LuaScriptSystem.hpp for  in /home/julien/C++/IndieStudio/src/indie/systems
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sat Jun 17 21:41:53 2017 julien
// Last update Sun Jun 18 21:01:31 2017 Adam Akkari
//

#ifndef LUASCRIPT_SYSTEM_HPP
# define LUASCRIPT_SYSTEM_HPP

# include <map>
# include <lua.hpp>
# include "ecs.hpp"
# include "event.hpp"
# include "system.hpp"
# include "engine.hpp"
# include "components.hpp"

namespace indie
{
  namespace system
  {
    class LuaScriptSystem : public ecs::ISystem
    {
    public:
      const std::map<int, indie::event::EEvent> action =
	{
	  {0, indie::event::EEvent::GO_RIGHT},
	  {1, indie::event::EEvent::GO_LEFT},
	  {2, indie::event::EEvent::GO_UP},
	  {3, indie::event::EEvent::GO_DOWN}
	};
      LuaScriptSystem()
      {
	auto &lua_info = engine::entityManager().getAllComponents<indie::component::LuaScript>();

	for (auto const &it : lua_info)
	  {
	    it.second->L = lua_open();
	    luaL_openlibs(it.second->L);
	    luaL_dofile(it.second->L, it.second->filepath.c_str());
	  }
      }
      ~LuaScriptSystem()
      {
	auto &lua_info = engine::entityManager().getAllComponents<indie::component::LuaScript>();
	
	for (auto const &it : lua_info)
	  {
	    lua_close(it.second->L);
	  }
      }
      std::vector<irr::core::vector3df>	getPlayerPos()
      {
	std::vector<irr::core::vector3df>	player;
	auto	&players = engine::entityManager().getAllComponents<indie::component::TagPlayer>();

	for (auto &idx:players)
	  player.push_back
	    (engine::entityManager().getComponent<indie::component::Transform>(idx.first)
	     ->position);
	return (player);
      }
      void		update()
      {
	auto &lua_info = engine::entityManager().getAllComponents<indie::component::LuaScript>();
	auto &map_info = engine::entityManager().getAllComponents<indie::component::MapSettings>();

	if (map_info.size() == 1)
	  for (auto const &it : lua_info)
	    {
	      lua_getglobal(it.second->L, it.second->function.c_str());
	      lua_pushstring(it.second->L, map_info.begin()->second->AsciiMap.c_str());
	      lua_pushnumber(it.second->L, 1);
	      lua_pushnumber(it.second->L, 1);
	      lua_pcall(it.second->L, 3, 1, 0);
	      lua_pop(it.second->L, 3);
	      lua_tointeger(it.second->L, -1);
	    }
	//emit
      }
      ecs::SysType	type() const
      {
	return (indie::system::LUASCRIPT_SYSTEM);
      }
      static ISystem	*create()
      {
	return new LuaScriptSystem;
      }
    };
  }
}

#endif // LUASCRIPT_SYSTEM_HPP
