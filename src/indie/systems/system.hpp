//
// system.hpp for indie studio in /home/silvy_n/IndieStudio/src/indie/systems
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu Jun 15 20:29:09 2017 Noam Silvy
// Last update Thu Jun 15 20:29:51 2017 Noam Silvy
//

#ifndef SYSTEM_HPP
# define SYSTEM_HPP

namespace indie
{
  namespace system
  {
    enum ESystem
      {
	INPUT,
	MOVE,
	MAIN_MENU
      };

    void        registerAllSystems();
  }
}

#endif //!SYSTEM_HPP
