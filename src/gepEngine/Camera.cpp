#include "Camera.h"
#include "Core.h"

namespace gepEngine
{


glm::mat4 Camera::getView()
{ 
	glm::mat4 emptyRtn = glm::mat4(1.0);
	return emptyRtn;
}

glm::mat4 Camera::getProjection()
{
	return projection;
}

std::shared_ptr<Camera> Camera::getCamera()
{
	return self.lock();
}

void Camera::onInit()
{
	//std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	//camera->self = camera;

	projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);

	getCore()->setCurrentCamera(getCamera());
}

}
