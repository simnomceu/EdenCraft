#ifndef DATA_CONTEXT_OPENGL_HPP
#define DATA_CONTEXT_OPENGL_HPP

#include "renderer/opengl/base_context_opengl.hpp"

#include <Windows.h>

namespace ece
{
	struct DataContextOpenGL
	{
		inline DataContextOpenGL(HGLRC context, HDC device, HWND handle): _context(context), _device(device), _windowHandle(handle) {}

		HGLRC _context;
		HDC _device;
		HWND _windowHandle;
	};
}

#endif // DATA_CONTEXT_OPENGL_HPP
