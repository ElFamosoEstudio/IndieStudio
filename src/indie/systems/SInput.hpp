//
// SInput.hpp for  in /home/abd-al_a/rendu/IndieStudio
// 
// Made by akram abd-ali
// Login   <abd-al_a@epitech.net>
// 
// Started on  Mon Jun 12 20:47:37 2017 akram abd-ali
// Last update Mon Jun 12 23:29:08 2017 akram abd-ali
//

#ifndef INPUT_SYSTEM_HPP
# define INPUT_SYSTEM_HPP

# include <cstddef>
# include <map>
# include <iostream>
# include "InputReceiver.hpp"
# include "EventManager.hpp"
# include "ISystem.hpp"

namespace	ecs
{
  namespace	system
  {
    class	        Input : public ISystem
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
      SysType	type()
      {
	static const SysType TYPE = 1;
	return TYPE;
      }
      static ISystem	*create()
      {
	return new Input;
      }
    };
  }
}

#endif // !INPUT_SYSTEM_HPP
