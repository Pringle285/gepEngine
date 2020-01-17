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
	//function to load in the mesh and parse the data to rend
	void load(std::string path);
	
	//pointer to rend version of the mesh
	std::shared_ptr<rend::Mesh> getRendMesh();

};

}
