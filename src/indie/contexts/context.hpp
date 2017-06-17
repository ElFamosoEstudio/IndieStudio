//
// context.hpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed Jun 14 13:56:47 2017 Noam Silvy
// Last update Sat Jun 17 05:46:01 2017 Bento
//

#ifndef CONTEXT_HPP
# define CONTEXT_HPP

namespace indie
{
  namespace context
  {
    enum EContext
      {
	SPLASH_SCREEN,
	MAIN_MENU,
	GAME,
	PAUSE_MENU
      };

    void	registerAllContexts();
  }
}

#endif //!CONTEXT_HPP
