#include <iostream>
#include <stdlib.h>
#include <memory>
#include <gepEngine/GepEngine.h>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <exception>

using namespace gepEngine;

//sdl2 tries to change main since each os uses
//different mains such as winmain for windows
//or nativemain on andriods and this avoids
//the console based main in base c++, can simply
//undef main, link to SDL2main or hack sdl
//header file to avoid this
#undef main
int main()
{
	
	//std::cout << "gep engine" << std::endl;
	
	std::shared_ptr<Core> c = Core::initialize();
	/*
	std::shared_ptr<Entity> entity1 = c->addEntity();

	//std::shared_ptr<TriangleRenderer> triRender = entity1->addComponent<TriangleRenderer>();
	*/

	std::shared_ptr<Entity> te = c->addEntity();
	std::shared_ptr<MeshRenderer> mr = te->addComponent<MeshRenderer>();
	std::shared_ptr<Mesh> mesh = c->getResources()->load<Mesh>("models/curuthers.obj");
	mr->setMesh(mesh);
	te->getTransform()->setPosition(glm::vec3(0,0,-10));

	std::shared_ptr<Material> material = c->getResources()->load<Material>("shaders/simpleTex");
	material->addTexture("textures/curuthers_diffuse.png");
	mr->setMaterial(material);
	

	std::shared_ptr<Entity> cameraEntity = c->addEntity();
	std::shared_ptr<Camera> camera = cameraEntity->addComponent<Camera>();
	cameraEntity->getTransform()->setPosition(glm::vec3(0, 0, 10));


	c->start();

	system("pause");
	return 0;
}
