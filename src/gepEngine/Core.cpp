#include "Core.h"
#include <iostream> 


std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> core = std::make_shared<Core>();

	return core;
}

std::shared_ptr<Entity> addEntity()
{

}

void Core::start()
{
	std::cout << "text from start func in core class" << std::endl;
}
