#include "Rendering\ProgramGL.hpp"

#include <algorithm>

#include "Util\Log\ServiceLogger.hpp"
#include "Rendering\ShaderGL.hpp"

namespace ece
{
	ProgramGL::ProgramGL(): Program(), shaders()
	{
		this->id = glCreateProgram();
		if (this->id == 0) {
			ServiceLoggerLocator::getService().logError("An error occured while trying to create a program.");
		}
	}

	ProgramGL::~ProgramGL()
	{
		if (this->id > 0) {
			for (auto it = this->shaders.begin(); it != this->shaders.end(); ++it) {
				this->detachShader((*it)->getId());
			}

			glDeleteProgram(this->id);
		}
	}

	void ProgramGL::attachShader(Shader & shader)
	{
		if (this->id > 0) {
			//this->shaders.push_back(new ShaderGL(std::move(shader)));
			shader.reset(); // TODO: could be eventually moved in the move constructor (and move assignment operator) of Shader class.

			glAttachShader(this->id, this->shaders.front()->getId());
		}
		else {
			throw std::exception("It is not possible to attach a shader to an invalid program.");
		}
	}

	void ProgramGL::detachShader(const Shader::ShaderID & shader)
	{
		if (this->id > 0) {
			// TODO: check if the shader is attached to not trigger a GL_INVALID_OPERATION
			glDetachShader(this->id, shader);
			std::remove_if(this->shaders.begin(), this->shaders.end(), [shader](const Shader * element) {
				return shader == element->getId();
			});
		}
		else {
			throw std::exception("It is not possible to detach a shader from an invalid program.");
		}
	}

	void ProgramGL::link()
	{
		if (this->id > 0) {
			glLinkProgram(this->id);

			GLint result = GL_FALSE;
			int infoLogLength = 0;
			glGetProgramiv(this->id, GL_LINK_STATUS, &result);
			if (result == GL_FALSE) {

			}
			glGetProgramiv(this->id, GL_INFO_LOG_LENGTH, &infoLogLength);
			if (infoLogLength > 0) {
				char* error = new char[infoLogLength + 1];
				glGetProgramInfoLog(this->id, infoLogLength, NULL, error);
				std::cerr << std::string(error) << std::endl;
				delete[] error;
			}
		}
		else {
			throw std::exception("It is not possible to link an invalid program.");
		}
	}

	void ProgramGL::use()
	{
		if (this->id > 0) {
			glUseProgram(this->id);
		}
		else {
			throw std::exception("It is not possible to use an invalid program.");
		}
	}

	void ProgramGL::bindInfo(const glm::mat4 & info, const std::string & name)
	{
		if (this->id > 0) {
			GLuint handle = glGetUniformLocation(this->id, name.data());
			glUniformMatrix4fv(handle, 1, GL_FALSE, &info[0][0]);
		}
		else {
			throw std::exception("It is not possible to bind an info to an invalid program.");
		}
	}

	void ProgramGL::bindInfo(const glm::vec3 & info, const std::string & name)
	{
		if (this->id > 0) {
			GLuint handle = glGetUniformLocation(this->id, name.data());
			glUniform3fv(handle, 3, &info[0]);
		}
		else {
			throw std::exception("It is not possible to bind an info to an invalid program.");
		}
	}
}