#include "Material.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Core.h"
#include "Exception.h"
#include <fstream>

namespace gepEngine
{

void Material::load(std::string path)
{
	std::ifstream file(path);

	if(!file.is_open())
	{
		throw Exception("Failed to open Shader");
	}

	std::string obj;
	std::string line;

	while (!file.eof())
	{
		std::getline(file, line);
		obj += line + "\n";
	}

	sha = getCore()->getContext()->createShader();
	sha->parse(obj);

}

void Material::addTexture(std::string path)
{
	int w = 0;
	int h = 0;
	int bpp = 0;

	unsigned char *data = stbi_load(path.c_str(), &w, &h, &bpp, 3);

	if(!data)
	{
		throw Exception("Failed to open texture");
	}

	tex = getCore()->getContext()->createTexture();

	tex->setSize(w, h);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int r = y * w * 3 + x * 3;

			tex->setPixel(x, y, glm::vec3(
					data[r] / 255.0f,
					data[r + 1] / 255.0f,
					data[r + 2] / 255.0f));
		}
	}

	stbi_image_free(data);

}

std::shared_ptr<rend::Shader> Material::getShader()
{
	return sha;
}

std::shared_ptr<rend::Texture> Material::getTexture()
{
	return tex;
}




}
