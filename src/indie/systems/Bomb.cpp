//
// Bomb.cpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Sat Jun 17 02:28:47 2017 akram abd-ali
// Last update Sat Jun 17 10:41:02 2017 akram abd-ali
//

#include "Bomb.hpp"
#include "Spreadable.hpp"
#include "indie.hpp"

void	indie::system::Bomb::dropBomb(ecs::Entity entity)
{
  auto&	bombInfos = engine::entityManager().getAllComponents<component::BombInfo>();

  for (auto& it : bombInfos)
    {
      auto id = it.first;
      auto& info = it.second;
      auto &timer = engine::entityManager().getComponent<component::Timer>(id);
      if (!timer)
	{
	  engine::entityManager().create(entity::BOMB);
	  // component::Spreadable(info->range, info->propagationMask)
	  info->count -= 1;
	}
    }
}

void	indie::system::Bomb::dropBombErr(ecs::Entity entity)
{

}

indie::system::Bomb::Bomb()
{
  auto key = engine::eventManager().subscribe(event::DROP_BOMB, &indie::system::Bomb::dropBomb, this);
  _subKeys[event::DROP_BOMB] = key;
  key = engine::eventManager().subscribe(event::DROP_BOMB_ERR, &indie::system::Bomb::dropBombErr, this);
  _subKeys[event::DROP_BOMB_ERR] = key;
}

indie::system::Bomb::~Bomb()
{
  for (auto const& it : _subKeys)
    engine::eventManager().unsubscribe(it.first, it.second);
}

void	indie::system::Bomb::update() {

}

ecs::SysType	indie::system::Bomb::type() const
{
  return (system::BOMB);
}

ecs::ISystem	*indie::system::Bomb::create()
{
  return new Bomb;
}
