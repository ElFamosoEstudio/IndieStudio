//
// BonusSystem.cpp for bomberman in /home/akkari_a/rendu/IndieStudio/src/indie/systems
// 
// Made by Adam Akkari
// Login   <akkari_a@epitech.net>
// 
// Started on  Tue Jun 20 20:52:43 2017 Adam Akkari
// Last update Wed Jun 21 04:41:17 2017 akram abd-ali
//

#include <random>
#include "indie.hpp"
#include "components.hpp"

#include <iostream>

void	indie::system::BonusSystem::addBonus(ecs::Entity entity)
{
  static bool second = false;
  static ecs::Entity player = 0;
  ecs::Entity obj = 0;

  if (second == false)
    {
      player = entity;
      second = true;
      return ;
    }
  obj = entity;
  second = false;
  auto& bonus = engine::entityManager().getComponent<component::BonusSettings>(obj);
  if (!bonus)
    return ;
  std::cout << "yolo" << std::endl;
  auto&	bombInfos = engine::entityManager().getComponent<component::BombInfo>(player);
  auto&	speed = engine::entityManager().getComponent<component::Speed>(player);
  if ((bonus->type == component::BONUS_SPEED) && (speed) && (speed->value <= 0.8))
    speed->value += 0.1;
  if ((bonus->type == component::BONUS_RANGE) && (bombInfos))
    bombInfos->range += 1;
  else if ((bonus->type == component::BONUS_BOMB) && (bombInfos))
    bombInfos->count += 1;
  engine::eventManager().emit(event::REMOVE_SKEL, obj);
  auto& render = engine::entityManager().getComponent<component::Renderer3d>(obj);
  if (render && render->mesh)
    gfx::sceneManager()->addToDeletionQueue(render->mesh);
  engine::entityManager().removeEntity(obj);
}

void	indie::system::BonusSystem::createBonus(ecs::Entity entity)
{
  auto		&ent = indie::engine::entityManager();
  static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  static std::mt19937 gen(seed);
  auto const &crate = ent.getComponent<component::Transform>(entity);
  if (!crate)
    return ;
  if ((gen() % 4) == 0)
    {
      auto n = gen();
      component::Transform t;
      t.scale.X = 0.45;
      t.scale.Y = 0.45;
      t.scale.Z = 0.45;
      t.position.X = crate->position.X;
      t.position.Y = crate->position.Y;
      t.position.Z = crate->position.Z;
    
      ecs::Entity bonus = ent.create(entity::BONUS,
    				     component::Transform(t));
      if ((n % 3) == 2)
    	{
	  ent.addComponentEmplace<component::Renderer3d>(bonus, "gfx/cube1.obj", "gfx/extra_speed.jpg");
    	  ent.addComponentEmplace<component::BonusSettings>(bonus, component::BONUS_SPEED);
    	}
      else if ((n % 3) == 1)
    	{
	  ent.addComponentEmplace<component::Renderer3d>(bonus, "gfx/cube1.obj", "gfx/extra_range.jpg");
    	  ent.addComponentEmplace<component::BonusSettings>(bonus, component::BONUS_RANGE);
    	}
      else
    	{
	  ent.addComponentEmplace<component::Renderer3d>(bonus, "gfx/cube1.obj", "gfx/extra_bomb.jpg");
    	  ent.addComponentEmplace<component::BonusSettings>(bonus, component::BONUS_BOMB);
    	}
      auto &render = ent.getComponent<component::Renderer3d>(bonus);
      if (render)
	{
	  ent.addComponentEmplace<component::Skeleton>(bonus, render->mesh);
	  engine::eventManager().emit(event::COL_ADD_ELEM, bonus);
	}
    }
}

void		indie::system::BonusSystem::update()
{
  auto		&bonuses = engine::entityManager().getAllComponents<component::BonusSettings>();
  auto		&transform_cmp = engine::entityManager().getAllComponents<component::Transform>();

  for (auto &idx:bonuses)
    {
      if (transform_cmp.find(idx.first) != transform_cmp.end())
  	{
  	  transform_cmp[idx.first]->rotation.Z += 1;
  	}
    }
}

indie::system::BonusSystem::BonusSystem()
{
  auto key = engine::eventManager().
    subscribe(event::CREATE_BONUS, &indie::system::BonusSystem::createBonus, this);
  _eventKeys[event::CREATE_BONUS] = key;
  key = engine::eventManager().
    subscribe(event::COLLIDED, &indie::system::BonusSystem::addBonus, this);
  _eventKeys[event::COLLIDED] = key;
}

ecs::SysType	indie::system::BonusSystem::type() const
{
  return (system::BONUS_SYSTEM);
}

ecs::ISystem	*indie::system::BonusSystem::create()
{
  return (new BonusSystem);
}
