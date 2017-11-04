#ifndef GLX_HPP
#define GLX_HPP

#include "renderer/common/opengl.hpp"

namespace ece
{
	class GLX: public OpenGL
	{
	public:
		GLX() = default;
		GLX(const GLX & copy) = default;
		GLX(GLX && move) = default;

		~GLX() = default;

		GLX & operator=(const GLX & copy) = default;
		GLX & operator=(GLX && move) = default;

		virtual void init(const OptionOpenGL options) override;

	protected:
		virtual void * loadOpenGLProc(const std::string & name) override;
	};
}

#include "renderer/x11/glx.inl"

#endif // GLX_HPP
