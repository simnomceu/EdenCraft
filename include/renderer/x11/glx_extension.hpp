#ifndef GLX_EXTENSION_HPP
#define GLX_EXTENSION_HPP

#include "renderer/opengl/opengl_extension.hpp"

namespace ece
{
	class GLXExtension: public OpenGLExtension
	{
	public:
		GLXExtension() = default;
		GLXExtension(const GLXExtension & copy) = default;
		GLXExtension(GLXExtension && move) = default;

		~GLXExtension() = default;

		GLXExtension & operator=(const GLXExtension & copy) = default;
		GLXExtension & operator=(GLXExtension && move) = default;

		virtual void init(const OptionOpenGL options) override;

	protected:
		virtual void * loadOpenGLProc(const std::string & name) override;
	};
}

#include "renderer/x11/glx_extension.inl"

#endif // GLX_EXTENSION_HPP
