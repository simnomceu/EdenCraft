#include "renderer/opengl/opengl.hpp"

#include <iostream>

#include "utility/log/service_logger.hpp"

namespace ece
{
	std::unique_ptr<OpenGLExtension> OpenGL::extensions(nullptr);

	void OpenGL::init(const OptionOpenGL options)
	{
		if (OpenGL::extensions.get() == nullptr) {
			#ifdef __unix__
			OpenGL::extensions = std::make_unique<GLXExtension>();
			#elif __WINDOW__
			OpenGL::extensions = std::make_unique<WGLExtension>();
			#elif __OSX__
			OpenGL::extensions = std::make_unique<AGLExtension>();
			#else
			OpenGL::extensions = std::make_unique<WGLExtension>();
			#endif
		}
		OpenGL::extensions->init(options);
	}

	void OpenGL::checkErrors()
	{
		if (!OpenGL::extensions->isLoaded(COMMAND_EXECUTION)) {
			std::string error = "OpenGL errors cannot be checked, because some OpenGL extensions are missing. ("
				+ std::to_string(COMMAND_EXECUTION) + ")";
			throw std::runtime_error(error);
		}
		GLenum error(glGetError());
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

			ServiceLoggerLocator::getService().logError("Error OpenGL: (" + std::to_string(error) + ") " + errorMessage);
			error = glGetError();
		}
	}

	ShaderHandle OpenGL::createShader(const ShaderType type)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Shader cannot be created, because some OpenGL extensions are missing. ("
			+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		GLuint shaderHandle = 0;
		GLenum shaderType = 0;
		switch (type) {
		case ECE_NULL_SHADER: break;
		case ECE_COMPUTE_SHADER: shaderType = GL_COMPUTE_SHADER; break;
		case ECE_FRAGMENT_SHADER: shaderType = GL_FRAGMENT_SHADER; break;
		case ECE_GEOMETRY_SHADER: shaderType = GL_GEOMETRY_SHADER; break;
		case ECE_VERTEX_SHADER: shaderType = GL_VERTEX_SHADER; break;
		case ECE_TESS_EVALUATION_SHADER: shaderType = GL_TESS_EVALUATION_SHADER; break;
		case ECE_TESS_CONTROL_SHADER: shaderType = GL_TESS_CONTROL_SHADER; break;
		default: break;
		}

		if (shaderType == 0) {
			throw std::runtime_error("Trying to create a shader with an invalid type.");
		}
		shaderHandle = glCreateShader(shaderType);
		if (shaderHandle == 0) {
			throw std::runtime_error("OpenGL error while creating shader: " + std::to_string(glGetError()));
		}

		OpenGL::checkErrors();

		return shaderHandle;
	}

	void OpenGL::shaderSource(const ShaderHandle handle, const std::string & source)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Shader source cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		auto sourcePtr = source.data();
		glShaderSource(handle, 1, &sourcePtr, nullptr); // TODO: add the length of the source
		OpenGL::checkErrors();
	}

	void OpenGL::shaderSource(const ShaderHandle handle, const std::vector<std::string>& source)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Shader source cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		std::vector<const char*> sourcesPtr{};
		for (const auto& string : source) {
			sourcesPtr.push_back(string.data());
		}
		glShaderSource(handle, 1, sourcesPtr.data(), nullptr); // TODO: add the lengths of the sources
		OpenGL::checkErrors();
	}

	void OpenGL::compileShader(const ShaderHandle handle)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Shader cannot be compiled, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		glCompileShader(handle);
		OpenGL::checkErrors();
	}

	void OpenGL::deleteShader(const ShaderHandle handle)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Shader cannot be deleted, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		glDeleteShader(handle);
		OpenGL::checkErrors();
	}

	ProgramHandle OpenGL::createProgram()
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Program cannot be created, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		auto programHandle = glCreateProgram();
		OpenGL::checkErrors();
		return programHandle;
	}

	void OpenGL::attachShader(const ProgramHandle program, const ShaderHandle shader)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Shader cannot be attached to a program, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		glAttachShader(program, shader);
		OpenGL::checkErrors();
	}

	void OpenGL::linkProgram(const ProgramHandle handle)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Program cannot be linked, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		glLinkProgram(handle);
		OpenGL::checkErrors();
	}

	void OpenGL::useProgram(const ProgramHandle handle)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Program cannot be used, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		glUseProgram(handle);
		OpenGL::checkErrors();
	}

	UniformHandle OpenGL::getUniformLocation(const ProgramHandle handle, const std::string & uniform)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be found, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		auto location = glGetUniformLocation(handle, uniform.data());
		OpenGL::checkErrors();
		return location;
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const int value)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		glUniform1i(uniform, value);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const float value)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		glUniform1f(uniform, value);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const bool value)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		glUniform1i(uniform, static_cast<int>(value));
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const IntVertex2u value)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		//glUniform2i(uniform, value[0], value[1]);
		glUniform2iv(uniform, 2, &value[0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const IntVertex3u value)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		//glUniform3i(uniform, value[0], value[1], value[2]);
		glUniform3iv(uniform, 3, &value[0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const IntVertex4u value)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		//glUniform4i(uniform, value[0], value[1], value[2], value[3]);
		glUniform4iv(uniform, 4, &value[0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatVertex2u value)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		//glUniform2f(uniform, value[0], value[1]);
		glUniform2fv(uniform, 2, &value[0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatVertex3u value)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		//glUniform3f(uniform, value[0], value[1], value[2]);
		glUniform3fv(uniform, 3, &value[0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatVertex4u value)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		//glUniform4f(uniform, value[0], value[1], value[2], value[3]);
		glUniform4fv(uniform, 4, &value[0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatMatrix2u value)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		glUniformMatrix2fv(uniform, 2, false, &value[0][0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatMatrix3u value)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		glUniformMatrix3fv(uniform, 3, false, &value[0][0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatMatrix4u value)
	{
		if (!OpenGL::extensions->isLoaded(SHADERS_AND_PROGRAMS)) {
			std::string error = "Uniform cannot be set, because some OpenGL extensions are missing. ("
				+ std::to_string(SHADERS_AND_PROGRAMS) + ")";
			throw std::runtime_error(error);
		}
		glUniformMatrix4fv(uniform, 4, false, &value[0][0]);
		OpenGL::checkErrors();
	}
}