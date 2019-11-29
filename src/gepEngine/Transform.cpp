#include "Transform.h"

namespace gepEngine
{

void Transform::setPosition(glm::vec3 settingPosition)
{
	position = settingPosition;
}

glm::vec3 Transform::getPosition()
{
	return position;
}



}
