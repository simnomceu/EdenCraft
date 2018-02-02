#include "renderer/opengl/extension_loader.hpp"

#include "renderer/win32/wgl_loader.hpp"

#include "renderer/win32/wgl_extension.hpp"
#include "utility/log/service_logger.hpp"

namespace ece
{
	void * loadOpenGLProc(const std::string & name)
	{
		auto proc = wglGetProcAddress(name.data());
		if (proc == nullptr) {
			proc = WGLLoader::getInstance().getProcAddress(name);//GetProcAddress(WGLLoader::getInstance().getLibrary(), name.data());
			if (proc == nullptr) {
				ServiceLoggerLocator::getService().logError(name + " cannot be loaded.");
			}
		}
		return static_cast<void *>(proc);
	}

	std::array<unsigned short int, 2> initLoader()
	{
		auto & loader = WGLLoader::getInstance();
		loader.initDummyContext();
		std::array<unsigned short int, 2> version = loader.getLatestVersionAvailable();
		loader.terminateDummyContext();
		return version;
	}
}