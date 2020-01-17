#pragma once
#ifndef _ENTITY_H
#define _ENTITY_H

#include <memory>
#include <list>

namespace gepEngine
{

class Component;
class Core;
class Transform;

class Entity
{
private:
	friend class gepEngine::Core;
	
	//pointers around the CES system
	std::weak_ptr<Core> core;
	std::weak_ptr<Entity> self;
	std::weak_ptr<Transform> trans;
	
	//list of shared pointers to all components on the current entity
	std::list<std::shared_ptr<Component>> components;

	//calls data updates for all components attached to the entity
	void tick();

	//calls all display updates for all components attached to the entity
	void display();

public:
	//access to core
	std::shared_ptr<Core> getCore();

	//shortcut to the transform component of the entity
	std::shared_ptr<Transform> getTransform();
	
	//template function to get a component of a specified type T if this component exists attached to the entitiy.
	template <typename T>
	std::shared_ptr<T> getComponent()
	{
		for (auto i : components)
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(i);

			if (rtn)
			{
				return rtn;
			}
		}
		//throw an exception here using Exception class
	}
	
	//template function to  add a component of specified type T
	template <typename T>
	std::shared_ptr<T> addComponent() 
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		
		rtn->entity = self;
		rtn->self = rtn;
		rtn->onInit();

		components.push_back(rtn);
		return rtn;
	}
	
	//template function to add a component of specified type T with required variable to pass in Y
	template <typename T, typename Y>
	std::shared_ptr<T> addComponent(Y y)
 	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		
		rtn->entity = self;
		rtn->onInit(y);

		components.push_back(rtn);
		return rtn;
	}
	
	//template function to add a component of specified type T with variables to pass Y & X
	template <typename T, typename Y, typename X>
	std::shared_ptr<T> addComponent(Y y, X x)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		rtn->entity = self;
		rtn->onInit(y, x);
	}


};

}
#endif
