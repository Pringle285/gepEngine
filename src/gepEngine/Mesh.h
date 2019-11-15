#include "Resource.h"
#include <memory>


namespace gepEngine
{

class Mesh : public Resource
{
private:
	bool dirty;
	std::weak_ptr<Mesh> self;
	std::shared_ptr<rend::Mesh> raw; 

public:
	static std::shared_ptr<Mesh> load(std::string path);


};

}
