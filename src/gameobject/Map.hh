//
// Map.hh for bomberman in /home/akkari_a/rendu/IndieStudio/src/gameobject
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Wed Jun  7 08:57:20 2017 Adam Akkari
// Last update Wed Jun  7 14:43:03 2017 Adam Akkari
//

#ifndef MAP
# define MAP

# include <vector>
# include "GameObject.hpp"

enum class	Block
{
  EMPTY,
  WALL,
  CRATE
};

class	Map : public GameObject
{
private:
  std::vector<GameObject*>	_objects;
  std::vector<Block>		_map;

public:
  Map(std::string const &name,
      unsigned int size_x,
      unsigned int size_y);
  ~Map();
  virtual void	update();
};

#endif // MAP
