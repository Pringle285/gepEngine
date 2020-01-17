#include <vector>
#include <SDL2/SDL.h>

namespace gepEngine
{

class Keyboard
{
private: 
	//holds keys that are currently held
	std::vector<int> keys;

	//holds keys that have been pressed during the current frame
	std::vector<int> pressedKeys;

	//holds keys that have been released on the current frame
	std::vector<int> releasedKeys;



public:
	//collects keyboard input from SDL event and populates pressedKeys
	void keyboardInput(int input);

	//removes released keys from held keys
	void checkKeysForRelease();

	//adds pressedkeys to keys as long as the pressed key is not already contained within the keys vector
	void pressedKeysToKeys();
	
	//collects keyboard input and adds keys released this frame to releasedKeys
	void addingReleasedKeys(int release);


	//updates currently held keys based on released and pressed
	void updateKeys();
	
	//clears pressed and released at the end of each frame as these are only relevant on current frame
	void clearKeys();

	//provides access to the three key vectors
	std::vector<int> getKeys();
	std::vector<int> getPressedKeys();
	std::vector<int> getReleasedKeys();
	
	//provides a user with access to check the three keys vectors for specific characters allowing them
	//to act on currently pressed / released / held keys
	bool checkKeys(char testChar);
	bool checkPressedKeys(char testChar);
	bool checkReleasedKeys(char testChar);
	

};

}
