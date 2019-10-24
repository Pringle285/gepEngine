#include "Entity.h"
#include "Component.h"
#include <iostream> 

void Entity::tick()
{
	for (auto x : components)
	{
		//std::cout << typeid(x).name();
		x->onDisplay();
	}
}

std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}
