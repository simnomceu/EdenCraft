namespace ece
{
	inline Shader::Shader() : _filename(), _source(), _type(NULL_TYPE_SHADER) {}

	inline const std::string & Shader::getFilename() const { return this->_filename; }

	inline const std::string & Shader::getSource() const { return this->_source; }

	inline const ShaderType & Shader::getType() const { return this->_type; }
}