#include "Component.h"
#include "Entity.h"
#include <iostream>

namespace gepEngine
{


void Component::onInit() {}

void Component::onBegin() {}

void Component::onTick() {}

void Component::onDisplay() {}

std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
	return getEntity()->getCore();
}


}
