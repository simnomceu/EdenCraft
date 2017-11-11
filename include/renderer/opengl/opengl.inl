#include "opengl.hpp"
namespace ece
{
	template<class T> 
	void OpenGL::uniform(const UniformHandle uniform, const T value)
	{
		throw std::runtime_error("A uniform cannot be set with this type.");
	}

	template<class T>
	void OpenGL::bufferData(const BufferType type, const std::vector<T> & data, const BufferUsage usage)
	{
		if (!glBufferData) {
			throw OpenGLExtensionException("glBufferData", BUFFER_OBJECTS);
		}

		const GLvoid * dataPtr = data.data();
		glBufferData(type, data.size() * sizeof(T), dataPtr, usage);
		OpenGL::checkErrors();
	}

	template<class T>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset)
	{
		throw std::runtime_error("Vertex attribute pointer of this type cannot be passed.");
	}

	template<>
	void OpenGL::vertexAttribPointer<short>(const int location, const int size, const bool normalized, const int offset)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, SHORT, normalized, offset, nullptr);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer<unsigned short>(const int location, const int size, const bool normalized, const int offset)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, UNSIGNED_SHORT, normalized, offset, nullptr);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer<int>(const int location, const int size, const bool normalized, const int offset)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, INT, normalized, offset, nullptr);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer<unsigned int>(const int location, const int size, const bool normalized, const int offset)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, UNSIGNED_INT, normalized, offset, nullptr);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer<float>(const int location, const int size, const bool normalized, const int offset)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, FLOAT, normalized, offset, nullptr);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer<double>(const int location, const int size, const bool normalized, const int offset)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, DOUBLE, normalized, offset, nullptr);
		OpenGL::checkErrors();
	}

	template<class T>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<T> & data)
	{
		throw std::runtime_error("Vertex attribute pointer of this type cannot be passed.");
	}

	template<>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<short> & data)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, SHORT, normalized, offset, data.data());
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<unsigned short> & data)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, UNSIGNED_SHORT, normalized, offset, data.data());
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<int> & data)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, INT, normalized, offset, data.data());
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<unsigned int> & data)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, UNSIGNED_INT, normalized, offset, data.data());
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<float> & data)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, FLOAT, normalized, offset, data.data());
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<double> & data)
	{
		if (!glVertexAttribPointer) {
			throw OpenGLExtensionException("glVertexAttribPointer", VERTEX_ARRAYS);
		}
		glVertexAttribPointer(location, size, DOUBLE, normalized, offset, data.data());
		OpenGL::checkErrors();
	}
}