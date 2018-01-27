#include "renderer/opengl/vbo.hpp"

namespace ece
{
	VBO::VBO(const BufferType type): _handle(0), _type(type)
	{
		OpenGL::genBuffers(this->_handle);
	}

	VBO::VBO() : _handle(0), _type(BufferType::ARRAY_BUFFER)
	{
		OpenGL::genBuffers(this->_handle);
	}

	void VBO::bind()
	{
		OpenGL::bindBuffer(this->_type, this->_handle);
	}
}