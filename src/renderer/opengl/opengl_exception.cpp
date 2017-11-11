#include "renderer/opengl/opengl_exception.hpp"

namespace ece
{
	OpenGLExtensionException::OpenGLExtensionException(const std::string & extension, const OptionOpenGL option)
	{
		this->setMessage("The extension % is not loaded. Load % to use it.", extension, option);
	}
}