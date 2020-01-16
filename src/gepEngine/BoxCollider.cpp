#include "BoxCollider.h"
#include "Transform.h"
#include "Core.h"

namespace gepEngine
{

void BoxCollider::onInit()
{
	lastPosition = getTransform()->getPosition();
}

void BoxCollider::onTick()
{
	isColliding(getTransform()->getPosition(), size);
}

void BoxCollider::setSize(glm::vec3 settingSize)
{
	size = settingSize;
}

void BoxCollider::setOffset(glm::vec3 settingOffset)
{
	offset = settingOffset;
}

bool BoxCollider::isColliding(glm::vec3 position, glm::vec3 size)
{
	bool checkCollision = false;
	
	std::list<std::shared_ptr<Entity>> entitiesWithBoxCollide;
	//getCore()->entitiesWithComponent<BoxCollider>(entitiesWithBoxCollide);	
	entitiesWithBoxCollide = getCore()->entitiesWithComponent<BoxCollider>();

	for (std::list<std::shared_ptr<Entity>>::iterator it = entitiesWithBoxCollide.begin(); it != entitiesWithBoxCollide.end(); it++) 
	{
		if (*it == getEntity())
		{
			continue;
		}

		


		
	}
	
	return checkCollision;
}















}
