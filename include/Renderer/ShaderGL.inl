namespace ece
{
	inline ShaderGL::ShaderGL(): filename(), source(), type(GL::NULL_TYPE_SHADER), handle(GL::NULL_ID) {}

	inline ShaderGL::~ShaderGL() { GL::deleteShader(this->handle); }

	inline const std::string & ShaderGL::getFilename() const { return this->filename; }

	inline const std::string & ShaderGL::getSource() const { return this->source; }

	inline const GL::ShaderType & ShaderGL::getType() const { return this->type; }

	inline const GL::ShaderID & ShaderGL::getHandle() const { return this->handle; }
}