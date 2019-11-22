#pragma once
#ifndef _COMPONENT_H
#define _COMPONENT_H


#include <memory>
#include <list>

namespace gepEngine
{

class Entity;
class Core;
class Resources;

class Component
{
private:
	friend class gepEngine::Entity;

	std::weak_ptr<Entity> entity;

	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();

public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Resources> getResources();


};

}
#endif
