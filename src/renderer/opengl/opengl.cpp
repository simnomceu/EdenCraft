/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															ooooooooo.                               .o8                                        
															`888   `Y88.                            "888                                        
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b 
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P 
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888     
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888     
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b   
                                                                       
                                          
                                     
				This file is part of EdenCraft Engine - Renderer module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#include "renderer/opengl/opengl.hpp"

#include <iostream>

#include "utility/log/service_logger.hpp"

namespace ece
{
	std::unique_ptr<OpenGLExtension> OpenGL::_extensions(nullptr);

	void OpenGL::init(const OptionOpenGL options)
	{
		if (OpenGL::_extensions.get() == nullptr) {
			#ifdef __unix__
			OpenGL::_extensions = std::make_unique<GLXExtension>();
			#elif __WINDOW__
			OpenGL::_extensions = std::make_unique<WGLExtension>();
			#elif __OSX__
			OpenGL::_extensions = std::make_unique<AGLExtension>();
			#else
			OpenGL::_extensions = std::make_unique<WGLExtension>();
			#endif
		}
		OpenGL::_extensions->init(options);
	}

	unsigned int OpenGL::getError()
	{
		if (!glGetError) {
			throw OpenGLExtensionException("glGetError", COMMAND_EXECUTION);
		}
		return glGetError();
	}

	void OpenGL::checkErrors()
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

