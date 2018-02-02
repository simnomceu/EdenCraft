#include "renderer/opengl/vbo.hpp"

namespace ece
{
	VBO::VBO(const BufferType type): _handle(0), _type(type)
	{
		this->_handle = OpenGL::genBuffers();
	}

	VBO::VBO() : _handle(0), _type(BufferType::ARRAY_BUFFER)
	{
		this->_handle = OpenGL::genBuffers();
	}

	void VBO::bind()
	{
		OpenGL::bindBuffer(this->_type, this->_handle);
	}
}