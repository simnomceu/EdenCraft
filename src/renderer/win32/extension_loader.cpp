#include "renderer/opengl/extension_loader.hpp"

#include "renderer/win32/wgl_loader.hpp"

#include "renderer/win32/wgl_extension.hpp"
#include "renderer/opengl/opengl_extension.hpp"
#include "utility/log/service_logger.hpp"

namespace ece
{
	WGLLoader & WGLLoader::getInstance()
	{
		static WGLLoader instance;
		return instance;
	}

	WGLLoader::~WGLLoader()
	{
		if (this->_openglLib != nullptr) {
			FreeLibrary(this->_openglLib);
			this->_openglLib = nullptr;
		}
	}

	WGLLoader::WGLLoader() : _openglLib(nullptr), _latestVersionAvailable()
	{
		HDC device = nullptr;
		HGLRC dummyContext = nullptr;

		auto windowHandle = CreateWindow(L"Static", L"", WS_DISABLED, 0, 0, 1, 1, nullptr, nullptr, nullptr, nullptr);
		if (windowHandle) {
			PIXELFORMATDESCRIPTOR pixelFormat;

			if (!wglGetCurrentContext()) {
				device = GetDC(windowHandle);
				if (!device) {
					throw std::runtime_error("OpenGL cannot be initialized beacause no device is currently available.");
				}

				if (!SetPixelFormat(device, 1, &pixelFormat)) {
					throw std::runtime_error("OpenGL cannot be initialized because no video mode fit with.");
				}
				dummyContext = wglCreateContext(device);
				if (!dummyContext) {
					throw std::runtime_error("OpenGL cannot be initialized because it is not possible to create a context.");
				}
				if (!wglMakeCurrent(device, dummyContext)) {
					throw std::runtime_error("OpenGL cannot be initialized because it is not possible to use a context.");
				}
			}
		}

		if (this->_openglLib == nullptr) {
			this->_openglLib = LoadLibrary(L"opengl32.dll");
		}

		std::string versionPtr(reinterpret_cast<const char *>(glGetString(GL_VERSION)));
		this->_latestVersionAvailable[0] = static_cast<unsigned short int>(std::stoi(versionPtr.substr(0, 1)));
		this->_latestVersionAvailable[1] = static_cast<unsigned short int>(std::stoi(versionPtr.substr(2, 1)));

		// dummy calls
		wglChoosePixelFormat(nullptr, nullptr, nullptr, 0, nullptr, nullptr); // create an infinite loop because it call getInstance while we are still in constructor
		wglCreateContextAttribs(nullptr, nullptr, nullptr);

		if (dummyContext != nullptr) {
			wglMakeCurrent(nullptr, nullptr);
			wglDeleteContext(dummyContext);
			dummyContext = nullptr;
			ReleaseDC(windowHandle, device);
			device = nullptr;
			DestroyWindow(windowHandle);
			windowHandle = nullptr;
		}
	}

	HMODULE WGLLoader::getLibrary()
	{
		return this->_openglLib;
	}

	std::array<unsigned short int, 2> & WGLLoader::getLatestVersionAvailable()
	{
		return this->_latestVersionAvailable;
	}

	void * loadOpenGLProc(const std::string & name)
	{
		auto proc = wglGetProcAddress(name.data());
		if (proc == nullptr) {
			proc = GetProcAddress(WGLLoader::getInstance().getLibrary(), name.data());
			if (proc == nullptr) {
				ServiceLoggerLocator::getService().logError(name + " cannot be loaded.");
			}
		}
		return static_cast<void *>(proc);
	}

	std::array<unsigned short int, 2> & getLatestVersionAvailable()
	{
		return WGLLoader::getInstance().getLatestVersionAvailable();
	}
}