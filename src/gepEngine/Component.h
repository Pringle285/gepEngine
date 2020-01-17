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
class Transform;
class Keyboard;

class Component
{
private:
	friend class gepEngine::Entity;

	std::weak_ptr<Entity> entity;
	std::weak_ptr<Component> self;

	//virtual init function to be overwritten by components inheriting from this to allow component specific initilization
	virtual void onInit();
	virtual void onBegin();

	//virtual onTick function to be overwritten by components inheriting from this to allow
	//component specific data updates at the start of each game loop
	virtual void onTick();

	//virtual onDisplay function to be overwritten by components inheriting from this to allow
	//component specific display updates at the end of each game loop
	virtual void onDisplay();

public:
	//shortcut function to access entitiy containing this component
	std::shared_ptr<Entity> getEntity();

	//shortcut function to access core directly from current component
	std::shared_ptr<Core> getCore();

	//shortcut function to access resources directly from current component
	std::shared_ptr<Resources> getResources();

	//shortcut function to access transform directly from current component
	std::shared_ptr<Transform> getTransform();

	//shortcut function to access keyboard directly from current component
	std::shared_ptr<Keyboard> getKeyboard();

};

}
#endif
