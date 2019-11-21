#include "Resource.h"
#include "Resources.h"


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
