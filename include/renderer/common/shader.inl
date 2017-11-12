namespace ece
{
	inline Shader::Shader(): filename(), source(), type(FRAGMENT_SHADER), handle(0), compilationRequired(false) {}

	inline Shader::Shader(const Shader & copy) : 
		filename(copy.filename), source(copy.source), type(copy.type), handle(copy.handle), 
		compilationRequired(copy.compilationRequired) {}

	inline Shader::Shader(Shader && move) :
		filename(std::move(move.filename)), source(std::move(move.source)), type(move.type), handle(move.handle), 
		compilationRequired(move.compilationRequired)
	{
		move.filename.clear();
		move.handle = 0;
		move.compilationRequired = false;
	}

	inline Shader::~Shader() { this->terminate(); }

	inline const std::string & Shader::getFilename() const { return this->filename; }

	inline const std::string & Shader::getSource() const { return this->source; }

	inline ShaderType Shader::getType() const { return this->type; }

	inline ShaderHandle Shader::getHandle() const { return this->handle; }

	inline bool Shader::isCompilationRequired() const { return this->compilationRequired; }
}