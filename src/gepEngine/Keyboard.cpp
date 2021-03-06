#include "Keyboard.h"

#include <iostream>


namespace gepEngine
{

void Keyboard::keyboardInput(int input)
{
	//std::cout << input << std::endl;
	pressedKeys.push_back(input);
}

void Keyboard::pressedKeysToKeys()
{
	for (std::vector<int>::iterator it = pressedKeys.begin(); it != pressedKeys.end(); ++it)
	{
		bool alreadyContains = false;
		for (std::vector<int>::iterator keysIt = keys.begin(); keysIt != keys.end(); ++keysIt)
		{
			if ((*it) == (*keysIt))
			{
				//std::cout << "test: " << (*it) << " " << (*keysIt) << std::endl;
				alreadyContains = true;
			}
		}
		if (alreadyContains == false)
		{
			keys.push_back((*it));
		}
	}
	/*for (std::vector<int>::iterator it = keys.begin(); it != keys.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}*/
}

void Keyboard::addingReleasedKeys(int release)
{
	releasedKeys.push_back(release);
}

void Keyboard::checkKeysForRelease()
{
	for (std::vector<int>::iterator it = releasedKeys.begin(); it != releasedKeys.end(); ++it)
	{
		int keysSize = keys.size();
		for (int counter = 0; counter < keysSize; counter++)
		{
			if ((*it) == keys.at(counter))
			{
				keys.erase(keys.begin() + counter);
				counter--;
				keysSize--;
			}
		}
	}

}

void Keyboard::updateKeys()
{
	pressedKeysToKeys();
	checkKeysForRelease();
}

void Keyboard::clearKeys()
{
	pressedKeys.clear();
	releasedKeys.clear();
}



std::vector<int> Keyboard::getKeys()
{
	return keys;
}

bool Keyboard::checkKeys(char testChar)
{
	bool checker = false;

	for (std::vector<int>::iterator it = keys.begin(); it != keys.end(); it++)
	{
		if ((int)testChar == (*it))
		{
			checker = true; 
		}
	}
	return checker;
}


std::vector<int> Keyboard::getPressedKeys()
{
	return pressedKeys;
}

bool Keyboard::checkPressedKeys(char testChar)
{
	bool checker = false; 

	for (std::vector<int>::iterator it = pressedKeys.begin(); it != pressedKeys.end(); it++)
	{
		if ((int)testChar == (*it))
		{
			checker = true;
		}
	}
	return checker;
}


std::vector<int> Keyboard::getReleasedKeys()
{
	return releasedKeys;
}

bool Keyboard::checkReleasedKeys(char testChar)
{
	bool checker = false;

	for (std::vector<int>::iterator it = releasedKeys.begin(); it != releasedKeys.end(); it++)
	{
		if ((int)testChar == (*it))
		{
			checker = true;
		}
	}
	return checker; 
}

}
