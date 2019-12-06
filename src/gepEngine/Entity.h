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

	std::weak_ptr<Core> core;
	std::weak_ptr<Entity> self;
	std::weak_ptr<Transform> trans;
	
	std::list<std::shared_ptr<Component>> components;

	void tick();

public:
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Transform> getTransform();
	

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

	template <typename T, typename Y>
	std::shared_ptr<T> addComponent(Y y)
 	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		
		rtn->entity = self;
		rtn->onInit(y);

		components.push_back(rtn);
		return rtn;
	}

	template <typename T, typename Y, typename X>
	std::shared_ptr<T> addComponent(Y y, X x)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		rtn->entity = self;
		rtn->onInit(y, x);
	}


};

}
