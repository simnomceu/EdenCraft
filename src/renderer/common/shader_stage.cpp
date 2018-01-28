#include "renderer/common/shader_stage.hpp"

#include "utility/file_system/file.hpp"
#include "utility/debug/exception.hpp"
#include "utility/log/service_logger.hpp"

namespace ece
{
	ShaderStage & ShaderStage::operator=(const ShaderStage & copy)
	{
		this->_filename = copy._filename;
		this->_source = copy._filename;
		this->_type = copy._type;
		this->_handle = copy._handle;
		this->_compilationRequired = copy._compilationRequired;

		return *this;
	}

	ShaderStage & ShaderStage::operator=(ShaderStage && move)
	{
		this->_filename = std::move(move._filename);
		this->_source = std::move(move._filename);
		this->_type = move._type;
		this->_handle = move._handle;
		this->_compilationRequired = move._compilationRequired;

		move._filename.clear();
		move._handle = 0;
		move._compilationRequired = false;

		return *this;
	}

	void ShaderStage::loadFromFile(const ShaderType type, const std::string & filename)
	{
		this->terminate();

		if (this->_filename != filename) {
			this->_filename = filename;

			this->_source.clear();
			File shaderFile;
			try {
				shaderFile.open(this->_filename);
				this->_source = shaderFile.parseToString();
				shaderFile.close();
			}
			catch (FileException & e) {
				ServiceLoggerLocator::getService().logError(e.what());
			}
			this->_type = type;
			this->_compilationRequired = true;
		}
	}

	void ShaderStage::loadFromString(const ShaderType type, const std::string & sourceCode)
	{
		this->terminate();

		this->_filename = "";
		this->_source = sourceCode;
		this->_type = type;
		this->_compilationRequired = true;
	}

	void ShaderStage::compile()
	{
		this->_handle = OpenGL::createShader(this->_type);
		OpenGL::shaderSource(this->_handle, this->_source);		
		OpenGL::compileShader(this->_handle);
		this->_compilationRequired = false;
	}

	void ShaderStage::terminate()
	{
		if (this->_handle != 0) {
			OpenGL::deleteShader(this->_handle);
			this->_handle = 0;
			this->_compilationRequired = true;
		}
	}
}