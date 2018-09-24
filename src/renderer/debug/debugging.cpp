#include "renderer/debug/debugging.hpp"

#include "utility/log.hpp"
#include "renderer/opengl.hpp"

#include <string>

namespace ece
{
	namespace renderer
	{
		namespace debug
		{
			void checkErrors_(const char * file, const int line, const char * function)
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

					ServiceLoggerLocator::getService().logError("Error OpenGL: (" + std::to_string(static_cast<unsigned short int>(error)) + ") " + errorMessage + " in " + std::string(function) + " from " + std::string(file) + ":" + std::to_string(line) + ".");
					error = OpenGL::getError();
				}
			}

			void APIENTRY glDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei /*length*/, const GLchar *message, const void * /*userParam*/)
			{
				std::string debugMessage = " Debug OpenGL: (" + std::to_string(id) + "): " + std::string(message);

				switch (source)
				{
				case GL_DEBUG_SOURCE_API:             debugMessage += "[Source: API]"; break;
				case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   debugMessage += "[Source: Window System]"; break;
				case GL_DEBUG_SOURCE_SHADER_COMPILER: debugMessage += "[Source: Shader Compiler]"; break;
				case GL_DEBUG_SOURCE_THIRD_PARTY:     debugMessage += "[Source: Third Party]"; break;
				case GL_DEBUG_SOURCE_APPLICATION:     debugMessage += "[Source: Application]"; break;
				case GL_DEBUG_SOURCE_OTHER:           debugMessage += "[Source: Other]"; break;
				}

				switch (type)
				{
				case GL_DEBUG_TYPE_ERROR:               debugMessage += "[Type: Error]"; break;
				case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: debugMessage += "[Type: Deprecated Behaviour]"; break;
				case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  debugMessage += "[Type: Undefined Behaviour]"; break;
				case GL_DEBUG_TYPE_PORTABILITY:         debugMessage += "[Type: Portability]"; break;
				case GL_DEBUG_TYPE_PERFORMANCE:         debugMessage += "[Type: Performance]"; break;
				case GL_DEBUG_TYPE_MARKER:              debugMessage += "[Type: Marker]"; break;
				case GL_DEBUG_TYPE_PUSH_GROUP:          debugMessage += "[Type: Push Group]"; break;
				case GL_DEBUG_TYPE_POP_GROUP:           debugMessage += "[Type: Pop Group]"; break;
				case GL_DEBUG_TYPE_OTHER:               debugMessage += "[Type: Other]"; break;
				}

				switch (severity)
				{
				case GL_DEBUG_SEVERITY_HIGH:         debugMessage += "[Severity: high]"; break;
				case GL_DEBUG_SEVERITY_MEDIUM:       debugMessage += "[Severity: medium]"; break;
				case GL_DEBUG_SEVERITY_LOW:          debugMessage += "[Severity: low]"; break;
				case GL_DEBUG_SEVERITY_NOTIFICATION: debugMessage += "[Severity: notification]"; break;
				}
				if (severity == GL_DEBUG_SEVERITY_NOTIFICATION) {
					ServiceLoggerLocator::getService().logWarning(debugMessage);
				}
				else {
					ServiceLoggerLocator::getService().logError(debugMessage);
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece
