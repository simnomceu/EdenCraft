#ifndef CONTEXT_OPENGL_HPP
#define CONTEXT_OPENGL_HPP

#include "renderer/opengl/base_context_opengl.hpp"

namespace ece
{
	class ContextOpenGL: public BaseContextOpenGL
	{
	public:
		ContextOpenGL() = default;
		ContextOpenGL(const ContextOpenGL & copy) = default;
		ContextOpenGL(ContextOpenGL && move) = default;

		~ContextOpenGL() = default;

		ContextOpenGL & operator=(const ContextOpenGL & copy) = default;
		ContextOpenGL & operator=(ContextOpenGL && move) = default;

		virtual void create(const RenderWindow & window) override;
		virtual void swapBuffers() override;
	private:
	};
}

#include "renderer/cocoa/context_opengl.inl"

#endif // CONTEXT_OPENGL_HPP
