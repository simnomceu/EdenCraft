#ifndef CONTEXT_OPENGL_HPP
#define CONTEXT_OPENGL_HPP

#include "common_renderer/base_context_opengl.hpp"

namespace ece
{
	class ContextOpenGL: public BaseContextOpenGL
	{
	public:
		inline ContextOpenGL();
		ContextOpenGL(const ContextOpenGL & copy) = default;
		ContextOpenGL(ContextOpenGL && move) = default;

		~ContextOpenGL();

		ContextOpenGL & operator=(const ContextOpenGL & copy) = default;
		ContextOpenGL & operator=(ContextOpenGL && move) = default;

		virtual void create(const RenderWindow & window) override;
		virtual void swapBuffers() override;
		
	private:
		HGLRC context;
		HDC device;
		HWND windowHandle;
	};
}

#include "win32/context_opengl.inl"

#endif // CONTEXT_OPENGL_HPP
