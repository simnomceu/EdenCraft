#ifndef WGL_EXTENSION_HPP
#define WGL_EXTENSION_HPP

#include "renderer/opengl/opengl_extension.hpp"
#include "GL/wglext.h"

namespace ece
{
	class WGLExtension : public OpenGLExtension
	{
	public:
		inline WGLExtension();
		WGLExtension(const WGLExtension & copy) = default;
		WGLExtension(WGLExtension && move) = default;

		~WGLExtension();

		WGLExtension & operator=(const WGLExtension & copy) = default;
		WGLExtension & operator=(WGLExtension && move) = default;

		virtual std::array<int, 2> init(const OptionOpenGL options) override;

	protected:
		virtual void * loadOpenGLProc(const std::string & name) override;

		virtual void loadPlatformExtensions() override;
	
	private:
		HMODULE _openglLib;
	};
}

#include "renderer/win32/wgl_extension.inl"

#endif // WGL_EXTENSION_HPP
