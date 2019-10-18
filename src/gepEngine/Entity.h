#include <memory>
#include <list>

class Component;
class Core;

class Entity
{
private:
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;
	void tick();

public:
	std::shared_ptr<Core> getCore();
	
	template <class T>
	std::shared_ptr<T> addComponent(T t);

	template <class T, class Y>
	std::shared_ptr<T> addComponent(T t, Y y);



};
