#include "ShaderGL.hpp"

#include "GL\glew.h"
#include "Util\Log\ServiceLogger.hpp"

#include <fstream>
#include <exception>

namespace ece
{
	ShaderGL::ShaderGL(const ShaderType & type): Shader(type), source("")
	{
		auto & logger = ServiceLoggerLocator::getService();

		switch (this->type) {
			case COMPUTE_SHADER:
				this->id = glCreateShader(GL_COMPUTE_SHADER);
				break;
			case FRAGMENT_SHADER:
				this->id = glCreateShader(GL_FRAGMENT_SHADER);
				break;
			case GEOMETRY_SHADER:
				this->id = glCreateShader(GL_GEOMETRY_SHADER);
			 	break;
			case VERTEX_SHADER:
				this->id = glCreateShader(GL_VERTEX_SHADER);
				break;
			case TESS_EVALUATION_SHADER:
				this->id = glCreateShader(GL_TESS_EVALUATION_SHADER);
				break;
			case TESS_CONTROL_SHADER:
				this->id = glCreateShader(GL_TESS_CONTROL_SHADER);
				break;
			default:
				logger.logError("Shader created with the unknown type " + std::to_string(this->type));
				break;
		}

		if (this->id == 0) {
			logger.logError("An error occured while trying to create a shader of type: " + std::to_string(this->type));
		}
	}

	ShaderGL::~ShaderGL()
	{
		if (this->id > 0) {
			glDeleteShader(this->id);
		}
	}

	void ShaderGL::loadFromFile(const std::string & filename)
	{
		if (this->filename != filename) {
			this->filename = filename;
			this->source.clear();

			std::ifstream shaderFile(this->filename.data(), std::ios::out);
			if (!shaderFile.is_open()) {
				throw std::exception(std::string("Error while trying to open " + this->filename).c_str());
				// TODO replace by a great exception.
			}
			std::string line;
			while (shaderFile.good()) {
				getline(shaderFile, line);
				this->source.append(line).append("\n");
			}
			shaderFile.close();
		}
	}

	void ShaderGL::loadFromString(const std::string & sourceCode)
	{
		this->filename = "";
		this->source = sourceCode;
	}

	void ShaderGL::compile()
	{
		const GLchar * source = this->source.data();

		if (this->id > 0) {
			glShaderSource(this->id, 1, &source, nullptr);
			glCompileShader(this->id);

			GLint result = GL_FALSE;
			int infoLogLength = 0;
			glGetShaderiv(this->id, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				throw std::exception(std::string("An error occured while trying to compile the shader " + std::to_string(this->id)).data());
			}
			glGetShaderiv(this->id, GL_INFO_LOG_LENGTH, &infoLogLength);
			if (infoLogLength > 0) {
				char * error = new char[infoLogLength + 1];
				glGetShaderInfoLog(this->id, infoLogLength, NULL, error);
				throw std::exception(error);
				delete[] error;
			}

			this->source.clear();
		}
		else {
			throw std::exception("It is impossible to compile an invalid shader.");
		}
	}

	void ShaderGL::reset()
	{
		if (this->id > 0) {
			glDeleteShader(this->id);
		}
		this->filename.clear();
		this->source.clear();
	}
}