#include "renderer/opengl/base_context_opengl.hpp"

#include "renderer/opengl/opengl.hpp"
#include "utility/log/service_logger.hpp"

namespace ece
{
	void BaseContextOpenGL::logInfos()
	{
		ServiceLoggerLocator::getService().logInfo("Renderer: " + OpenGL::getString(InfoGL::RENDERER));
		ServiceLoggerLocator::getService().logInfo("OpenGL version supported " + OpenGL::getString(InfoGL::VERSION));
		ServiceLoggerLocator::getService().logInfo("GLSL version supported " + OpenGL::getString(InfoGL::SHADING_LANGUAGE_VERSION));
	}
}