#include "MeshRenderer.h"
#include "Material.h"
#include "Mesh.h"
#include <glm/ext/matrix_clip_space.hpp>
#include "Core.h"
#include "Camera.h"


namespace gepEngine
{

void MeshRenderer::onInit() {}

void MeshRenderer::onDisplay()
{
	//the line below needs the cameras projection mat4 and the whole program will crash from 
	//lack of attribute setting
	material->getShader()->setUniform("u_Projection", getCore()->getCurrentCamera()->getProjection()); 
	//material->getShader()->setUniform("u_Projection", glm::perspective(glm::radians(45.0f), 800.0f/600.0f, 0.1f, 100.0f));
	material->getShader()->setMesh(mesh->getRendMesh());
	material->getShader()->render();
}

void MeshRenderer::setMesh(std::shared_ptr<Mesh> settingMesh)
{
	mesh = settingMesh;
}

void MeshRenderer::setMaterial(std::shared_ptr<Material> settingMaterial)
{
	material = settingMaterial;
}


}
