#include <vector>

namespace gepEngine
{

class Keyboard
{
private: 
	std::vector<int> keys;
	std::vector<int> pressedKeys;
	std::vector<int> releasedKeys;



public:
	void keyboardInput();

	void checkKeysForRelease();

};

}
