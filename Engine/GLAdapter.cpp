#include "GLAdapter.hpp"

#include "Constants.inl"

#include <iostream>


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

int GLAdapter::getNumberOfMonitors()
{
	int count = 0;
	glfwGetMonitors(&count);
	return count;
}

GLFWmonitor * GLAdapter::getMainMonitor()
{
	return glfwGetPrimaryMonitor();
}

GLFWmonitor * GLAdapter::getMonitor(const int monitorId)
{
	int count = 0;
	GLFWmonitor** monitors = glfwGetMonitors(&count);
	GLFWmonitor* monitor = nullptr;

	if (monitorId < count) {
		monitor = monitors[monitorId];
	}

	return monitor;
}
