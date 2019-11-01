#include "Component.h"

#include <glm/glm.hpp>

class Transform : public Component
{
private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

public:
	void setPosition(glm::vec3 position);
	glm::vec3 getPosition();



};
