#include "Core.h"
#include "Entity.h"

#include <iostream> 


std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> core = std::make_shared<Core>();

	return core;
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
	entities.push_back(rtn);

	return rtn;
}

void Core::tick()
{
	std::cout << "coretick out" << std::endl;
	for (auto i : entities)
	{
		//std::cout << typeid(i).name();
		i->tick();
	}
}

void Core::start()
{
	std::cout << "text from start func in core class" << std::endl;
	tick();
}

void Core::end()
{
	
}
