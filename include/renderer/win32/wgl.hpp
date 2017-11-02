#ifndef WGL_HPP
#define WGL_HPP

#include "common_renderer/opengl.hpp"
#include "GL/wglext.h"

namespace ece
{
	class WGL: public OpenGL
	{
	public:
		inline WGL();
		WGL(const WGL & copy) = default;
		WGL(WGL && move) = default;

		~WGL();

		WGL & operator=(const WGL & copy) = default;
		WGL & operator=(WGL && move) = default;

		virtual void init(const OptionOpenGL options) override;

	protected:
		virtual void * loadOpenGLProc(const std::string & name) override;

		virtual void loadPlatformExtensions() override;
	
	private:
		HMODULE openglLib;
	};
}

extern PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormat;
extern PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribs;

#include "win32/wgl.inl"

#endif // WGL_HPP
