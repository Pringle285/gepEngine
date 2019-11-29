#include "Component.h"
#include <memory>


namespace gepEngine
{

class Mesh;
class Material;

class MeshRenderer : public Component
{
private:
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Material> material;
	

public:
	void onInit();
	void onDisplay();
	void setMesh(std::shared_ptr<Mesh> settingMesh);
	void setMaterial(std::shared_ptr<Material> settingMaterial);

};


}
