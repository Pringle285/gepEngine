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

void Camera::onInit()
{
	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	camera->self = camera;

	getCore()->setCurrentCamera(camera);
}

}
