#include "TriangleObject.hpp"

#include <vector>

TriangleObject::TriangleObject(): BaseObject()
{
	std::vector<float> vertices({ 0.0f,	0.5f, 0.0f,
								  0.5f, -0.5f, 0.0f,
								  -0.5f, -0.5f,	0.0f });

	std::vector<float> colors({ 1.0f, 0.0f, 0.0f,
								0.0f, 0.0f, 1.0f,
								1.0f, 1.0f, 0.0f });

	this->submitData<float>(VERTICE, vertices);
	this->submitData<float>(COLOR, colors);

	vertices.clear();
	colors.clear();

	std::string vs = "Basic.vert";
	std::string fs = "Basic.frag";
	this->applyShadersFromFiles(vs, fs);
}


TriangleObject::~TriangleObject()
{
}
