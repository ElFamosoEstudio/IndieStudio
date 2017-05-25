#include <iostream>
#include <tuple>
#include <map>
#include <string>

struct CVelocity {int velocity;};
struct CPosition {int x; int y;};
struct CGraphics {std::string mesh;};

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
		void lol()
		{
			std::get<0>(_components)[0].velocity = 42;
			::CVelocity &vel = std::get<0>(_components)[0];
			std::cout << vel.velocity << std::endl;
		}
	private:
		std::tuple<std::map<Entity, CompTypes>...> _components;
	};
}

int main()
{
	ecs::ComponentManager<CVelocity, CPosition, CGraphics> manager;

	manager.lol();
	return 0;
}
