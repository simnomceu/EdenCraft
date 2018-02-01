#include "renderer/opengl/opengl_extension.hpp"

namespace ece
{
	inline unsigned short int OpenGL::getLatestMinorVersion() { return OpenGL::_latestVersion[1]; }

	inline unsigned short int OpenGL::getLatestMajorVersion() { return OpenGL::_latestVersion[0]; }

	inline ErrorGL OpenGL::getError() { return static_cast<ErrorGL>(glGetError()); }

	inline void OpenGL::clear(const Bitfield mask)
	{
		glClear(static_cast<GLbitfield>(mask));
		OpenGL::checkErrors("OpenGL::clear");
	}

	inline void OpenGL::clearColor(const float r, const float g, const float b, const float a)
	{
		glClearColor(r, g, b, a);
		OpenGL::checkErrors("OpenGL::clearColor");
	}

	inline std::string OpenGL::getString(const InfoGL parameter)
	{
		const char * tmp = reinterpret_cast<const char *>(glGetString(static_cast<GLenum>(parameter)));
		OpenGL::checkErrors("OpenGL::getString");
		return std::string(tmp);
	}

	inline Handle OpenGL::genBuffers()
	{
		GLuint handle = 0;
		glGenBuffers(1, &handle);
		OpenGL::checkErrors("OpenGL::genBuffers");
		return static_cast<Handle>(handle);
	}

	inline std::vector<Handle> OpenGL::genBuffers(const int count)
	{
		std::vector<Handle> handles;
		if (count != 0) {
			handles.resize(handles.size() + count);
			glGenBuffers(count, reinterpret_cast<GLuint *>(&handles.back() - count + 1));
			OpenGL::checkErrors("OpenGL::genBuffers");
		}
		return handles;
	}

	inline void OpenGL::bindBuffer(const BufferType type, const Handle handle)
	{
		glBindBuffer(static_cast<GLenum>(type), static_cast<GLuint>(handle));
		OpenGL::checkErrors("OpenGL::bindBuffer");
	}

	inline Handle OpenGL::createProgram()
	{
		auto programHandle = glCreateProgram();
		OpenGL::checkErrors("OpenGL::createProgram");
		return static_cast<Handle>(programHandle);
	}

	inline void OpenGL::enable(const Capability cap)
	{
		glEnable(static_cast<GLenum>(cap));
		OpenGL::checkErrors("OpenGL::enable");
	}

	inline void OpenGL::disable(const Capability cap)
	{
		glDisable(static_cast<GLenum>(cap));
		OpenGL::checkErrors("OpenGL::disable");
	}

	inline void OpenGL::enableIndexed(const Capability cap, const unsigned short int index)
	{
		glEnablei(static_cast<GLenum>(cap), index);
		OpenGL::checkErrors("OpenGL::enableIndexed");
	}

	inline void OpenGL::disableIndexed(const Capability cap, const unsigned short int index)
	{
		glDisablei(static_cast<GLenum>(cap), index);
		OpenGL::checkErrors("OpenGL::disableIndexed");
	}

	inline void OpenGL::cullFace(const CullFaceMode mode)
	{
		glCullFace(static_cast<GLenum>(mode));
		OpenGL::checkErrors("OpenGL::cullFace");
	}

	inline void OpenGL::frontFace(const FrontFaceMode mode)
	{
		glFrontFace(static_cast<GLenum>(mode));
		OpenGL::checkErrors("OpenGL::frontFace");
	}

	inline void OpenGL::depthFunc(const DepthFunctionCondition condition)
	{
		glDepthFunc(static_cast<GLenum>(condition));
		OpenGL::checkErrors("OpenGL::depthFunc");
	}

	inline void OpenGL::getInteger(const Parameter parameter, int & data)
	{
		GLint tmp;
		glGetIntegerv(static_cast<GLenum>(parameter), &tmp);
		OpenGL::checkErrors("OpenGL::getInteger");
		data = static_cast<int>(tmp);
	}
	/*
	inline void OpenGL::getIntegers(const Parameter parameter, std::vector<int> & data)
	{
		std::vector<GLint> tmp;
		glGetIntegerv(static_cast<GLenum>(parameter), tmp.data());
		OpenGL::checkErrors("OpenGL::getIntegers");
		std::copy(tmp.begin(), tmp.end(), data.begin());
	}
	*/
	inline Handle OpenGL::createShader(const ShaderType type)
	{
		GLuint shaderHandle = glCreateShader(static_cast<GLenum>(type));
		OpenGL::checkErrors("OpenGL::createShader");
		return static_cast<Handle>(shaderHandle);
	}

	inline void OpenGL::shaderSource(const Handle handle, const std::string & source)
	{
		auto sourcePtr = source.data();
		glShaderSource(handle, 1, &sourcePtr, nullptr); // TODO: add the length of the source
		OpenGL::checkErrors("OpenGL::shaderSource");
	}

