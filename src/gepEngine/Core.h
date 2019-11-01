#include <memory>
#include <list>

#include <SDL2/SDL.h>

class Entity;

class Core
{
private:
	std::list<std::shared_ptr<Entity>> entities;
	void tick();
	bool running;

	std::weak_ptr<Core> self;


	SDL_Window *window;

public:
	static std::shared_ptr<Core> initialize();
	std::shared_ptr<Entity> addEntity();
	void start();
	void end();

};
