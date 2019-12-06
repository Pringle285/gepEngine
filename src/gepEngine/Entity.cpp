#include "Entity.h"
#include "Component.h"
#include <iostream> 

namespace gepEngine
{

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

std::shared_ptr<Transform> Entity::getTransform()
{
	return trans.lock();
}

}
