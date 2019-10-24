#include <iostream>
#include <stdlib.h>
#include <memory>
#include <gepEngine/GepEngine.h>


class TestScreen : public Component
{
	void onDisplay()
	{
		std::cout << "onDisplay called from testScreen" << std::endl;
	}

};


int main()
{
	std::cout << "gep engine" << std::endl;
	
	std::shared_ptr<Core> c = Core::initialize();

	std::shared_ptr<Entity> entity1 = c->addEntity();

	std::shared_ptr<TestScreen> testScreen = entity1->addComponent<TestScreen>();
	//entity1->tick();
	c->start();

	system("pause");
	return 0;
}
