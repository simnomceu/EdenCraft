#include "TriangleObject.hpp"

#include <vector>

TriangleObject::TriangleObject(): BaseObject()
{
	std::vector<float> vertices({ 0.0f,	0.5f, 0.0f,
								  0.5f, -0.5f, 0.0f,
								  -0.5f, -0.5f,	0.0f });

	std::vector<float> colors({ 1.0f, 0.0f, 0.0f,
								0.0f, 1.0f, 0.0f,
								0.0f, 1.0f, 1.0f });

	this->submitData<float>(VERTICE, vertices);
	this->submitData<float>(COLOR, colors);

	vertices.clear();
	colors.clear();

	const char * vs = "#version 450\nlayout(location = 0) in vec3 in_vertices;layout(location = 1) in vec3 in_colors;out vec3 pass_color;void main(void) {gl_Position = vec4(in_vertices, 1.0);pass_color = in_colors;}";
	const char * fs = "#version 450\nin vec3 pass_color;out vec4 out_color;void main(void) {out_color = vec4(pass_color, 1.0);}";
	this->applyShaders(vs, fs);
}


TriangleObject::~TriangleObject()
{
}
