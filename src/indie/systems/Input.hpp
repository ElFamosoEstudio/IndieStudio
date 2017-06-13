//
// Input.hpp for  in /home/abd-al_a/rendu/IndieStudio
//
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
//
// Started on  Mon Jun 12 20:47:37 2017 akram abd-ali
// Last update Tue Jun 13 19:19:10 2017 Noam Silvy
//

#ifndef INPUT_SYSTEM_HPP
# define INPUT_SYSTEM_HPP

# include <cstddef>
# include <map>
# include <iostream>
# include "ecs.hpp"
# include "InputReceiver.hpp"
# include "ESystem.hpp"

namespace indie
{
  namespace system
  {
    class Input : public ecs::ISystem
    {
    private:
      indie::InputReceiver	*_receiver;
    public:
      Input() {};
      Input(indie::InputReceiver *receiver) : _receiver(receiver) {}
      ~Input() = default;
      Input(Input const&) = delete;
      Input& operator=(Input const&) = delete;
    public:
      void	update() {
	std::cout << "update input" << std::endl;
      }
      ecs::SysType	type() const
      {
	static const ecs::SysType _TYPE = system::INPUT;
	return _TYPE;
      }
      static ISystem	*create()
      {
	return new Input;
      }
    };
  }
}
#endif // !INPUT_SYSTEM_HPP
