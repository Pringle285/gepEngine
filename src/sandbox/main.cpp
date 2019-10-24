#include <iostream>
#include <stdlib.h>
#include <memory>
#include <gepEngine/GepEngine.h>

int main()
{
	std::cout << "gep engine" << std::endl;
	
	std::shared_ptr<Core> c = Core::initialize();

	std::shared_ptr<Entity> entity1 = c->addEntity();
	//entity1->tick();
	c->start();

	system("pause");
	return 0;
}
