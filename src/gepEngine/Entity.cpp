#include "Entity.h"

void Entity::tick()
{

}

std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}
