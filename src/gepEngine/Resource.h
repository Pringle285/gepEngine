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
	std::string path;

	std::weak_ptr<Resources> resources;


public:
	std::shared_ptr<Resources> getResources();
	std::shared_ptr<Core> getCore();

};

}

#endif
