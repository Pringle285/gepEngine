#include "Entity.h"
#include <iostream> 

void Entity::tick()
{
	for (auto i : components)
	{
		std::cout << typeid(i).name();
		//call update on each i(componenet) once implemented
		//i.update();
	}
}

std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}
