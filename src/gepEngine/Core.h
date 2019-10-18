#include <memory>
#include <list>

class Entity;

class Core
{
private:
	std::list<std::shared_ptr<Entity>> entities;

public:
	static std::shared_ptr<Core> initialize();
	std::shared_ptr<Entity> addEntity();
	void start();

};
