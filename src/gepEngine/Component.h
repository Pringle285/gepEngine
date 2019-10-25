#pragma once
#ifndef _COMPONENT_H
#define _COMPONENT_H


#include <memory>
#include <list>

class Entity;
class Core;

class Component
{
private:
	std::weak_ptr<Entity> entity;
	void onInit();
	void onBegin();
	void onTick();
	virtual void onDisplay();

	friend class ::Entity;

public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();


};

#endif
