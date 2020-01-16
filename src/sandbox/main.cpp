#include <iostream>
#include <stdlib.h>
#include <memory>
#include <gepEngine/GepEngine.h>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <exception>

#include <math.h>

using namespace gepEngine;

/*struct DogController : Component
{
  void onTick()
	{
    if(getKeyboard()->getKey(KEYS_DOWN))
		{
			//getTransform()->move(vec3(0, -1, 0) * getDeltaTime());
			getTransform()->setPosition(getTransform()->getPosition() + vec3(0, -1, 0) * getDeltaTime());
		}
	}
};*/

struct camController : Component
{
	void onTick()
	{
		if (getKeyboard()->checkKeys('w'))
		{
			getTransform()->setPosition(getTransform()->getPosition() + glm::vec3(0, 0, -3) * getCore()->getDeltaTime());
		}
		if (getKeyboard()->checkKeys('a'))
		{
			getTransform()->setPosition(getTransform()->getPosition() + glm::vec3(-3, 0, 0) * getCore()->getDeltaTime());
		}
		if (getKeyboard()->checkKeys('s'))
		{
			getTransform()->setPosition(getTransform()->getPosition() + glm::vec3(0, 0, 3) * getCore()->getDeltaTime());
		}
		if (getKeyboard()->checkKeys('d'))
		{
			getTransform()->setPosition(getTransform()->getPosition() + glm::vec3(3, 0, 0) * getCore()->getDeltaTime());
		}
		if (getKeyboard()->checkKeys('q'))
		{
			getTransform()->setRotation(getTransform()->getRotation() + glm::vec3(0, 0.4f, 0) * getCore()->getDeltaTime());
		}
		if (getKeyboard()->checkKeys('e'))
		{
			getTransform()->setRotation(getTransform()->getRotation() + glm::vec3(0, -0.4f, 0) * getCore()->getDeltaTime());
		}

	}
};


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

	//testvar
	glm::vec3 curuPos(0,0,-10);
	std::shared_ptr<Entity> te = c->addEntity();
	std::shared_ptr<MeshRenderer> mr = te->addComponent<MeshRenderer>();
	std::shared_ptr<Mesh> mesh = c->getResources()->load<Mesh>("models/curuthers.obj");
	mr->setMesh(mesh);
	te->getTransform()->setPosition(curuPos);
	te->getTransform()->setRotation(glm::vec3(0,0,0));
	te->getTransform()->setScale(glm::vec3(0.5, 0.5, 0.5));
	std::shared_ptr<BoxCollider> bcCuru = te->addComponent<BoxCollider>();
	bcCuru->setSize(glm::vec3(1,1,1));
	bcCuru->setOffset(glm::vec3(0.1f, 0.1f, 0.1f));

	std::shared_ptr<Material> material = c->getResources()->load<Material>("shaders/simpleTex");
	material->addTexture("textures/curuthers_diffuse.png");
	mr->setMaterial(material);

	std::shared_ptr<Entity> graveyard = c->addEntity();
	std::shared_ptr<MeshRenderer> gyMR = graveyard->addComponent<MeshRenderer>();
	std::shared_ptr<Mesh> gyMesh = c->getResources()->load<Mesh>("models/graveyard.obj");
	gyMR->setMesh(gyMesh);
	graveyard->getTransform()->setPosition(glm::vec3(0,-1,-10));

	std::shared_ptr<Material> gyMaterial = c->getResources()->load<Material>("shaders/simpleTex");
	gyMaterial->addTexture("textures/graveyard.png");
	gyMR->setMaterial(gyMaterial);

	/*
	 * e = addEntity();
	 * e->addComponent<Player>();
	 */

	std::shared_ptr<Entity> cameraEntity = c->addEntity();
	std::shared_ptr<Camera> camera = cameraEntity->addComponent<Camera>();
	cameraEntity->getTransform()->setPosition(glm::vec3(0, 2, 0));
	cameraEntity->getTransform()->setRotation(glm::vec3(-0.2, 0, 0));
	
	cameraEntity->addComponent<camController>();

	curuPos.x += 0.1;
	c->start();

	system("pause");
	return 0;
}
