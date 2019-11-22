#include <memory>
#include <string>
#include <list> 
#include <iostream>

namespace gepEngine
{

class Resource;
class Core; 

class Resources
{
private:
	std::list<std::shared_ptr<Resource>> resources; 
	
	friend class gepEngine::Core;

	std::weak_ptr<Core> core;
	std::weak_ptr<Resources> self;

public: 

	std::shared_ptr<Core> getCore();
	

	template <typename T>
	std::shared_ptr<T> load(std::string path)
	{
		//this takes the loaded data from the mesh/texture/shader etc and
		//adds it to the above list, make a Resource then come back to this.
		std::shared_ptr<T> rtn = std::make_shared<T>();
		rtn->resources = self;
		
		
		rtn->load(path);

		resources.push_back(rtn);

		return rtn;
	}



};

}
