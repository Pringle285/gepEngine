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
	//overwritten init from component to initilize the meshrenderer data
	void onInit();

	//overwritten ondisplay from component to call display data for the meshrenderer
	void onDisplay();

	//sets the mesh for the renderer from a passed in mesh smart pointer
	void setMesh(std::shared_ptr<Mesh> settingMesh);

	//sets the material (shader + texture) from a passed in material smart pointer
	void setMaterial(std::shared_ptr<Material> settingMaterial);

};


}
