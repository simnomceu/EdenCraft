#pragma once


#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#pragma warning(pop)

#include "ColorGL.hpp"

class GLAdapter
{
public:
	GLAdapter();
	~GLAdapter();

	static void initGLContext();
	static void init3D();

	static void displayContextInfos();

	static void clearWindow();
	static void clearWindow(const Colors::Color color);

	static void setVAOBuffer(int vaoId);
	static void clearVAOBuffer();
};

