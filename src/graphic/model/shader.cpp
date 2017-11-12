#include "graphic/model/shader.hpp"

#include "utility/file/file.hpp"
#include "utility/debug/exception.hpp"
#include "utility/log/service_logger.hpp"

namespace ece
{
	void Shader::loadFromFile(const ShaderType & type, const std::string & filename)
	{
		if (type == NULL_TYPE_SHADER) {
			throw BadInputException("A shader file need to be loaded with a valid type.");
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
			throw BadInputException("A shader file need to be loaded with a valid type.");
		}

		this->filename = "";
		this->source = sourceCode;
		this->type = type;
	}
}