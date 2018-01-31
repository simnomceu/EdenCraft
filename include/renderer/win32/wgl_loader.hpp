#ifndef WGL_LOADER_HPP
#define WGL_LOADER_HPP

#include "GL/glcorearb.h" 
#include "GL/glext.h" 
#include "GL/wglext.h"

#include <array>

namespace ece
{
	class WGLLoader
	{
	public:
		static WGLLoader & getInstance();

		~WGLLoader();

		HMODULE getLibrary();
		std::array<unsigned short int, 2> & getLatestVersionAvailable();

	private:
		WGLLoader();

		HMODULE _openglLib;
		std::array<unsigned short int, 2> _latestVersionAvailable;
	};
}

#endif // WGL_LOADER_HPP