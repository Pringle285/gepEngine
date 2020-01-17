#pragma once
#ifndef _RESOURCE_H
#define _RESOURCE_H


#include <string> 
#include <memory>

namespace gepEngine
{

class Resources;
class Core;

class Resource
{
private:
	friend class gepEngine::Resources;
	//path for loading files
	std::string path;

	std::weak_ptr<Resources> resources;


public:
	//provides access to resources
	std::shared_ptr<Resources> getResources();

	//shortcut for access to core
	std::shared_ptr<Core> getCore();

};

}

#endif
