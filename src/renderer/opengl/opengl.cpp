#include "renderer/opengl/opengl.hpp"

#include "utility/log/service_logger.hpp"

namespace ece
{
	std::array<unsigned short int, 2> OpenGL::_latestVersion{2, 1};

	void OpenGL::init()
	{
		auto version = getLatestVersionAvailable();
		if (version != std::array<unsigned short int, 2>{0, 0}) {
			OpenGL::_latestVersion = version;
		}
	}

	void OpenGL::checkErrors(const std::string & location)
	{
		auto error(OpenGL::getError());
		while (error != ErrorGL::NO_ERROR) {
			std::string errorMessage;

			switch (error) {
			case ErrorGL::INVALID_ENUM:	errorMessage = "INVALID_ENUM"; break;
			case ErrorGL::INVALID_VALUE: errorMessage = "INVALID_VALUE"; break;
			case ErrorGL::INVALID_OPERATION: errorMessage = "INVALID_OPERATION"; break;
			case ErrorGL::INVALID_FRAMEBUFFER_OPERATION: errorMessage = "INVALID_FRAMEBUFFER_OPERATION"; break;
			case ErrorGL::OUT_OF_MEMORY: errorMessage = "OUT_OF_MEMORY"; break;
			case ErrorGL::STACK_UNDERFLOW: errorMessage = "STACK_UNDERFLOW"; break;
			case ErrorGL::STACK_OVERFLOW: errorMessage = "STACK_OVERFLOW"; break;
			default: break;
			}

			ServiceLoggerLocator::getService().logError("Error OpenGL: (" + std::to_string(static_cast<unsigned short int>(error)) + ") " + errorMessage + " in " + location + ".");
			error = OpenGL::getError();
		}
	}
}