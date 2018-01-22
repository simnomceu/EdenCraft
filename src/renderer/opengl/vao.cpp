#include "renderer/opengl/vao.hpp"

namespace ece
{
	VAO::VAO(): _handle(0)
	{
		OpenGL::genVertexArrays(this->_handle);
	}

	void VAO::bind() const
	{
		OpenGL::bindVertexArray(this->_handle);
	}
}