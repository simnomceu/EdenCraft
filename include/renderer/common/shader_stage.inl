namespace ece
{
	inline ShaderStage::ShaderStage(): _filename(), _source(), _type(ShaderType::FRAGMENT_SHADER), _handle(), _compilationRequired(false) {}

	inline ShaderStage::ShaderStage(const ShaderStage & copy) :
		_filename(copy._filename), _source(copy._source), _type(copy._type), _handle(copy._handle), 
		_compilationRequired(copy._compilationRequired) {}

	inline ShaderStage::ShaderStage(ShaderStage && move) :
		_filename(std::move(move._filename)), _source(std::move(move._source)), _type(move._type), _handle(move._handle), 
		_compilationRequired(move._compilationRequired)
	{
		move._filename.clear();
		move._handle = 0;
		move._compilationRequired = false;
	}

	inline ShaderStage::~ShaderStage() { this->terminate(); }

	inline const std::string & ShaderStage::getFilename() const { return this->_filename; }

	inline const std::string & ShaderStage::getSource() const { return this->_source; }

	inline ShaderType ShaderStage::getType() const { return this->_type; }

	inline Handle ShaderStage::getHandle() const { return this->_handle; }

	inline bool ShaderStage::isCompilationRequired() const { return this->_compilationRequired; }
}