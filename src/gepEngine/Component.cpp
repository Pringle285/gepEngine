#include "Component.h"
#include "Entity.h"
#include <iostream>


void Component::onInit()
{

}

void Component::onDisplay()
{
	
}

std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
	return getEntity()->getCore();
}


