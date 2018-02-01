#ifndef OPENGL_EXCEPTION_HPP
#define OPENGL_EXCEPTION_HPP

#include "utility/debug/exception.hpp"
#include "renderer/opengl/opengl_extension.hpp"

namespace ece
{
	class OpenGLExtensionException : public Exception
	{
	public:
		OpenGLExtensionException(const std::string & extension);
	};
}

#endif // OPENGL_EXCEPTION_HPP
