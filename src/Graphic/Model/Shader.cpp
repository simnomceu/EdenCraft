#include "Model\Shader.hpp"

#include "File\File.hpp"
#include "Debug\Exception.hpp"
#include "Log\ServiceLogger.hpp"

namespace ece
{
	void Shader::loadFromFile(const ShaderType & type, const std::string & filename)
	{
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
		this->filename = "";
		this->source = sourceCode;
		this->type = type;
	}
}