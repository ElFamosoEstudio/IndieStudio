//
// AsciiMapSystem.cpp for  in /home/julien/C++/IndieStudio/src/indie/systems
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 18:59:52 2017 julien
// Last update Sun Jun 18 20:07:56 2017 julien
//

#include <map>
#include "AsciiMapSystem.hpp"

void	indie::systems::AsciiMapSystem::update()
{
  static const std::map<indie::component::element, char> convert =
    {
      {indie::component::element::EMPTY, ' '},
      {indie::component::element::BLOCK, 'X'},
      {indie::component::element::CRATE, '~'},
      {indie::component::element::BOMB, 'O'},
      {indie::component::element::EXPL, '*'}
    };

  auto	&map_info = engine::entityManager().getAllComponents<indie::component::MapSettings>();

  for (auto &it : map_info)
    {
      it.second->AsciiMap.clear();
      for (auto &elem : it.second->map)
	{
	  for (auto &diff : convert)
	    {
	      if (elem.second == diff.first)
		{
		  it.second->AsciiMap += diff.second;
		  break;
		}
	    }
	}
    }
}
