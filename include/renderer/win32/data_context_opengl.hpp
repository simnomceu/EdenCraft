#ifndef DATA_CONTEXT_OPENGL_HPP
#define DATA_CONTEXT_OPENGL_HPP

#include "renderer/opengl/base_context_opengl.hpp"

#include <Windows.h>

namespace ece
{
	struct DataContextOpenGL
	{
		inline DataContextOpenGL(HGLRC context, HDC device, HWND handle): context(context), device(device), windowHandle(handle) {}

		HGLRC context;
		HDC device;
		HWND windowHandle;
	};
}

#endif // DATA_CONTEXT_OPENGL_HPP
