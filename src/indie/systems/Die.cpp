//
// Die.cpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Tue Jun 20 19:29:34 2017 akram abd-ali
// Last update Tue Jun 20 20:32:50 2017 akram abd-ali
//

#include "Die.hpp"

void	indie::system::Die::crateToBonus(ecs::Entity entity)
{
  auto		&crate = indie::engine::entityManager().getComponent<component::TagCrate>(entity);
  std::cout << "Destroyed crate" << std::endl;
  if (!crate)
    return ;
  std::cout << "Destroyed crate" << std::endl;
}

indie::system::Die::Die()
{
  auto key = engine::eventManager().
    subscribe(event::HIT, &indie::system::Die::crateToBonus, this);
  _eventKeys[event::HIT] = key;
}

void	indie::system::Die::update()
{
  
}

ecs::SysType	indie::system::Die::type() const
{
  return (system::DIE);
}

ecs::ISystem	*indie::system::Die::create()
{
  return new Die;
}
