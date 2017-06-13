//
// ecs.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Thu Jun  8 01:13:58 2017 akram abd-ali
// Last update Tue Jun 13 01:51:43 2017 Noam Silvy
//

#ifndef		ECS_HPP
# define	ECS_HPP

# include <cstdint>

namespace	ecs
{
  using Entity = uint32_t;
  using SysType = uint32_t;
  using EventKey = uint32_t;
  using EventTypeDefault = uint32_t;
}

#endif // !ECS_HPP