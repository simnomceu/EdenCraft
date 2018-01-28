#include "renderer/opengl/vao.hpp"

namespace ece
{
	VAO::VAO(): _handle(0), nbVertices(0), _ibo()
	{
		OpenGL::genVertexArrays(this->_handle);
	}

	void VAO::bind() const
	{
		OpenGL::bindVertexArray(this->_handle);
	}

	void VAO::bindIndexBuffer() const
	{
		this->_ibo.bind();
	}

	void VAO::addIndices(const std::vector<unsigned int> & data, const BufferUsage usage)
	{
		if (this->nbVertices == 0) {
			this->nbVertices = data.size();
		}

		this->bind();
		this->_ibo.bufferData(data, usage);
	}
}