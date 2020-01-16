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
	collideBox();
}

void BoxCollider::setSize(glm::vec3 settingSize)
{
	size = settingSize;
}

void BoxCollider::setOffset(glm::vec3 settingOffset)
{
	offset = settingOffset;
}

void BoxCollider::collideBox()
{
	
	std::list<std::shared_ptr<Entity>> entitiesWithBoxCollide;
	//getCore()->entitiesWithComponent<BoxCollider>(entitiesWithBoxCollide);	
	entitiesWithBoxCollide = getCore()->entitiesWithComponent<BoxCollider>();

	glm::vec3 np = getTransform()->getPosition() + offset;

	for (std::list<std::shared_ptr<Entity>>::iterator it = entitiesWithBoxCollide.begin(); it != entitiesWithBoxCollide.end(); it++) 
	{
		if (*it == getEntity())
		{
			continue;
		}

		std::shared_ptr<BoxCollider> bc = (*it)->getComponent<BoxCollider>();

		glm::vec3 sp = bc->getCollisionResponse(np, size);
		np = sp;
		np = np - offset;
		getTransform()->setPosition(np);
		lastPosition = np;

		
	}
	
}

bool BoxCollider::isColliding(glm::vec3 position, glm::vec3 size)
{
	glm::vec3 a = getTransform()->getPosition() + offset;
	glm::vec3& as = this->size;
	glm::vec3& b = position;
	glm::vec3& bs = size;

	if(a.x > b.x) // a right of b
  {
    if(a.x - as.x > b.x + bs.x) // left edge of a greater than right edge of b (not colliding)
    {
      return false;
    }
  }
  else
  {
    if(b.x - bs.x > a.x + as.x)
    {
      return false;
    }
  }

  if(a.z > b.z) // a front of b
  {
    if(a.z - as.z > b.z + bs.z) // back edge of a greater than front edge of b (not colliding)
    {
      return false;
    }
  }
  else
  {
    if(b.z - bs.z > a.z + as.z)
    {
      return false;
    }
  }

  if(a.y > b.y) // a above b
  {
    if(a.y - as.y > b.y + bs.y) // bottom edge of a greater than top edge of b (not colliding)
    {
      return false;
    }
  }
  else
  {
    if(b.y - bs.y > a.y + as.y)
    {
      return false;
    }
  }

  return true;
}

glm::vec3 BoxCollider::getCollisionResponse(glm::vec3 position, glm::vec3 size)
{
	float amount = 0.05f;
	float step = 0.05f;

	while (true)
	{
		if (!isColliding(position, size)) break;
		position.x += amount;
		if (!isColliding(position, size)) break;
		position.x -= amount;
		position.x -= amount;
		if (!isColliding(position, size)) break;
		position.x += amount;
		position.z += amount;
		if (!isColliding(position, size)) break;
		position.z -= amount;
		position.z -= amount;
		if (!isColliding(position, size)) break;	
		position.z += amount;
		position.y += amount;
		if (!isColliding(position, size)) break;
		position.y -= amount;
		position.y -= amount;
		if (!isColliding(position, size)) break;
		position.y += amount;
		amount += step;
	}
	
	return position;
}















}
