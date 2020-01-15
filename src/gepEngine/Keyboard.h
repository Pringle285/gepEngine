#include <vector>
#include <SDL2/SDL.h>

namespace gepEngine
{

class Keyboard
{
private: 
	std::vector<int> keys;
	std::vector<int> pressedKeys;
	std::vector<int> releasedKeys;



public:
	void keyboardInput(int input);

	void checkKeysForRelease();
	void pressedKeysToKeys();

	void addingReleasedKeys(int release);

	void updateKeys();
	
	void clearKeys();


	std::vector<int> getKeys();
	std::vector<int> getPressedKeys();
	std::vector<int> getReleasedKeys();

};

}
