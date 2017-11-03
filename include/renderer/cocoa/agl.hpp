#ifndef AGL_HPP
#define AGL_HPP

#include "renderer/common_renderer/opengl.hpp"

namespace ece
{
	class AGL: public OpenGL
	{
	public:
		AGL() = default;
		AGL(const AGL & copy) = default;
		AGL(AGL && move) = default;

		~AGL() = default;

		AGL & operator=(const AGL & copy) = default;
		AGL & operator=(AGL && move) = default;

		virtual void init(const OptionOpenGL options) override;

	protected:
		virtual void * loadOpenGLProc(const std::string & name) override;

	};
}

#include "renderer/cocoa/agl.inl"

#endif // AGL_HPP
