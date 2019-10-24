#include <memory>
#include <list>

class Component;
class Core;

class Entity
{
private:
	//friend class ::Core;
	
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;
	void tick();


public:
	std::shared_ptr<Core> getCore();
	
	template <typename T>
	std::shared_ptr<T> addComponent() 
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		components.push_back(rtn);
		return rtn;
	}

	template <typename T, typename Y>
	std::shared_ptr<T> addComponent(Y y)
 	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		//run with parameter y once init implemented
		components.push_back(rtn);
		return rtn;
	}


};
