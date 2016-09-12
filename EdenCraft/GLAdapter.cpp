#include "GLAdapter.hpp"

#include "GLFW\glfw3.h"
#include "Constants.inl"

#include <iostream>


GLAdapter::GLAdapter()
{
}


GLAdapter::~GLAdapter()
{
}

int GLAdapter::initGLFW()
{
	if (!glfwInit()) {
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Constants::GL_MAJOR_VERSION_EC);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Constants::GL_MINOR_VERSION_EC);
	glfwSwapInterval(0);

	return 0;
}

void GLAdapter::initGLContext()
{
	// Init Glew.
	// Required to use VAO & VBO.
	glewExperimental = GL_TRUE;

	GLint GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult)
	{
		std::cerr << "ERROR: " << glewGetErrorString(GlewInitResult) << std::endl;
	}
}

void GLAdapter::init3D()
{
	/* tell GL to only draw onto a pixel if the shape is closer to the viewer
	*/
	glEnable(GL_DEPTH_TEST); /* enable depth-testing */
							 /* with LESS depth-testing interprets a smaller value as "closer" */
	glDepthFunc(GL_LESS);

	// Reduce cost by disabling back rendering
	glEnable(GL_CULL_FACE); // cull face
	glCullFace(GL_BACK); // cull back face
	glFrontFace(GL_CW); // GL_CCW for counter clock-wise
}

void GLAdapter::displayContextInfos()
{
	std::cerr << "Renderer used: " << glGetString(GL_RENDERER) << std::endl;
	std::cerr << glGetString(GL_VERSION) << " used in an GLFW context." << std::endl;
}

void GLAdapter::clearWindow()
{
	GLAdapter::clearWindow(Colors::BLACK);
}

void GLAdapter::clearWindow(const Colors::Color color)
{
	glClearColor(color[0], color[1], color[2], 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLAdapter::setVAOBuffer(int vaoId)
{
	glBindVertexArray(vaoId);
}

void GLAdapter::clearVAOBuffer()
{
	GLAdapter::setVAOBuffer(0);
}

void GLAdapter::setVBOBuffer(int vboId)
{
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
}

void GLAdapter::clearVBOBuffer()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

int GLAdapter::generateVAO()
{
	GLuint vao;
	glGenBuffers(1, &vao);

	return vao;
}
