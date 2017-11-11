#include "renderer/common/renderer.hpp"

namespace ece
{
	Program Renderer::getProgram() const
	{
		int handle = 0;
		glGetIntegerv(GL_CURRENT_PROGRAM, &handle);
		return Program(handle);
	}

	void Renderer::drawPrimitives(const PrimitiveMode mode, const VAO & vao)
	{
	}
}