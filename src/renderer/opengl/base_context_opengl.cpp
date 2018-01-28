#include "renderer/opengl/base_context_opengl.hpp"

#include "renderer/opengl/opengl.hpp"
#include "utility/log/service_logger.hpp"

namespace ece
{
	void BaseContextOpenGL::logInfos()
	{
		std::string renderer, version, shaderVersion;
		OpenGL::getString(InfoGL::RENDERER, renderer);
		OpenGL::getString(InfoGL::VERSION, version);
		OpenGL::getString(InfoGL::SHADING_LANGUAGE_VERSION, shaderVersion);

		ServiceLoggerLocator::getService().logInfo("Renderer: " + renderer);
		ServiceLoggerLocator::getService().logInfo("OpenGL version supported " + version);
		ServiceLoggerLocator::getService().logInfo("GLSL version supported " + shaderVersion);
	}
}