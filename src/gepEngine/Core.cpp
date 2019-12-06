#include "Core.h"
#include "Entity.h"
#include "Resources.h"
#include "Transform.h"

#include <iostream>
#include <exception>
#include <GL/glew.h>

namespace gepEngine
{

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

std::shared_ptr<Core> Core::initialize()
{
	//make shared ptr of core
	std::shared_ptr<Core> core = std::make_shared<Core>();
	
	core->self = core;

	core->running = false;
	
	//sdl init
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	core->window = SDL_CreateWindow("Lab 4 - Architecture",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if(!SDL_GL_CreateContext(core->window))
	{
		throw std::exception();
	}

	//if(glewInit() != GLEW_OK)
	//{
	//	throw std::exception();
	//}
	
	//creating the resources object so it knows core exists
	core->resources = std::make_shared<Resources>();
	core->resources->self = core->resources;
	core->resources->core = core; 
	
	//core->resources;

	//context = rend::Context::initialize();
	core->context = rend::Context::initialize();

	return core;
}

std::shared_ptr<rend::Context> Core::getContext()
{
	return context;
}

std::shared_ptr<Resources> Core::getResources()
{
	return resources;
}

void Core::start()
{

	running = true;

	while(running)
	{
		SDL_Event event = {0};

		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				running = false;
			}
		}
		//calling update on all entities and components
		//tick();

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//calling update on all entities and components
		tick();

		//call display/draw functions from entities/components here
		

		SDL_GL_SwapWindow(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
	entities.push_back(rtn);
	rtn->self = rtn;
	rtn->core = self;
	std::shared_ptr<Transform> transform = rtn->addComponent<Transform>();
	rtn->trans = transform;
	return rtn;
}

void Core::tick()
{
	//std::cout << "coretick out" << std::endl;
	for (auto i : entities)
	{
		//std::cout << typeid(i).name();
		i->tick();
	}
}

std::shared_ptr<Camera> Core::getCurrentCamera()
{
	return currentCamera.lock();
}

void Core::setCurrentCamera(std::shared_ptr<Camera> settingCamera)
{
	currentCamera = settingCamera;
}


void Core::end()
{
	
}


}
