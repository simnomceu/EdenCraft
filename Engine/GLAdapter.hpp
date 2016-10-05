#pragma once


#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#include "GLFW\glfw3.h"
#pragma warning(pop)

#include "ColorGL.hpp"

class GLAdapter
{
public:
	static void init3D();

	static void clearWindow();
	static void clearWindow(const Colors::Color color);

	static void setVAOBuffer(int vaoId);
	static void clearVAOBuffer();

	static void setVBOBuffer(int vboId);
	static void clearVBOBuffer();

	static int generateVAO();
	static int generateVBO();
	static void attachVBOtoVAO(int vboId, int vaoId);


	/* ##### MONITORS ##### */
	static int getNumberOfMonitors();
	static GLFWmonitor* getMainMonitor();
	static GLFWmonitor* getMonitor(const int monitorId);
};

