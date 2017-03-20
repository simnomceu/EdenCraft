#include "Shader.hpp"
namespace ece
{
	inline Shader::Shader(): filename(), source(), type(GL::NULL_TYPE_SHADER), handle(GL::NULL_ID) {}

	inline Shader::~Shader() { GL::deleteShader(this->handle); }

	inline const std::string & Shader::getFilename() const { return this->filename; }

	inline const std::string & Shader::getSource() const { return this->source; }

	inline const GL::ShaderType & Shader::getType() const { return this->type; }

	inline const GL::ShaderID & Shader::getHandle() const { return this->handle; }
}