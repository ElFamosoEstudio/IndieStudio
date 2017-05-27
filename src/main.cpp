#include <string>
#include <iostream>
#include <tuple>
#include <map>
#include "EntityManager.hpp"

struct CVelocity {int velocity;static const ecs::CTypeSize TYPE = 1;};
struct CPosition {int x; int y;static const ecs::CTypeSize TYPE = 4;};
struct CGraphics {std::string mesh;static const ecs::CTypeSize TYPE = 8;};

int main()
{
	ecs::EntityManager<CVelocity, CPosition, CGraphics> manager;
	// manager.lol();
	return 0;
}
