#include "renderer/opengl/vbo.hpp"

namespace ece
{
	template<class T> 
	void VAO::addAttribute(const int location, const int size, const bool normalized, const int offset,
		const BufferType type, const std::vector<T> & data, const BufferUsage usage)
	{
		this->bind();
		OpenGL::enableVertexAttribArray(location);

		VBO vbo(type);
		vbo.bufferData(data, usage);
		OpenGL::vertexAttribPointer<T>(location, size, normalized, offset);
	}

	template<class T>
	void VAO::addAttributeWithoutBuffer(const int location, const int size, const bool normalized, const int offset,
		const BufferType type, std::vector<T> & data, const BufferUsage usage)
	{
		// BUG: somewhere here
		this->bind();
		OpenGL::enableVertexAttribArray(location);

		OpenGL::vertexAttribPointer<T>(location, size, normalized, offset, data);
	}

	inline unsigned int VAO::getNbVertices() const { return this->nbVertices; }
}