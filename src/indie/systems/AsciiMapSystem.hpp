//
// AsciiMapSystem.hpp for  in /home/julien/C++/IndieStudio/src/indie/systems
// 
// Made by julien
// Login   <julien.montagnat@epitech.eu>
// 
// Started on  Sun Jun 18 18:52:06 2017 julien
// Last update Sun Jun 18 19:58:54 2017 julien
//

#ifndef ASCIIMAPSYSTEM_HPP
# define ASCIIMAPSYSTEM_HPP

# include "ecs.hpp"
# include "indie.hpp"
# include "components.hpp"

namespace indie
{
  namespace systems
  {
    class AsciiMapSystem : ecs::ISystem
    {
    public:
      void			update();
      ecs::SysType	type() const
      {
	return (indie::system::ASCIIMAPSYSTEM);
      }
      ecs::ISystem		*create()
      {
	return new AsciiMapSystem;
      }
    };
  }
}

#endif // ASCIIMAPSYSTEM_HPP
