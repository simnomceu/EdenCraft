#ifndef WGL_LOADER_HPP
#define WGL_LOADER_HPP

#include "GL/glcorearb.h" 
#include "GL/glext.h" 
#include "GL/wglext.h"

#include <array>

#include "utility/indexing/version.hpp"

namespace ece
{
	class WGLLoader
	{
	public:
		static WGLLoader & getInstance();

		~WGLLoader();

		FARPROC getProcAddress(const std::string & name);

		void initDummyContext();
		Version<2> & getLatestVersionAvailable();
		void terminateDummyContext();

	private:
		WGLLoader();

		HMODULE _openglLib;
		Version<2> _latestVersionAvailable;

		struct {
			HDC device;
			HGLRC context;
			HWND window;
		} _dummy;
	};
}

#endif // WGL_LOADER_HPP