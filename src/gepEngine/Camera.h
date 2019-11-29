#include "Component.h"
//#include "Core.h"
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>

namespace gepEngine
{

class Camera : public Component
{
private:
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
	
	std::weak_ptr<Camera> self; 

public:
	glm::mat4 getView();
	glm::mat4 getProjection();
	
	void onInit();

};

}
