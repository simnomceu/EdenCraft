#include "renderer/common/shader.hpp"

#include "utility/file_system/file.hpp"
#include "utility/debug/exception.hpp"
#include "utility/log/service_logger.hpp"

namespace ece
{
	Shader & Shader::operator=(const Shader & copy)
	{
		this->filename = copy.filename;
		this->source = copy.filename;
		this->type = copy.type;
		this->handle = copy.handle;
		this->compilationRequired = copy.compilationRequired;

		return *this;
	}

	Shader & Shader::operator=(Shader && move)
	{
		this->filename = std::move(move.filename);
		this->source = std::move(move.filename);
		this->type = move.type;
		this->handle = move.handle;
		this->compilationRequired = move.compilationRequired;

		move.filename.clear();
		move.handle = 0;
		move.compilationRequired = false;

		return *this;
	}

	void Shader::loadFromFile(const ShaderType type, const std::string & filename)
	{
		this->terminate();

		if (this->filename != filename) {
			this->filename = filename;

			this->source.clear();
			File shaderFile;
			try {
				shaderFile.open(this->filename);
				this->source = shaderFile.parseToString();
				shaderFile.close();
			}
			catch (FileException & e) {
				ServiceLoggerLocator::getService().logError(e.what());
			}
			this->type = type;
			this->compilationRequired = true;
		}
	}

	void Shader::loadFromString(const ShaderType type, const std::string & sourceCode)
	{
		this->terminate();

		this->filename = "";
		this->source = sourceCode;
		this->type = type;
		this->compilationRequired = true;
	}

	void Shader::compile()
	{
		this->handle = OpenGL::createShader(this->type);
		OpenGL::shaderSource(this->handle, this->source);		
		OpenGL::compileShader(this->handle);
		this->compilationRequired = false;
	}

	void Shader::terminate()
	{
		if (this->handle != 0) {
			OpenGL::deleteShader(this->handle);
			this->handle = 0;
			this->compilationRequired = true;
		}
	}
}