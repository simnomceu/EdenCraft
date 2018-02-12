#ifndef CONTEXT_OPENGL_HPP
#define CONTEXT_OPENGL_HPP

#include "renderer/opengl/base_context_opengl.hpp"
#include "utility/pattern/pimpl.hpp"

namespace ece
{
	struct DataContextOpenGL;

	class ContextOpenGL: public BaseContextOpenGL
	{
	public:
		ContextOpenGL();
		ContextOpenGL(const ContextOpenGL & copy) = default;
		ContextOpenGL(ContextOpenGL && move) = default;

		~ContextOpenGL();

		ContextOpenGL & operator=(const ContextOpenGL & copy) = default;
		ContextOpenGL & operator=(ContextOpenGL && move) = default;

		virtual void create(const RenderWindow & window) override;
		virtual void swapBuffers() override;

		virtual void setCurrent() override;

	private:
		Pimpl<DataContextOpenGL> _data;
	};
}

#endif // !CONTEXT_OPENGL_HPP
