#include "shader.hpp"
namespace ece
{
	inline Shader::Shader(): filename(), source(), type(ECE_NULL_SHADER), handle(0) {}

	inline Shader::~Shader() { /*GL::deleteShader(this->handle);*/ }

	inline const std::string & Shader::getFilename() const { return this->filename; }

	inline const std::string & Shader::getSource() const { return this->source; }

	inline ShaderType Shader::getType() const { return this->type; }

	inline ShaderHandle Shader::getHandle() const { return this->handle; }
}