#ifndef OPENGL_EXTENSION_HPP
#define OPENGL_EXTENSION_HPP

#include <string>
#include "GL/glcorearb.h"
#include "GL/glext.h"

namespace ece
{
	inline GLenum glGetError()
	{
		static auto proxy = OpenGLExtension::loadOpenGLProcT<PFNGLGETERRORPROC>("glGetError");
		return proxy();
	}
}

#include "renderer/opengl/opengl_extension.inl"

#endif // OPENGL_EXTENSION_HPP