	inline void OpenGL::shaderSource(const Handle handle, const std::vector<std::string>& source)
	{
		std::vector<const char*> sourcesPtr{};
		for (const auto& string : source) {
			sourcesPtr.push_back(string.data());
		}
		glShaderSource(handle, 1, sourcesPtr.data(), nullptr); // TODO: add the lengths of the sources
		OpenGL::checkErrors("OpenGL::shaderSource");
	}

	inline void OpenGL::compileShader(const Handle handle)
	{
		glCompileShader(handle);
		OpenGL::checkErrors("OpenGL::compileShader");
	}
	
	inline void OpenGL::deleteShader(const Handle handle)
	{
		glDeleteShader(handle);
		OpenGL::checkErrors("OpenGL::deleteShader");
	}

	inline void OpenGL::attachShader(const Handle program, const Handle shader)
	{
		glAttachShader(program, shader);
		OpenGL::checkErrors("OpenGL::attachShader");
	}

	inline void OpenGL::linkProgram(const Handle handle)
	{
		glLinkProgram(handle);
		OpenGL::checkErrors("OpenGL::linkProgram");
	}

	inline void OpenGL::useProgram(const Handle handle)
	{
		glUseProgram(handle);
		OpenGL::checkErrors("OpenGL::useProgram");
	}
/*
	inline Handle OpenGL::getUniformLocation(const Handle handle, const std::string & uniform)
	{
		auto location = glGetUniformLocation(handle, uniform.data());
		OpenGL::checkErrors("OpenGL::getUniformLocation");
		return static_cast<Handle>(location);
	}
	*/
	inline void OpenGL::genVertexArrays(Handle & handle)
	{
		glGenVertexArrays(1, reinterpret_cast<GLuint *>(&handle));
		OpenGL::checkErrors("OpenGL::genVertexArrays");
	}

	inline 	void OpenGL::genVertexArrays(const int count, std::vector<Handle>& handles)
	{
		if (count != 0) {
			handles.resize(handles.size() + count);
			glGenVertexArrays(count, reinterpret_cast<GLuint *>(&handles.back() - count + 1));
			OpenGL::checkErrors("OpenGL::genVertexArrays");
		}
	}

	inline void OpenGL::bindVertexArray(const Handle handle)
	{
		glBindVertexArray(handle);
		OpenGL::checkErrors("OpenGL::bindVertexArray");
	}

	inline void OpenGL::enableVertexAttribArray(const int location)
	{
		glEnableVertexAttribArray(location);
		OpenGL::checkErrors("OpenGL::enableVertexAttribArray");
	}
/*
	inline void OpenGL::disableVertexAttribArray(const int location)
	{
		glDisableVertexAttribArray(location);
		OpenGL::checkErrors("OpenGL::disableVertexAttribArray");
	}

	inline void OpenGL::drawArrays(const PrimitiveMode mode, const int first, const unsigned int count)
	{
		glDrawArrays(static_cast<GLenum>(mode), first, count);
		OpenGL::checkErrors("OpenGL::drawArrays");
	}
	*/
	inline void OpenGL::drawElements(const PrimitiveMode mode, const unsigned int count, const DataType type, const int offset)
	{
		glDrawElements(static_cast<GLenum>(mode), count, static_cast<GLenum>(type), reinterpret_cast<void *>(offset));
		OpenGL::checkErrors("OpenGL::drawElements");
	}
	/*
	template<class T> 
	inline void OpenGL::uniform(const Handle uniform, const T value)
	{
		throw std::runtime_error("A uniform cannot be set with this type.");
	}
	*/
	template<class T>
	inline void OpenGL::bufferData(const BufferType type, const std::vector<T> & data, const BufferUsage usage)
	{
		const GLvoid * dataPtr = data.data();
		glBufferData(static_cast<GLenum>(type), data.size() * sizeof(T), dataPtr, static_cast<GLenum>(usage));
		OpenGL::checkErrors("OpenGL::bufferData");
	}

