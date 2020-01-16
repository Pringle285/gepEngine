#include "Component.h"

#include <glm/glm.hpp>

namespace gepEngine
{

class Core;

class Transform : public Component
{
private:
	glm::vec3 position = glm::vec3(0,0,0);
	glm::vec3 rotation = glm::vec3(0,0,0);
	glm::vec3 scale = glm::vec3(1,1,1);
	

public:
	void setPosition(glm::vec3 settingPosition);
	void setRotation(glm::vec3 settingRotation);
	void setScale(glm::vec3 settingScale);

	glm::vec3 getPosition();
	glm::vec3 getRotation();
	glm::vec3 getScale();

	void translate(glm::vec3 amount);

	glm::mat4 getModel();
	
	void onTick();

};

}
