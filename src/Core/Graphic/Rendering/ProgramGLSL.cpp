#include "Core\Graphic\Rendering\ProgramGLSL.hpp"

#include <fstream>

namespace ece
{
	ProgramGLSL::ProgramGLSL(): programId(-1), shaders()
	{
		this->programId = glCreateProgram();
	}

	ProgramGLSL::~ProgramGLSL()
	{
		glDeleteProgram(this->programId);
		for (auto it = this->shaders.begin(); it != this->shaders.end(); ++it) {
			glDeleteShader(it->shaderId);
		}
	}

	void ProgramGLSL::loadShader(const std::string & pathname, const ShaderType type)
	{
		auto id = glCreateShader(type);
		if (id == 0) {
			throw std::exception("Error while loading shader.");
			// TODO replace by a great exception.
		}

		std::string shaderSource;

		std::ifstream shaderFile(pathname.c_str(), std::ios::out);
		if (!shaderFile.is_open()) {
			throw std::exception(std::string("Error while trying to open " + pathname).c_str());
			// TODO replace by a great exception.
		}
		std::string line;
		while (shaderFile.good()) {
			getline(shaderFile,line);
			shaderSource.append(line).append("\n");
		}
		shaderFile.close();

		const GLchar * source[1];
		source[0] = shaderSource.c_str();
		GLint size[1];
		size[0] = (GLint)shaderSource.size();
		glShaderSource(id, 1, source, size);

		glCompileShader(id);
		this->shaders.push_back({ id, type });
	}

	void ProgramGLSL::link()
	{
		for (auto it = this->shaders.begin(); it != this->shaders.end(); ++it) {
			glAttachShader(this->programId, it->shaderId);
		}
		glLinkProgram(this->programId);
		glValidateProgram(this->programId);
	}

	void ProgramGLSL::use()
	{
		if (glIsProgram(this->programId)) {
			glUseProgram(this->programId);
		}
	}

	void ProgramGLSL::unuse()
	{
		glUseProgram(0);
	}

	void ProgramGLSL::removeShader(const ShaderType type)
	{
		for (auto it = this->shaders.begin(); it != this->shaders.end(); ++it) {
			if (it->type == type) {
				glDetachShader(this->programId, it->shaderId);
			}
		}
	}
}