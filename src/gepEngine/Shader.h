#include "Resource.h"
#include <rend/rend.h>

namespace gepEngine
{

class Shader : public Resource
{
private:
	bool dirty;
	std::shared_ptr<rend::Texture> tex;

public:
	void load(std::string path);
	
	
};

}
