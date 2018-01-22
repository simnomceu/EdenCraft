#include "graphic/model/shader.hpp"

#include "utility/file_system/file.hpp"
#include "utility/debug/exception.hpp"
#include "utility/log/service_logger.hpp"

namespace ece
{
	void Shader::loadFromFile(const ShaderType & type, const std::string & filename)
	{
		if (type == NULL_TYPE_SHADER) {
			throw BadInputException("A shader file need to be loaded with a valid type.");
		}

		if (this->_filename != filename) {
			this->_filename = filename;

			this->_source.clear();
			File shaderFile;
			try {
				shaderFile.open(this->_filename, OpenMode::out);
				this->_source = shaderFile.parseToString();
				shaderFile.close();
			}
			catch (FileException & e) {
				ServiceLoggerLocator::getService().logError(e.what());
			}
			this->_type = type;
		}
	}

	void Shader::loadFromString(const ShaderType & type, const std::string & sourceCode)
	{
		if (type == NULL_TYPE_SHADER) {
			throw BadInputException("A shader file need to be loaded with a valid type.");
		}

		this->_filename = "";
		this->_source = sourceCode;
		this->_type = type;
	}
}