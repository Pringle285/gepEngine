#include <iostream>
#include <stdlib.h>
#include <memory>
#include <gepEngine/Core.h>

int main()
{
	std::cout << "gep engine" << std::endl;
	
	std::shared_ptr<Core> c = Core::initialize();
		

	c->start();

	system("pause");
	return 0;
}
