#pragma once

#include <memory>
#include <vector>
#include <iostream>

#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#pragma warning(pop)

#include "TypeGL.hpp"
#include "ShaderScript.hpp"

class BaseObject
{
public:
	enum DataType : int {
		VERTICE = 0,
		COLOR = 1
	};

	class Matrix;
	class Texture;

	BaseObject();
	virtual ~BaseObject() = 0;

	void applyTransformation(Matrix & transformation);
	void applyTexture(Texture & texture);
	void applyShaders(std::string vsScript, std::string fsScript);
	void applyShadersFromFiles(std::string vsFile, std::string fsFile);

	GLuint getVAO();
	void prepareShaders();
protected:
	template <typename T>
	void submitData(DataType type, std::vector<T> & data);

	template <typename T>
	void submitVertices(std::vector<T> & data);
	template <typename T>
	void submitColors(std::vector<T> & data);

	GLuint vaoId;
	GLuint vboIds[2];
	ShaderScript shaderScript;
};



template<typename T>
void BaseObject::submitData(DataType type, std::vector<T>& data)
{
	switch (type) {
	case BaseObject::VERTICE:
		this->submitVertices(data);
		break;
	case BaseObject::COLOR:
		this->submitColors(data);
		break;
	default:
		std::cerr << "This kind of data cannot be submited yet for a model." << std::endl;
		break;
	}
}

template<typename T>
void BaseObject::submitVertices(std::vector<T>& data)
{
	// Generate the VBO id.
	glGenBuffers(1, &this->vboIds[BaseObject::VERTICE]);
	// Push the VBO in the buffer to use it.
	glBindBuffer(GL_ARRAY_BUFFER, this->vboIds[BaseObject::VERTICE]);

	// Set the data in the VBO via the buffer.
	// add guard : if data.size() == 0, there is an error here (maybe guard in the caller method
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(T), &data[0], GL_STATIC_DRAW);

	// Select the VAO to use.
	glBindVertexArray(this->vaoId);
	
	// Assign the VBO in the VAO.
	glVertexAttribPointer((GLuint)BaseObject::VERTICE, 3, TypeGL::whatIsIt<T>(), GL_FALSE, 0, nullptr);

	// Activate the VBO in the VAO.
	glEnableVertexAttribArray(BaseObject::VERTICE);
}

template<typename T>
void BaseObject::submitColors(std::vector<T>& data)
{
	// Generate the VBO id.
	glGenBuffers(1, &this->vboIds[BaseObject::COLOR]);
	// Push the VBO in the buffer to use it.
	glBindBuffer(GL_ARRAY_BUFFER, this->vboIds[BaseObject::COLOR]);

	// Set the data in the VBO via the buffer.
	// add guard : if data.size() == 0, there is an error here (maybe guard in the caller method
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(T), &data[0], GL_STATIC_DRAW);

	// Select the VAO to use.
	glBindVertexArray(this->vaoId);

	// Assign the VBO in the VAO.
	glVertexAttribPointer((GLuint)BaseObject::COLOR, 3, TypeGL::whatIsIt<T>() , GL_FALSE, 0, nullptr);

	// Activate the VBO in the VAO.
	glEnableVertexAttribArray(BaseObject::COLOR);
}
