
#include "Resource.h"
#include <memory>
#include <rend/rend.h>

namespace gepEngine
{

class Mesh : public Resource
{
private:
	bool dirty;
	std::shared_ptr<rend::Mesh> raw; 

	

public:
	void load(std::string path);


};

}
