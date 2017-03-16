namespace ece
{
	inline Shader::Shader(const ShaderType & type) : id(-1), type(type), filename("") {}

	inline Shader::~Shader() {}

	inline const Shader::ShaderID & Shader::getId() const { return this->id; }
	inline const ShaderType & Shader::getType() const { return this->type; }
	inline const std::string & Shader::getFilename() const { return this->filename; }
}