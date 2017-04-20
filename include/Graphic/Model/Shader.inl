namespace ece
{
	inline Shader::Shader() : filename(), source(), type(NULL_TYPE_SHADER) {}

	inline const std::string & Shader::getFilename() const { return this->filename; }

	inline const std::string & Shader::getSource() const { return this->source; }

	inline const ShaderType & Shader::getType() const { return this->type; }
}