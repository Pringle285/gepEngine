#include "Transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

namespace gepEngine
{

void Transform::setPosition(glm::vec3 settingPosition)
{
	position = settingPosition;
}

void Transform::setRotation(glm::vec3 settingRotation)
{
	rotation = settingRotation;
}

void Transform::setScale(glm::vec3 settingScale)
{
	scale = settingScale;
}


glm::vec3 Transform::getPosition()
{
	return position;
}

glm::vec3 Transform::getRotation()
{
	return rotation;
}

glm::vec3 Transform::getScale()
{
	return scale;
}


glm::mat4 Transform::getModel()
{
	//identity mat
	//translate , rotate 3 axis y,x,z,  scale
	
	glm::mat4 m = glm::mat4(1.0);

	m = glm::translate(m, position);

	m = glm::rotate(m, rotation.y, glm::vec3(0,1,0));
	m = glm::rotate(m, rotation.x, glm::vec3(1,0,0));
	m = glm::rotate(m, rotation.z, glm::vec3(0,0,1));

	m = glm::scale(m, scale);
	//std::cout << position.x << " " << position.y << " " << position.z << std::endl;
	return m;
}

void Transform::onTick()
{
	getModel();
}

void Transform::translate(glm::vec3 amount)
{
	glm::mat4 m = glm::mat4(1.0f);

	m = glm::rotate(m, rotation.x, glm::vec3(1,0,0));
	m = glm::rotate(m, rotation.y, glm::vec3(0,1,0));
	m = glm::rotate(m, rotation.z, glm::vec3(0,0,1));

	glm::vec3 diff = glm::vec3(m * glm::vec4(amount, 1));
	
	position += diff; 

}

}
