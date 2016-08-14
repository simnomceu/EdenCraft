#pragma once

#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#pragma warning(pop)

// An object extended this base should be constructed like this :
//			- construct the base
//			- prepare the vertices
//			- loadInMemory
//			- deactivate the buffers
//			- clear the array of vertices from memory

class BaseObject
{
public:
	BaseObject();
	virtual ~BaseObject();

	GLuint getVAO();
	GLuint getVBO();

protected:
	void loadInMemory(const int nbVertices, float* vertices);
	void deactivateBuffers();

private:
	GLuint vao;
	GLuint vbo;
};

