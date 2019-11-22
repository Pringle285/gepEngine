#include "MeshRenderer.h"


namespace gepEngine
{

void MeshRenderer::onInit() {}

void MeshRenderer::onDisplay(){}


std::shared_ptr<Mesh> MeshRenderer::getMesh()
{
	return mesh.lock();
}
/*
std::shared_ptr<Material> MeshRenderer::getMaterial()
{
	return material.lock();
}
*/
void MeshRenderer::setMesh(std::weak_ptr<Mesh> settingMesh)
{
	mesh = settingMesh;
}


}
