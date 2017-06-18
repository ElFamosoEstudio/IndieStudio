//
// AsciiMapSystem.cpp for  in /home/julien/C++/IndieStudio/src/indie/systems
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 18:59:52 2017 julien
// Last update Sun Jun 18 19:24:46 2017 julien
//

#include <map>
#include "AsciiMapSystem.hpp"

void	indie::system::udpate()
{
  static constexpr std::map<indie::component::element, char> convert =
    {
      {indie::component::element::EMPTY, ' '},
      {indie::component::element::BLOCK, 'X'},
      {indie::component::element::CRATE, '~'},
      {indie::component::element::BOMB, 'O'},
      {indie::component::element::EXPL, '*'}
    }

  auto	&map_info = engine::entityManager().getComponent<component::MapSettings>(entity);

  for (auto &it : map_info)
    {
      it.clear();
      for (auto &elem : it.map)
	{
	  for (auto &diff : convert)
	    {
	      if (elem.second == diff.first)
		{
		  it.AsciiMap += diff.second;
		  break;
		}
	    }
	}
    }
}
