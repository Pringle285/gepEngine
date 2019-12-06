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
	glm::mat4 getView();
	glm::mat4 getProjection();
	
	void onInit();
	
	std::shared_ptr<Camera> getCamera();
};

}
