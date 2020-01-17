#include <SDL2/SDL.h>

namespace gepEngine
{

class Environment
{
private:
	float deltaTime;

public:
	//set the deltatime for the running of the program
	void setDeltaTime(float time);

	//returns the deltatime to be used
	float getDeltaTime();
};

}
