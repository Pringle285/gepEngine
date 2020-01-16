#include "Component.h"

#include <glm/glm.hpp>


namespace gepEngine
{

class BoxCollider : public Component
{
private:
	glm::vec3 size;
	glm::vec3 offset;

	
public:
	void onTick();
	void setSize(glm::vec3 settingSize);
	void setOffset(glm::vec3 settingOffset);
	bool isColliding(glm::vec3 position, glm::vec3 size);

};

}
