//
// EContext.hpp for indie studio in /home/silvy_n/projects/IndieStudio
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Wed Jun 14 13:56:47 2017 Noam Silvy
// Last update Thu Jun 15 13:09:16 2017 Noam Silvy
//

#ifndef ECONTEXT_HPP
# define ECONTEXT_HPP

namespace indie
{
  namespace context
  {
    enum Econtext
      {
	SPLASH_SCREEN,
	MAIN_MENU,
	GAME,
	PAUSE_MENU
      };

    void	registerAllContexts();
  }
}

#endif //!ECONTEXT_HPP