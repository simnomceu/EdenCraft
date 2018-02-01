#include "renderer/opengl/opengl_exception.hpp"

namespace ece
{
	OpenGLExtensionException::OpenGLExtensionException(const std::string & extension)
	{
		this->setMessage("The extension % is not loaded", extension);
	}
}