#include "renderer/opengl/vao.hpp"

namespace ece
{
	VAO::VAO(): handle(0)
	{
		OpenGL::genVertexArrays(this->handle);
	}

	void VAO::bind() const
	{
		OpenGL::bindVertexArray(this->handle);
	}
}