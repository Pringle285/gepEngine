#include "Component.h"
#include <iostream>

void Component::onInit()
{

}

void Component::onDisplay()
{
	std::cout << "onDisplay call from base component class" << std::endl;
}
