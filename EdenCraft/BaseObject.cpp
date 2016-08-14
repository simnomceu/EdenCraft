#include "BaseObject.hpp"

BaseObject::BaseObject(): vao(0), vbo(0)
{
	glGenVertexArrays(1, &this->vao); // generate new VAO with index ID.
	glBindVertexArray(this->vao); // link to the VAO.

	glGenBuffers(1, &this->vbo); // generate new VBO with index ID.
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo); // link to the VBO.
}


BaseObject::~BaseObject()
{
}

GLuint BaseObject::getVAO()
{
	return this->vao;
}

GLuint BaseObject::getVBO()
{
	return this->vbo;
}

void BaseObject::loadInMemory(const int nbVertices, float * vertices)
{
	// Define the VBO.
	glBufferData(GL_ARRAY_BUFFER, nbVertices * 3 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

	// Prepare the VAO
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
}

void BaseObject::deactivateBuffers()
{
	// Deativate the VAO.
	glEnableVertexAttribArray(0);
	// Deactivate the VBO.
	glBindVertexArray(0);
}
