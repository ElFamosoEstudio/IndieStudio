#include <string>
#include <iostream>
#include <tuple>
#include <map>
#include "ComponentManager.hpp"

struct CVelocity {int velocity;};
struct CPosition {int x; int y;};
struct CGraphics {std::string mesh;};

int main()
{
	ecs::ComponentManager<CVelocity, CPosition, CGraphics> manager;
	return 0;
}
