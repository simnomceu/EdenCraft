#include "GLAdapter.hpp"

#include <iostream>


GLAdapter::GLAdapter()
{
}


GLAdapter::~GLAdapter()
{
}

void GLAdapter::initGLContext()
{
	// Init Glew.
	// Required to use VAO & VBO.
	glewExperimental = GL_TRUE;
	glewInit();
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
	std::cerr << glGetString(GL_VERSION) << " used in an SFML context." << std::endl;
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