	template<class T>
	inline void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset)
	{
		throw std::runtime_error("Vertex attribute pointer of this type cannot be passed.");
	}

	template<>
	inline void OpenGL::vertexAttribPointer<short>(const int location, const int size, const bool normalized, const int offset)
	{
		glVertexAttribPointer(location, size, static_cast<GLenum>(DataType::SHORT), normalized, offset, nullptr);
		OpenGL::checkErrors("OpenGL::vertexAttribPointer");
	}

	template<>
	inline void OpenGL::vertexAttribPointer<unsigned short>(const int location, const int size, const bool normalized, const int offset)
	{
		glVertexAttribPointer(location, size, static_cast<GLenum>(DataType::UNSIGNED_SHORT), normalized, offset, nullptr);
		OpenGL::checkErrors("OpenGL::vertexAttribPointer");
	}

	template<>
	inline void OpenGL::vertexAttribPointer<int>(const int location, const int size, const bool normalized, const int offset)
	{
		glVertexAttribPointer(location, size, static_cast<GLenum>(DataType::INT), normalized, offset, nullptr);
		OpenGL::checkErrors("OpenGL::vertexAttribPointer");
	}

	template<>
	inline void OpenGL::vertexAttribPointer<unsigned int>(const int location, const int size, const bool normalized, const int offset)
	{
		glVertexAttribPointer(location, size, static_cast<GLenum>(DataType::UNSIGNED_INT), normalized, offset, nullptr);
		OpenGL::checkErrors("OpenGL::vertexAttribPointer");
	}

	template<>
	inline void OpenGL::vertexAttribPointer<float>(const int location, const int size, const bool normalized, const int offset)
	{
		glVertexAttribPointer(location, size, static_cast<GLenum>(DataType::FLOAT), normalized, offset, nullptr);
		OpenGL::checkErrors("OpenGL::vertexAttribPointer");
	}

	template<>
	inline void OpenGL::vertexAttribPointer<double>(const int location, const int size, const bool normalized, const int offset)
	{
		glVertexAttribPointer(location, size, static_cast<GLenum>(DataType::DOUBLE), normalized, offset, nullptr);
		OpenGL::checkErrors("OpenGL::vertexAttribPointer");
	}

	template<class T>
	inline void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<T> & data)
	{
		throw std::runtime_error("Vertex attribute pointer of this type cannot be passed.");
	}

	template<>
	inline void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<short> & data)
	{
		glVertexAttribPointer(location, size, static_cast<GLenum>(DataType::SHORT), normalized, offset, data.data());
		OpenGL::checkErrors("OpenGL::vertexAttribPointer");
	}

	template<>
	inline void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<unsigned short> & data)
	{
		glVertexAttribPointer(location, size, static_cast<GLenum>(DataType::UNSIGNED_SHORT), normalized, offset, data.data());
		OpenGL::checkErrors("OpenGL::vertexAttribPointer");
	}

	template<>
	inline void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<int> & data)
	{
		glVertexAttribPointer(location, size, static_cast<GLenum>(DataType::INT), normalized, offset, data.data());
		OpenGL::checkErrors("OpenGL::vertexAttribPointer");
	}

	template<>
	inline void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<unsigned int> & data)
	{
		glVertexAttribPointer(location, size, static_cast<GLenum>(DataType::UNSIGNED_INT), normalized, offset, data.data());
		OpenGL::checkErrors("OpenGL::vertexAttribPointer");
	}

	template<>
	inline void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<float> & data)
	{
		glVertexAttribPointer(location, size, static_cast<GLenum>(DataType::FLOAT), normalized, offset, data.data());
		OpenGL::checkErrors("OpenGL::vertexAttribPointer");
	}

	template<>
	inline void OpenGL::vertexAttribPointer(const int location, const int size, const bool normalized, const int offset, std::vector<double> & data)
	{
		glVertexAttribPointer(location, size, static_cast<GLenum>(DataType::DOUBLE), normalized, offset, data.data());
		OpenGL::checkErrors("OpenGL::vertexAttribPointer");
	}
/*
	template<>
	inline void OpenGL::uniform(const Handle uniform, const int value)
	{
		glUniform1i(uniform, value);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	inline void OpenGL::uniform(const Handle uniform, const float value)
	{
		glUniform1f(uniform, value);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	inline void OpenGL::uniform(const Handle uniform, const bool value)
	{
		glUniform1i(uniform, static_cast<int>(value));
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	inline void OpenGL::uniform(const Handle uniform, const IntVector2u value)
	{
		//glUniform2i(uniform, value[0], value[1]);
		glUniform2iv(uniform, 2, &value[0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	inline void OpenGL::uniform(const Handle uniform, const IntVector3u value)
	{
		//glUniform3i(uniform, value[0], value[1], value[2]);
		glUniform3iv(uniform, 3, &value[0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	inline void OpenGL::uniform(const Handle uniform, const IntVector4u value)
	{
		//glUniform4i(uniform, value[0], value[1], value[2], value[3]);
		glUniform4iv(uniform, 4, &value[0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	inline void OpenGL::uniform(const Handle uniform, const FloatVector2u value)
	{
		//glUniform2f(uniform, value[0], value[1]);
		glUniform2fv(uniform, 2, &value[0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	inline void OpenGL::uniform(const Handle uniform, const FloatVector3u value)
	{
		//glUniform3f(uniform, value[0], value[1], value[2]);
		glUniform3fv(uniform, 3, &value[0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	inline void OpenGL::uniform(const Handle uniform, const FloatVector4u value)
	{
		//glUniform4f(uniform, value[0], value[1], value[2], value[3]);
		glUniform4fv(uniform, 4, &value[0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	inline void OpenGL::uniform(const Handle uniform, const FloatMatrix2u value)
	{
		glUniformMatrix2fv(uniform, 2, false, &value[0][0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	inline void OpenGL::uniform(const Handle uniform, const FloatMatrix3u value)
	{
		glUniformMatrix3fv(uniform, 3, false, &value[0][0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	inline void OpenGL::uniform(const Handle uniform, const FloatMatrix4u value)
	{
		glUniformMatrix4fv(uniform, 4, false, &value[0][0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}*/
}