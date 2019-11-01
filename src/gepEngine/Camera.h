#include "Component.h"

#include <glm/glm.hpp>

class Camera : public Component
{
private:
	

public:
	glm::mat4 getView();
	glm::mat4 getProjection();


};