			ServiceLoggerLocator::getService().logError("Error OpenGL: (" + std::to_string(error) + ") " + errorMessage);
			error = OpenGL::getError();
		}
	}

	ShaderHandle OpenGL::createShader(const ShaderType type)
	{
		if (!glCreateShader) {
			throw OpenGLExtensionException("glCreateShader", SHADERS_AND_PROGRAMS);
		}
		GLuint shaderHandle = glCreateShader(type);
		OpenGL::checkErrors();
		return static_cast<ShaderHandle>(shaderHandle);
	}

	void OpenGL::shaderSource(const ShaderHandle handle, const std::string & source)
	{
		if (!glShaderSource) {
			throw OpenGLExtensionException("glShaderSource", SHADERS_AND_PROGRAMS);
		}
		auto sourcePtr = source.data();
		glShaderSource(handle, 1, &sourcePtr, nullptr); // TODO: add the length of the source
		OpenGL::checkErrors();
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
		OpenGL::checkErrors();
	}

	void OpenGL::compileShader(const ShaderHandle handle)
	{
		if (!glCompileShader) {
			throw OpenGLExtensionException("glCompileShader", SHADERS_AND_PROGRAMS);
		}
		glCompileShader(handle);
		OpenGL::checkErrors();
	}

	void OpenGL::deleteShader(const ShaderHandle handle)
	{
		if (!glDeleteShader) {
			throw OpenGLExtensionException("glDeleteShader", SHADERS_AND_PROGRAMS);
		}
		glDeleteShader(handle);
		OpenGL::checkErrors();
	}

	ProgramHandle OpenGL::createProgram()
	{
		if (!glCreateProgram) {
			throw OpenGLExtensionException("glCreateProgram", SHADERS_AND_PROGRAMS);
		}
		auto programHandle = glCreateProgram();
		OpenGL::checkErrors();
		return static_cast<ProgramHandle>(programHandle);
	}

	void OpenGL::attachShader(const ProgramHandle program, const ShaderHandle shader)
	{
		if (!glAttachShader) {
			throw OpenGLExtensionException("glAttachShader", SHADERS_AND_PROGRAMS);
		}
		glAttachShader(program, shader);
		OpenGL::checkErrors();
	}

	void OpenGL::linkProgram(const ProgramHandle handle)
	{
		if (!glLinkProgram) {
			throw OpenGLExtensionException("glLinkProgram", SHADERS_AND_PROGRAMS);
		}
		glLinkProgram(handle);
		OpenGL::checkErrors();
	}

	void OpenGL::useProgram(const ProgramHandle handle)
	{
		if (!glUseProgram) {
			throw OpenGLExtensionException("glUseProgram", SHADERS_AND_PROGRAMS);
		}
		glUseProgram(handle);
		OpenGL::checkErrors();
	}

	UniformHandle OpenGL::getUniformLocation(const ProgramHandle handle, const std::string & uniform)
	{
		if (!glGetUniformLocation) {
			throw OpenGLExtensionException("glGetUniformLocation", SHADERS_AND_PROGRAMS);
		}
		auto location = glGetUniformLocation(handle, uniform.data());
		OpenGL::checkErrors();
		return static_cast<UniformHandle>(location);
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const int value)
	{
		if (!glUniform1i) {
			throw OpenGLExtensionException("glUniform1i", SHADERS_AND_PROGRAMS);
		}
		glUniform1i(uniform, value);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const float value)
	{
		if (!glUniform1f) {
			throw OpenGLExtensionException("glUniform1f", SHADERS_AND_PROGRAMS);
		}
		glUniform1f(uniform, value);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const bool value)
	{
		if (!glUniform1i) {
			throw OpenGLExtensionException("glUniform1i", SHADERS_AND_PROGRAMS);
		}
		glUniform1i(uniform, static_cast<int>(value));
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const IntVector2u value)
	{
		if (!glUniform2iv) {
			throw OpenGLExtensionException("glUniform2iv", SHADERS_AND_PROGRAMS);
		}
		//glUniform2i(uniform, value[0], value[1]);
		glUniform2iv(uniform, 2, &value[0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const IntVector3u value)
	{
		if (!glUniform3iv) {
			throw OpenGLExtensionException("glUniform3iv", SHADERS_AND_PROGRAMS);
		}
		//glUniform3i(uniform, value[0], value[1], value[2]);
		glUniform3iv(uniform, 3, &value[0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const IntVector4u value)
	{
		if (!glUniform4iv) {
			throw OpenGLExtensionException("glUniform4iv", SHADERS_AND_PROGRAMS);
		}
		//glUniform4i(uniform, value[0], value[1], value[2], value[3]);
		glUniform4iv(uniform, 4, &value[0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatVector2u value)
	{
		if (!glUniform2fv) {
			throw OpenGLExtensionException("glUniform2fv", SHADERS_AND_PROGRAMS);
		}
		//glUniform2f(uniform, value[0], value[1]);
		glUniform2fv(uniform, 2, &value[0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatVector3u value)
	{
		if (!glUniform3fv) {
			throw OpenGLExtensionException("glUniform3fv", SHADERS_AND_PROGRAMS);
		}
		//glUniform3f(uniform, value[0], value[1], value[2]);
		glUniform3fv(uniform, 3, &value[0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatVector4u value)
	{
		if (!glUniform4fv) {
			throw OpenGLExtensionException("glUniform4fv", SHADERS_AND_PROGRAMS);
		}
		//glUniform4f(uniform, value[0], value[1], value[2], value[3]);
		glUniform4fv(uniform, 4, &value[0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatMatrix2u value)
	{
		if (!glUniformMatrix2fv) {
			throw OpenGLExtensionException("glUniformMatrix2fv", SHADERS_AND_PROGRAMS);
		}
		glUniformMatrix2fv(uniform, 2, false, &value[0][0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatMatrix3u value)
	{
		if (!glUniformMatrix3fv) {
			throw OpenGLExtensionException("glUniformMatrix3fv", SHADERS_AND_PROGRAMS);
		}
		glUniformMatrix3fv(uniform, 3, false, &value[0][0]);
		OpenGL::checkErrors();
	}

	template<>
	void OpenGL::uniform(const UniformHandle uniform, const FloatMatrix4u value)
	{
		if (!glUniform4fv) {
			throw OpenGLExtensionException("glUniformMatrix4fv", SHADERS_AND_PROGRAMS);
		}
		glUniformMatrix4fv(uniform, 4, false, &value[0][0]);
		OpenGL::checkErrors();
	}

	void OpenGL::genBuffers(VBOHandle & handle)
	{
		if (!glGenBuffers) {
			throw OpenGLExtensionException("glGenBuffers", BUFFER_OBJECTS);
		}
		glGenBuffers(1, &handle);
		OpenGL::checkErrors();
	}

	void OpenGL::genBuffers(const int count, std::vector<VBOHandle>& handles)
	{
		if (count != 0) {
			if (!glGenBuffers) {
				throw OpenGLExtensionException("glGenBuffers", BUFFER_OBJECTS);
			}
			handles.resize(handles.size() + count);
			glGenBuffers(count, &handles.back() - count + 1);
			OpenGL::checkErrors();
		}
	}

	void OpenGL::bindBuffer(const BufferType type, const VBOHandle handle)
	{
		if (!glBindBuffer) {
			throw OpenGLExtensionException("glBindBuffer", BUFFER_OBJECTS);
		}
		glBindBuffer(type, handle);
		OpenGL::checkErrors();
	}

	void OpenGL::genVertexArrays(VAOHandle & handle)
	{
		if (!glGenVertexArrays) {
			throw OpenGLExtensionException("glGenVertexArrays", BUFFER_OBJECTS);
		}
		glGenVertexArrays(1, &handle);
		OpenGL::checkErrors();
	}

	void OpenGL::genVertexArrays(const int count, std::vector<VAOHandle>& handles)
	{
		if (count != 0) {
			if (!glGenVertexArrays) {
				throw OpenGLExtensionException("glGenVertexArrays", BUFFER_OBJECTS);
			}
			handles.resize(handles.size() + count);
			glGenVertexArrays(count, &handles.back() - count + 1);
			OpenGL::checkErrors();
		}
	}

	void OpenGL::bindVertexArray(const VAOHandle handle)
	{
		if (!glBindVertexArray) {
			throw OpenGLExtensionException("glBindVertexArray", BUFFER_OBJECTS);
		}
		glBindVertexArray(handle);
		OpenGL::checkErrors();
	}

	void OpenGL::enableVertexAttribArray(const int location)
	{
		if (!glEnableVertexAttribArray) {
			throw OpenGLExtensionException("glEnableVertexAttribArray", VERTEX_ARRAYS);
		}
		glEnableVertexAttribArray(location);
		OpenGL::checkErrors();
	}

	void OpenGL::disableVertexAttribArray(const int location)
	{
		if (!glDisableVertexAttribArray) {
			throw OpenGLExtensionException("glDisableVertexAttribArray", VERTEX_ARRAYS);
		}
		glDisableVertexAttribArray(location);
		OpenGL::checkErrors();
	}
}