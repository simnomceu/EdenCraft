#include "Model\Shader.hpp"

#include "File\File.hpp"
#include "Debug\Exception.hpp"
#include "Log\ServiceLogger.hpp"

namespace ece
{
	void Shader::loadFromFile(const ShaderType & type, const std::string & filename)
	{
		if (type == NULL_TYPE_SHADER) {
			throw BadInputException::makeException("A shader file need to be loaded with a valid type.");
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

	void Shader::loadFromString(const ShaderType & type, const std::string & sourceCode)
	{
		if (type == NULL_TYPE_SHADER) {
			throw BadInputException::makeException("A shader file need to be loaded with a valid type.");
		}

		this->filename = "";
		this->source = sourceCode;
		this->type = type;
	}
}