#include <memory>
#include <list>

#include <SDL2/SDL.h>

namespace gepEngine
{

class Entity;

class Core
{
private:
	std::list<std::shared_ptr<Entity>> entities;
	void tick(); //acts as update
	//need to add a display function to ensure update happens prior to display
	bool running;

	std::weak_ptr<Core> self;

	
	SDL_Window *window;
	
	std::shared_ptr<rend::Context> context;
	
	//do I need the line below? 
	//std::shared_ptr<Resources> resources;

public:
	static std::shared_ptr<Core> initialize();
	std::shared_ptr<Entity> addEntity();
	void start();
	void end();

};

}
