//
// context.hpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed Jun 14 13:56:47 2017 Noam Silvy
// Last update Thu Jun 15 20:27:19 2017 Noam Silvy
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
