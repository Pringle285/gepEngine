#include "Resource.h"
#include <rend/rend.h>
#include <memory>

namespace gepEngine
{

class Material : public Resource
{
private:
	std::shared_ptr<rend::Texture> tex; 
	std::shared_ptr<rend::Shader> sha;



public:
	//so this would need users to create a shader and texture object
	//then apply shader and object to the material to then use the material
	//void addShader(std::shared_ptr<Shader> settingShader)
	//void addTexture(std::shared_ptr<Texture> settingTexture
	
	//this loads a shader since shaders are always required, textures are optional
	void load(std::string path);
	void addTexture(std::string path);

	std::shared_ptr<rend::Shader> getShader();
	std::shared_ptr<rend::Texture> getTexture();

};

}
