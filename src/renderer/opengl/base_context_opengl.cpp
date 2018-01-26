#include "renderer/opengl/base_context_opengl.hpp"

#include "renderer/opengl/opengl.hpp"
#include "utility/log/service_logger.hpp"

namespace ece
{
	void BaseContextOpenGL::logInfos()
	{
		if (glGetString) {
			auto renderer = reinterpret_cast<const char *>(glGetString(GL_RENDERER));
			auto version = reinterpret_cast<const char *>(glGetString(GL_VERSION));
			auto shaderVersion = reinterpret_cast<const char *>(glGetString(GL_SHADING_LANGUAGE_VERSION));

			ServiceLoggerLocator::getService().logInfo("Renderer: " + std::string(renderer));
			ServiceLoggerLocator::getService().logInfo("OpenGL version supported " + std::string(version));
			ServiceLoggerLocator::getService().logInfo("GLSL version supported " + std::string(shaderVersion));
		}
	}
}