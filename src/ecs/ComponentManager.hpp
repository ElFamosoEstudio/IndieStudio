//
// ComponentManager.hpp for IndieStudio in /home/silvy_n/projects/IndieStudio/src/ecs
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu May 25 18:46:02 2017 Noam Silvy
// Last update Thu May 25 19:26:20 2017 Noam Silvy
//

#ifndef INDIESTUDIO_COMPONENTMANAGER_HPP
# define INDIESTUDIO_COMPONENTMANAGER_HPP

#include <tuple>
#include <map>

namespace ecs
{
	using Entity = std::size_t;

	template<typename ...CompTypes>
	class ComponentManager
	{
	public:
		ComponentManager()
		{
		}
		template<typename T>
		// void lol()
		// {
		// 	std::get<T::TYPE>(_components)[Entity_id].velocity = 42;
		// 	::CVelocity &vel = std::get<0>(_components)[0];
		// 	std::cout << vel.velocity << std::endl;
		// }
	private:
		std::tuple<std::map<Entity, CompTypes>...> _components;
	};
}

ecs::ComponentManager<CVelocity, CPosition, CGraphics> manager;

#endif //INDIESTUDIO_COMPONENTMANAGER_HPP
