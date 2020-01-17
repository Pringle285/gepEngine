#include "Component.h"
//#include "Core.h"
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>

namespace gepEngine
{

class Camera : public Component
{
private:
	glm::mat4 projection;
	
	std::weak_ptr<Camera> self;
	friend class gepEngine::Entity;

public:
	//provides the view matrix of the camera
	glm::mat4 getView();

	//provides the projection matrix provided by the camera
	glm::mat4 getProjection();
	
	//overwrite of virtual init to initilize camera data
	void onInit();
	
	//returns a shared pointer of this camera
	std::shared_ptr<Camera> getCamera();
};

}
