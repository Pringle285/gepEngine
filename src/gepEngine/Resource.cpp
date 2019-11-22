#include "Resource.h"
#include "Resources.h"
#include <iostream>

namespace gepEngine
{


std::shared_ptr<Resources> Resource::getResources()
{
	return resources.lock();
}

std::shared_ptr<Core> Resource::getCore()
{
	
	return getResources()->getCore();
}



}
