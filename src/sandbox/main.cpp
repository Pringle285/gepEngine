#include <iostream>
#include <stdlib.h>
#include <memory>
#include <gepEngine/GepEngine.h>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <exception>


class TestScreen : public Component
{
	void onDisplay()
	{
		std::cout << "onDisplay called from testScreen" << std::endl;
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
	std::cout << "gep engine" << std::endl;
	
	std::shared_ptr<Core> c = Core::initialize();

	std::shared_ptr<Entity> entity1 = c->addEntity();

	std::shared_ptr<TriangleRenderer> triRender = entity1->addComponent<TriangleRenderer>();

	//entity1->tick();
	c->start();

	system("pause");
	return 0;
}
