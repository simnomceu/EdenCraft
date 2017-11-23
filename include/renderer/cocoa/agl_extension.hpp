#ifndef AGL_EXTENSION_HPP
#define AGL_EXTENSION_HPP

#include "renderer/opengl/opengl_extension.hpp"

namespace ece
{
	class AGLExtension: public OpenGLExtension
	{
	public:
		AGLExtension() = default;
		AGLExtension(const AGLExtension & copy) = default;
		AGLExtension(AGLExtension && move) = default;

		~AGLExtension() = default;

		AGLExtension & operator=(const AGLExtension & copy) = default;
		AGLExtension & operator=(AGLExtension && move) = default;

		virtual void init(const OptionOpenGL options) override;

	protected:
		virtual void * loadOpenGLProc(const std::string & name) override;

	};
}

#include "renderer/cocoa/agl_extension.inl"

#endif // AGL_EXTENSION_HPP
