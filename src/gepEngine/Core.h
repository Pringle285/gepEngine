#include <memory>
#include <list>
#include <rend/rend.h>

#include <SDL2/SDL.h>

//#include "stb_vorbis.h"
#include <AL/al.h>
#include <AL/alc.h>

#include "Entity.h"
#include "Component.h"


namespace gepEngine
{

class Entity;
class Resources;
class Camera;
class Transform;
class Keyboard; 
class Environment;

class Core
{
private:
	//list of all entities
	std::list<std::shared_ptr<Entity>> entities;
	//calls to update values on all entities
	void tick();
	//used once tick has been called to call draw on all entities with updated values
	void display();

	//bool to check if program is still running
	bool running;

	//init value for deltaTime calculation
	float lastTime = SDL_GetTicks();
	float idealTime = 1.0f / 60.0f;


	std::weak_ptr<Core> self;

	
	SDL_Window *window;
	
	//pointers for quick access around the engine
	std::shared_ptr<rend::Context> context;
	std::shared_ptr<Resources>  resources;
	//ALCdevice* audioDevice;
	//ALCcontext* audioContext;
	std::weak_ptr<Camera> currentCamera;
	std::shared_ptr<Keyboard> keyboard; 
	std::shared_ptr<Environment> environment;

public:
	static std::shared_ptr<Core> initialize();
	std::shared_ptr<Entity> addEntity();
	std::shared_ptr<rend::Context> getContext();
	std::shared_ptr<Resources> getResources();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Camera> getCurrentCamera();
	std::list<std::shared_ptr<Entity>> getEntities();
	void setCurrentCamera(std::shared_ptr<Camera> settingCamera);
	void start();
	void end();
	
	float getDeltaTime();

	//Checking for entities with a specific component of type T
	template <typename T>
	std::list<std::shared_ptr<Entity>> entitiesWithComponent()
	{
		std::list<std::shared_ptr<Entity>> container;
		//iterator through entities
		for (std::list<std::shared_ptr<Entity>>::iterator itEnt = entities.begin(); itEnt != entities.end(); itEnt++)
		{
			//iterator through components of each entity
			bool doesItContainT = false;
			for (std::list<std::shared_ptr<Component>>::iterator itCom = (*itEnt)->components.begin(); itCom != (*itEnt)->components.end(); itCom++)
			{
				//checking if component type at current point in loop is equal to template type T
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>((*itCom));
				if (rtn)
				{
					//if rtn isn't null (component is of type T) set check to true
					doesItContainT = true;
				}

			
			}	
			//if check above is true then push the entity into the vector
			if (doesItContainT == true)
			{
				container.push_back((*itEnt));
			}
		}




		return container; 
	}


};

}
