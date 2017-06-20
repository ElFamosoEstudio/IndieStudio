//
// BonusSettings.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/components
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue Jun 20 20:20:47 2017 Adam Akkari
// Last update Tue Jun 20 20:25:26 2017 Adam Akkari
//

#ifndef BONUS_SETTINGS_HPP
# define BONUS_SETTINGS_HPP

namespace indie
{
  namespace component
  {
    enum	BonusType
      {
	DEFAULT,
	SPEED,
	RANGE,
	BOMB
      };

    struct BonusSettings
    {
      BonusSettings() = delete;
      BonusSettings(BonusType btype)
	: type(btype)
      {}
      BonusType	type;
    };
  }
}

#endif // BONUS_SETTINGS_HPP
