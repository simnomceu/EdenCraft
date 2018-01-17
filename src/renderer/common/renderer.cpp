#include "renderer/common/renderer.hpp"

#include "renderer/opengl/vao.hpp"

namespace ece
{
	Program Renderer::getProgram() const
	{
		int handle = 0;
		glGetIntegerv(GL_CURRENT_PROGRAM, &handle);
		return Program(static_cast<ProgramHandle>(handle));
	}

	void Renderer::drawPrimitives(const PrimitiveMode mode, const VAO & vao)
	{
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CW);

		vao.bind();
		glDrawArrays(mode, 0, 3);
	}
}