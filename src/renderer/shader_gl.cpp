#include "shader_gl.hpp"

#include "file/file.hpp"
#include "debug/exception.hpp"
#include "log/service_logger.hpp"

namespace ece
{
	ShaderGL::ShaderGL(ShaderGL && move):
		filename(std::move(move.filename)), source(std::move(move.source)), type(move.type), handle(move.handle)
	{
		move.handle = GL::NULL_ID;
	}

	ShaderGL & ShaderGL::operator=(ShaderGL && move)
	{
		this->filename = std::move(move.filename);
		this->source = std::move(move.filename);
		this->type = move.type;
		this->handle = move.handle;

		move.handle = GL::NULL_ID;

		return *this;
	}

	void ShaderGL::loadFromFile(const GL::ShaderType & type, const std::string & filename)
	{
		if (this->handle != GL::NULL_ID) {
			this->terminate();
		}

		if (this->filename != filename) {
			this->filename = filename;

			this->source.clear();
			File shaderFile;
			try {
				shaderFile.open(this->filename, std::ios::out);
				this->source = shaderFile.parseToString();
				shaderFile.close();
			}
			catch (FileException & e) {
				ServiceLoggerLocator::getService().logError(e.what());
			}
			this->type = type;
		}
	}

	void ShaderGL::loadFromString(const GL::ShaderType & type, const std::string & sourceCode)
	{
		if (this->handle != GL::NULL_ID) {
			this->terminate();
		}

		this->filename = "";
		this->source = sourceCode;
		this->type = type;
	}

	void ShaderGL::compile()
	{
		this->handle = GL::createShader(this->type);
		GL::compileShader(this->handle, this->source);

		auto result = GL::checkShaderCompilationStatus(this->handle);
		if (!result.compiled) {
			throw BadInputException("Shader failed to compile: " + result.log);
		}
		if (result.deleteFlag) {
			//TODO : what to do ?
		}
		if (result.type != this->type) {
			//TODO : what to do ?
		}
		if (result.source != this->source) {
			//TODO : what to do ?
		}
	}

	void ShaderGL::terminate()
	{
		GL::deleteShader(this->handle);
		this->handle = GL::NULL_ID;
	}
}