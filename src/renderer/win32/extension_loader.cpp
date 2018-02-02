#include "renderer/opengl/extension_loader.hpp"

#include "renderer/win32/wgl_loader.hpp"

#include "renderer/win32/wgl_extension.hpp"
#include "utility/log/service_logger.hpp"

#ifdef _MSC_VER
#	undef min
#	undef max
#endif

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

	Version<2> initLoader(const Version<2> & minVersionGL, const Version<2> & maxVersionGL)
	{
		auto & loader = WGLLoader::getInstance();
		loader.initDummyContext();
		auto version = loader.getLatestVersionAvailable();
		loader.terminateDummyContext();
		return min(max(minVersionGL, version), maxVersionGL);
	}
}