#include "renderer/opengl/opengl.hpp"

#include <iostream>

#include "utility/log/service_logger.hpp"

namespace ece
{
	std::array<unsigned short int, 2> OpenGL::_latestVersion{2, 1};

	void OpenGL::init()
	{
		auto version = getLatestVersionAvailable();
		if (version != std::array<unsigned short int, 2>{0, 0}) {
			OpenGL::_latestVersion = version;
		}
	}

	unsigned int OpenGL::getError()
	{
		//if (!glGetError) {
		//	throw OpenGLExtensionException("glGetError", COMMAND_EXECUTION);
		//}
		return glGetError();
	}

	void OpenGL::checkErrors(const std::string & location)
	{
		GLenum error(OpenGL::getError());
		while (error != GL_NO_ERROR) {
			std::string errorMessage;

			switch (error) {
			case GL_INVALID_OPERATION:				errorMessage = "INVALID_OPERATION";				break;
			case GL_INVALID_ENUM:					errorMessage = "INVALID_ENUM";					break;
			case GL_INVALID_VALUE:					errorMessage = "INVALID_VALUE";					break;
			case GL_OUT_OF_MEMORY:					errorMessage = "OUT_OF_MEMORY";					break;
			case GL_INVALID_FRAMEBUFFER_OPERATION:  errorMessage = "INVALID_FRAMEBUFFER_OPERATION"; break;
			default: break;
			}

			ServiceLoggerLocator::getService().logError("Error OpenGL: (" + std::to_string(error) + ") " + errorMessage + " in " + location + ".");
			error = OpenGL::getError();
		}
	}

/*	void OpenGL::clear(const Bitfield mask)
	{
		if (!glClear) {
			throw OpenGLExtensionException("glClear", WHOLE_FRAMEBUFFER);
		}
		glClear(static_cast<GLbitfield>(mask));
		OpenGL::checkErrors("OpenGL::clear");
	}

	void OpenGL::clearColor(const float r, const float g, const float b, const float a)
	{
		if (!glClearColor) {
			throw OpenGLExtensionException("glClearColor", WHOLE_FRAMEBUFFER);
		}
		glClearColor(r, g, b, a);
		OpenGL::checkErrors("OpenGL::clearColor");
	}

	void OpenGL::enable(const Capability cap)
	{
		if (!glEnable) {
			throw OpenGLExtensionException("glEnable", TEXTURES_AND_SAMPLERS);
		}
		glEnable(static_cast<GLenum>(cap));
		OpenGL::checkErrors("OpenGL::enable");
	}

	void OpenGL::disable(const Capability cap)
	{
		if (!glDisable) {
			throw OpenGLExtensionException("glDisable", TEXTURES_AND_SAMPLERS);
		}
		glDisable(static_cast<GLenum>(cap));
		OpenGL::checkErrors("OpenGL::disable");
	}

	void OpenGL::enableIndexed(const Capability cap, const unsigned short int index)
	{
		if (!glEnablei) {
			throw OpenGLExtensionException("glEnablei", PER_FRAGMENT_OPERATIONS);
		}
		glEnablei(static_cast<GLenum>(cap), index);
		OpenGL::checkErrors("OpenGL::enableIndexed");
	}

	void OpenGL::disableIndexed(const Capability cap, const unsigned short int index)
	{
		if (!glDisablei) {
			throw OpenGLExtensionException("glDisablei", PER_FRAGMENT_OPERATIONS);
		}
		glDisablei(static_cast<GLenum>(cap), index);
		OpenGL::checkErrors("OpenGL::disableIndexed");
	}

	void OpenGL::cullFace(const CullFaceMode mode)
	{
		if (!glCullFace) {
			throw OpenGLExtensionException("glCullFace", RASTERIZATION);
		}
		glCullFace(static_cast<GLenum>(mode));
		OpenGL::checkErrors("OpenGL::cullFace");
	}

	void OpenGL::frontFace(const FrontFaceMode mode)
	{
		if (!glFrontFace) {
			throw OpenGLExtensionException("glFrontFace", RASTERIZATION);
		}
		glFrontFace(static_cast<GLenum>(mode));
		OpenGL::checkErrors("OpenGL::frontFace");
	}

	void OpenGL::depthFunc(const DepthFunctionCondition condition)
	{
		if (!glDepthFunc) {
			throw OpenGLExtensionException("glDepthFunc", PER_FRAGMENT_OPERATIONS);
		}
		glDepthFunc(static_cast<GLenum>(condition));
		OpenGL::checkErrors("OpenGL::depthFunc");
	}

	void OpenGL::getInteger(const Parameter parameter, int & data)
	{
		if (!glGetIntegerv) {
			throw OpenGLExtensionException("glGetIntegerv", STATE_AND_STATE_REQUESTS);
		}
		GLint tmp;
		glGetIntegerv(static_cast<GLenum>(parameter), &tmp);
		OpenGL::checkErrors("OpenGL::getInteger");
		data = static_cast<int>(tmp);
	}

	void OpenGL::getString(const InfoGL parameter, std::string & data)
	{
		if (!glGetString) {
			throw OpenGLExtensionException("glGetString", STATE_AND_STATE_REQUESTS);
		}
		const char * tmp = reinterpret_cast<const char *>(glGetString(static_cast<GLenum>(parameter)));
		OpenGL::checkErrors("OpenGL::getString");
		data = std::string(tmp);
	}

	void OpenGL::getIntegers(const Parameter parameter, std::vector<int> & data)
	{
		if (!glGetIntegerv) {
			throw OpenGLExtensionException("glGetIntegerv", STATE_AND_STATE_REQUESTS);
		}
		std::vector<GLint> tmp;
		glGetIntegerv(static_cast<GLenum>(parameter), tmp.data());
		OpenGL::checkErrors("OpenGL::getIntegers");
		std::copy(tmp.begin(), tmp.end(), data.begin());
	}

	ShaderHandle OpenGL::createShader(const ShaderType type)
	{
		if (!glCreateShader) {
			throw OpenGLExtensionException("glCreateShader", SHADERS_AND_PROGRAMS);
		}
		GLuint shaderHandle = glCreateShader(static_cast<GLenum>(type));
		OpenGL::checkErrors("OpenGL::createShader");
		return static_cast<ShaderHandle>(shaderHandle);
	}

	void OpenGL::shaderSource(const ShaderHandle handle, const std::string & source)
	{
		if (!glShaderSource) {
			throw OpenGLExtensionException("glShaderSource", SHADERS_AND_PROGRAMS);
		}
		auto sourcePtr = source.data();
		glShaderSource(handle, 1, &sourcePtr, nullptr); // TODO: add the length of the source
		OpenGL::checkErrors("OpenGL::shaderSource");
	}

	void OpenGL::shaderSource(const ShaderHandle handle, const std::vector<std::string>& source)
	{
		if (!glShaderSource) {
			throw OpenGLExtensionException("glShaderSource", SHADERS_AND_PROGRAMS);
		}
		std::vector<const char*> sourcesPtr{};
		for (const auto& string : source) {
			sourcesPtr.push_back(string.data());
		}
		glShaderSource(handle, 1, sourcesPtr.data(), nullptr); // TODO: add the lengths of the sources
		OpenGL::checkErrors("OpenGL::shaderSource");
	}

	void OpenGL::compileShader(const ShaderHandle handle)
	{
		if (!glCompileShader) {
			throw OpenGLExtensionException("glCompileShader", SHADERS_AND_PROGRAMS);
		}
		glCompileShader(handle);
		OpenGL::checkErrors("OpenGL::compileShader");
	}

	void OpenGL::deleteShader(const ShaderHandle handle)
	{
		if (!glDeleteShader) {
			throw OpenGLExtensionException("glDeleteShader", SHADERS_AND_PROGRAMS);
		}
		glDeleteShader(handle);
		OpenGL::checkErrors("OpenGL::deleteShader");
	}

	ProgramHandle OpenGL::createProgram()
	{
		if (!glCreateProgram) {
			throw OpenGLExtensionException("glCreateProgram", SHADERS_AND_PROGRAMS);
		}
		auto programHandle = glCreateProgram();
		OpenGL::checkErrors("OpenGL::createProgram");
		return static_cast<ProgramHandle>(programHandle);
	}

	void OpenGL::attachShader(const ProgramHandle program, const ShaderHandle shader)
	{
		if (!glAttachShader) {
			throw OpenGLExtensionException("glAttachShader", SHADERS_AND_PROGRAMS);
		}
		glAttachShader(program, shader);
		OpenGL::checkErrors("OpenGL::attachShader");
	}

	void OpenGL::linkProgram(const ProgramHandle handle)
	{
		if (!glLinkProgram) {
			throw OpenGLExtensionException("glLinkProgram", SHADERS_AND_PROGRAMS);
		}
		glLinkProgram(handle);
		OpenGL::checkErrors("OpenGL::linkProgram");
	}

	void OpenGL::useProgram(const ProgramHandle handle)
	{
		if (!glUseProgram) {
			throw OpenGLExtensionException("glUseProgram", SHADERS_AND_PROGRAMS);
		}
		glUseProgram(handle);
		OpenGL::checkErrors("OpenGL::useProgram");
	}

	UniformHandle OpenGL::getUniformLocation(const ProgramHandle handle, const std::string & uniform)
	{
		if (!glGetUniformLocation) {
			throw OpenGLExtensionException("glGetUniformLocation", SHADERS_AND_PROGRAMS);
		}
		auto location = glGetUniformLocation(handle, uniform.data());
		OpenGL::checkErrors("OpenGL::getUniformLocation");
		return static_cast<UniformHandle>(location);
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const int value)
	{
		if (!glUniform1i) {
			throw OpenGLExtensionException("glUniform1i", SHADERS_AND_PROGRAMS);
		}
		glUniform1i(uniform, value);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const float value)
	{
		if (!glUniform1f) {
			throw OpenGLExtensionException("glUniform1f", SHADERS_AND_PROGRAMS);
		}
		glUniform1f(uniform, value);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const bool value)
	{
		if (!glUniform1i) {
			throw OpenGLExtensionException("glUniform1i", SHADERS_AND_PROGRAMS);
		}
		glUniform1i(uniform, static_cast<int>(value));
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const IntVector2u value)
	{
		if (!glUniform2iv) {
			throw OpenGLExtensionException("glUniform2iv", SHADERS_AND_PROGRAMS);
		}
		//glUniform2i(uniform, value[0], value[1]);
		glUniform2iv(uniform, 2, &value[0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const IntVector3u value)
	{
		if (!glUniform3iv) {
			throw OpenGLExtensionException("glUniform3iv", SHADERS_AND_PROGRAMS);
		}
		//glUniform3i(uniform, value[0], value[1], value[2]);
		glUniform3iv(uniform, 3, &value[0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const IntVector4u value)
	{
		if (!glUniform4iv) {
			throw OpenGLExtensionException("glUniform4iv", SHADERS_AND_PROGRAMS);
		}
		//glUniform4i(uniform, value[0], value[1], value[2], value[3]);
		glUniform4iv(uniform, 4, &value[0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatVector2u value)
	{
		if (!glUniform2fv) {
			throw OpenGLExtensionException("glUniform2fv", SHADERS_AND_PROGRAMS);
		}
		//glUniform2f(uniform, value[0], value[1]);
		glUniform2fv(uniform, 2, &value[0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatVector3u value)
	{
		if (!glUniform3fv) {
			throw OpenGLExtensionException("glUniform3fv", SHADERS_AND_PROGRAMS);
		}
		//glUniform3f(uniform, value[0], value[1], value[2]);
		glUniform3fv(uniform, 3, &value[0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatVector4u value)
	{
		if (!glUniform4fv) {
			throw OpenGLExtensionException("glUniform4fv", SHADERS_AND_PROGRAMS);
		}
		//glUniform4f(uniform, value[0], value[1], value[2], value[3]);
		glUniform4fv(uniform, 4, &value[0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatMatrix2u value)
	{
		if (!glUniformMatrix2fv) {
			throw OpenGLExtensionException("glUniformMatrix2fv", SHADERS_AND_PROGRAMS);
		}
		glUniformMatrix2fv(uniform, 2, false, &value[0][0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatMatrix3u value)
	{
		if (!glUniformMatrix3fv) {
			throw OpenGLExtensionException("glUniformMatrix3fv", SHADERS_AND_PROGRAMS);
		}
		glUniformMatrix3fv(uniform, 3, false, &value[0][0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatMatrix4u value)
	{
		if (!glUniform4fv) {
			throw OpenGLExtensionException("glUniformMatrix4fv", SHADERS_AND_PROGRAMS);
		}
		glUniformMatrix4fv(uniform, 4, false, &value[0][0]);
		OpenGL::checkErrors("OpenGL::uniform");
	}

	void OpenGL::genBuffers(VBOHandle & handle)
	{
		if (!glGenBuffers) {
			throw OpenGLExtensionException("glGenBuffers", BUFFER_OBJECTS);
		}
		glGenBuffers(1, &handle);
		OpenGL::checkErrors("OpenGL::genBuffers");
	}

	void OpenGL::genBuffers(const int count, std::vector<VBOHandle>& handles)
	{
		if (count != 0) {
			if (!glGenBuffers) {
				throw OpenGLExtensionException("glGenBuffers", BUFFER_OBJECTS);
			}
			handles.resize(handles.size() + count);
			glGenBuffers(count, &handles.back() - count + 1);
			OpenGL::checkErrors("OpenGL::genBuffers");
		}
	}

	void OpenGL::bindBuffer(const BufferType type, const VBOHandle handle)
	{
		if (!glBindBuffer) {
			throw OpenGLExtensionException("glBindBuffer", BUFFER_OBJECTS);
		}
		glBindBuffer(static_cast<GLenum>(type), handle);
		OpenGL::checkErrors("OpenGL::bindBuffer");
	}

	void OpenGL::genVertexArrays(VAOHandle & handle)
	{
		if (!glGenVertexArrays) {
			throw OpenGLExtensionException("glGenVertexArrays", BUFFER_OBJECTS);
		}
		glGenVertexArrays(1, &handle);
		OpenGL::checkErrors("OpenGL::genVertexArrays");
	}

	void OpenGL::genVertexArrays(const int count, std::vector<VAOHandle>& handles)
	{
		if (count != 0) {
			if (!glGenVertexArrays) {
				throw OpenGLExtensionException("glGenVertexArrays", BUFFER_OBJECTS);
			}
			handles.resize(handles.size() + count);
			glGenVertexArrays(count, &handles.back() - count + 1);
			OpenGL::checkErrors("OpenGL::genVertexArrays");
		}
	}

	void OpenGL::bindVertexArray(const VAOHandle handle)
	{
		if (!glBindVertexArray) {
			throw OpenGLExtensionException("glBindVertexArray", BUFFER_OBJECTS);
		}
		glBindVertexArray(handle);
		OpenGL::checkErrors("OpenGL::bindVertexArray");
	}

	void OpenGL::enableVertexAttribArray(const int location)
	{
		if (!glEnableVertexAttribArray) {
			throw OpenGLExtensionException("glEnableVertexAttribArray", VERTEX_ARRAYS);
		}
		glEnableVertexAttribArray(location);
		OpenGL::checkErrors("OpenGL::enableVertexAttribArray");
	}

	void OpenGL::disableVertexAttribArray(const int location)
	{
		if (!glDisableVertexAttribArray) {
			throw OpenGLExtensionException("glDisableVertexAttribArray", VERTEX_ARRAYS);
		}
		glDisableVertexAttribArray(location);
		OpenGL::checkErrors("OpenGL::disableVertexAttribArray");
	}

	void OpenGL::drawArrays(const PrimitiveMode mode, const int first, const unsigned int count)
	{
		if (!glDrawArrays) {
			throw OpenGLExtensionException("glDrawArrays", VERTEX_ARRAYS);
		}
		glDrawArrays(static_cast<GLenum>(mode), first, count);
		OpenGL::checkErrors("OpenGL::drawArrays");
	}*/
}