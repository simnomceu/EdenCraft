#pragma once

#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#pragma warning(pop)

class TypeGL
{
public:
	template <class T>
	static int whatIsIt();
};