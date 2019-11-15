#include "Mesh.h"
#include <fstream>
#include "Exception.h"

namespace gepEngine
{

std::shared_ptr<Mesh> Mesh::load(std::string path)
{

	std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
	mesh->self = mesh;

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
	raw = context->createMesh();
	raw->parse(obj)
	return mesh; 
}



}
