#include "Component.h"
#include <memory>


namespace gepEngine
{

class Mesh;
class Material;

class MeshRenderer : public Component
{
private:
	std::weak_ptr<Mesh> mesh;
	//std::shared_ptr<Materal> material;

public:
	void onInit();
	void onDisplay();
	void setMesh(std::weak_ptr<Mesh> mesh);
	std::shared_ptr<Mesh> getMesh();
	std::shared_ptr<Material> getMaterial();

};


}
