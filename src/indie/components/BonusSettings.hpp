//
// BonusSettings.hpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/components
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue Jun 20 20:20:47 2017 Adam Akkari
// Last update Wed Jun 21 02:59:18 2017 akram abd-ali
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
	BONUS_SPEED,
	BONUS_RANGE,
	BONUS_POWER,
	BONUS_BOMB	
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
