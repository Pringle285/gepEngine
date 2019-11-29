#include "Mesh.h"
#include <fstream>
#include "Exception.h"
#include "Core.h"

namespace gepEngine
{

void Mesh::load(std::string path)
{

	std::ifstream file(path);

	if(!file.is_open())
	{
		throw Exception("Failed to open Mesh");
	}
	
	std::string obj;
	std::string line; 

	while (!file.eof())
	{
		std::getline(file, line);
		obj += line + "\n";
	}
	
	raw = getCore()->getContext()->createMesh();
	raw->parse(obj); 

	dirty = true;
}

std::shared_ptr<rend::Mesh> Mesh::getRendMesh()
{
	return raw; 
}


}
