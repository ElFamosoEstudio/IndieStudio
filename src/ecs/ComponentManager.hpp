//
// ComponentManager.hpp for IndieStudio in /home/silvy_n/projects/IndieStudio/src/ecs
//
// Made by Noam Silvy
// Login   <silvy_n@epitech.net>
//
// Started on  Thu May 25 18:46:02 2017 Noam Silvy
// Last update Fri May 26 11:53:15 2017 Noam Silvy
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
        ComponentManager() {}

//        template<typename T>
//         void lol()
//         {
//         	::CVelocity &vel = std::get<0>(_components)[0];
//         	std::cout << vel.velocity << std::endl;
//         }
    private:
        std::tuple<std::map<Entity, CompTypes>...> _components;
    };
}

#endif //INDIESTUDIO_COMPONENTMANAGER_HPP
