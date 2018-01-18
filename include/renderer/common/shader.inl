namespace ece
{
	inline Shader::Shader(): _filename(), _source(), _type(FRAGMENT_SHADER), _handle(0), _compilationRequired(false) {}

	inline Shader::Shader(const Shader & copy) : 
		_filename(copy._filename), _source(copy._source), _type(copy._type), _handle(copy._handle), 
		_compilationRequired(copy._compilationRequired) {}

	inline Shader::Shader(Shader && move) :
		_filename(std::move(move._filename)), _source(std::move(move._source)), _type(move._type), _handle(move._handle), 
		_compilationRequired(move._compilationRequired)
	{
		move._filename.clear();
		move._handle = 0;
		move._compilationRequired = false;
	}

	inline Shader::~Shader() { this->terminate(); }

	inline const std::string & Shader::getFilename() const { return this->_filename; }

	inline const std::string & Shader::getSource() const { return this->_source; }

	inline ShaderType Shader::getType() const { return this->_type; }

	inline ShaderHandle Shader::getHandle() const { return this->_handle; }

	inline bool Shader::isCompilationRequired() const { return this->_compilationRequired; }
}