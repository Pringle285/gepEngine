#include <memory>
#include <list>
#include <rend/rend.h>

#include <SDL2/SDL.h>

//#include "stb_vorbis.h"
#include <AL/al.h>
#include <AL/alc.h>


namespace gepEngine
{

class Entity;
class Resources;
class Camera;
class Transform;
class Keyboard; 

class Core
{
private:
	std::list<std::shared_ptr<Entity>> entities;
	void tick(); //acts as update
	//need to add a display function to ensure update happens prior to display
	void display();
	bool running;

	std::weak_ptr<Core> self;

	
	SDL_Window *window;
	
	std::shared_ptr<rend::Context> context;
	std::shared_ptr<Resources>  resources;
	
	//ALCdevice* audioDevice;
	//ALCcontext* audioContext;

	std::weak_ptr<Camera> currentCamera;
	
	std::shared_ptr<Keyboard> keyboard; 
	
public:
	static std::shared_ptr<Core> initialize();
	std::shared_ptr<Entity> addEntity();
	std::shared_ptr<rend::Context> getContext();
	std::shared_ptr<Resources> getResources();
	std::shared_ptr<Camera> getCurrentCamera();
	void setCurrentCamera(std::shared_ptr<Camera> settingCamera);
	void start();
	void end();
	


};

}
