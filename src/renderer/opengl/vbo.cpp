#include "renderer/opengl/vbo.hpp"

namespace ece
{
	VBO::VBO(const BufferType type): handle(0), type(type)
	{
		OpenGL::genBuffers(this->handle);
	}

	VBO::VBO() : handle(0), type(ARRAY_BUFFER)
	{
		OpenGL::genBuffers(this->handle);
	}

	void VBO::bind()
	{
		OpenGL::bindBuffer(this->type, this->handle);
	}
}