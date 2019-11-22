#include "Component.h"
#include "Entity.h"
#include <iostream>
#include "Core.h"

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

std::shared_ptr<Resources> Component::getResources()
{
	return getCore()->getResources();
}


}
