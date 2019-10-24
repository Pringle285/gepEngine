#include <memory>
#include <list>

class Entity;

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
	



};
