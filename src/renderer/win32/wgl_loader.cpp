#include "renderer/win32/wgl_loader.hpp"

#include "renderer/win32/wgl_extension.hpp"
#include "renderer/opengl/opengl_extension.hpp"

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

	FARPROC WGLLoader::getProcAddress(const std::string & name)
	{
		return GetProcAddress(this->_openglLib, name.data());
	}

	WGLLoader::WGLLoader() : _openglLib(nullptr), _latestVersionAvailable(), _dummy{nullptr, nullptr, nullptr}
	{
	}

	void WGLLoader::initDummyContext()
	{
		this->_dummy.window = CreateWindow(L"Static", L"", WS_DISABLED, 0, 0, 1, 1, nullptr, nullptr, nullptr, nullptr);
		if (this->_dummy.window) {
			this->_dummy.device = GetDC(this->_dummy.window);
			if (!this->_dummy.device) {
				throw std::runtime_error("OpenGL cannot be initialized beacause no device is currently available.");
			}

			PIXELFORMATDESCRIPTOR pixelFormat;
			ZeroMemory(&pixelFormat, sizeof(pixelFormat));
			pixelFormat.nSize = sizeof(pixelFormat);
			pixelFormat.nVersion = 1;
			pixelFormat.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
			pixelFormat.iPixelType = PFD_TYPE_RGBA;
			pixelFormat.cColorBits = 32;
			pixelFormat.cAlphaBits = 8;
			pixelFormat.cDepthBits = 24;

			if (!ChoosePixelFormat(this->_dummy.device, &pixelFormat)) {
				throw std::runtime_error("No pixel format choosen for OpenGL dummy context.");
			}

			if (!SetPixelFormat(this->_dummy.device, 1, &pixelFormat)) {
				throw std::runtime_error("OpenGL cannot be initialized because no video mode fit with.");
			}

			this->_dummy.context = wglCreateContext(this->_dummy.device);
			if (!this->_dummy.context) {
				throw std::runtime_error("OpenGL cannot be initialized because it is not possible to create a context.");
			}
			if (!wglMakeCurrent(this->_dummy.device, this->_dummy.context)) {
				throw std::runtime_error("OpenGL cannot be initialized because it is not possible to use a context.");
			}
		}

		if (this->_openglLib == nullptr) {
			this->_openglLib = LoadLibrary(L"opengl32.dll");
		}

		wglChoosePixelFormat(nullptr, nullptr, nullptr, 0, nullptr, nullptr); // dummy call
		wglCreateContextAttribs(nullptr, nullptr, nullptr); // dummy call
	}

	std::array<unsigned short int, 2> & WGLLoader::getLatestVersionAvailable()
	{
		if (this->_latestVersionAvailable == std::array<unsigned short int, 2>{ 0, 0 }) {
		std::string versionPtr(reinterpret_cast<const char *>(glGetString(GL_VERSION)));
		this->_latestVersionAvailable[0] = static_cast<unsigned short int>(std::stoi(versionPtr.substr(0, 1)));
		this->_latestVersionAvailable[1] = static_cast<unsigned short int>(std::stoi(versionPtr.substr(2, 1)));
		}
		return this->_latestVersionAvailable;
	}

	void WGLLoader::terminateDummyContext()
	{
		if (this->_dummy.context != nullptr) {
			wglMakeCurrent(nullptr, nullptr);
			wglDeleteContext(this->_dummy.context);
			this->_dummy.context = nullptr;
			ReleaseDC(this->_dummy.window, this->_dummy.device);
			this->_dummy.device = nullptr;
			DestroyWindow(this->_dummy.window);
			this->_dummy.window = nullptr;
		}
	}
}