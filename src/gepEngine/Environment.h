#include <SDL2/SDL.h>

namespace gepEngine
{

class Environment
{
private:
	float deltaTime;

public:
	void setDeltaTime(float time);
	float getDeltaTime();
};

}
