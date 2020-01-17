#include "Component.h"

#include <glm/glm.hpp>


namespace gepEngine
{

class BoxCollider : public Component
{
private:
	glm::vec3 size;
	glm::vec3 offset;
	glm::vec3 lastPosition;
	
public:
	//overwrite for component tick, updating data for box collision
	void onTick();

	//overwrite for init on component, sets initial data
	void onInit();

	//sets size for the collision box on the current entitiy
	void setSize(glm::vec3 settingSize);

	//sets offset for current entity
	void setOffset(glm::vec3 settingOffset);

	//starts collision checking, collects data in vector of all entities with boxcollider component
	//then calls collision response and iscolliding to find out if collision is happening and provides a method of
	//default handling
	void collideBox();

	//cludge method for box collision response
	glm::vec3 getCollisionResponse(glm::vec3 position, glm::vec3 size);

	//checks aabb collision
	bool isColliding(glm::vec3 position, glm::vec3 size);

};

}
