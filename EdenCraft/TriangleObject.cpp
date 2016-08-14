#include "TriangleObject.hpp"

TriangleObject::TriangleObject(): BaseObject()
{
	float* vertices = new float[9];
	vertices[0] = 0.0f; vertices[1] = 0.0f; vertices[2] = 0.0f;
	vertices[3] = 1.0f; vertices[4] = 0.0f; vertices[5] = 0.0f;
	vertices[6] = 0.5f; vertices[7] = 1.0f; vertices[8] = 0.0f;

	this->loadInMemory(3, vertices);
	this->deactivateBuffers();

	delete[] vertices;
}


TriangleObject::~TriangleObject()
{
}
