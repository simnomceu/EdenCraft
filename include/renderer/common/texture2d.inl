namespace ece
{
	inline Texture2D::Texture2D()noexcept : _filename(), _data(), _width(), _height(), _type(TextureTypeTarget::TEXTURE_2D), _handle(ece::OpenGL::genTexture()) {}

	inline Texture2D::Texture2D(const Texture2D & copy) : _filename(copy._filename), _data(copy._data), _width(copy._width), _height(copy._height), _type(copy._type), 
															_handle(copy._handle) {}

	inline Texture2D::Texture2D(Texture2D && move) noexcept : _filename(std::move(move._filename)), _data(std::move(move._data)), _width(move._width), _height(move._height), _type(move._type), 
															_handle(move._handle)
	{
		move._data.clear();
		move._handle = 0;
	}

	inline const std::string & Texture2D::getFilename() const { return this->_filename; }

	inline const std::vector<std::byte> & Texture2D::getData() const { return this->_data; }

	inline unsigned int Texture2D::getWidth() const { return this->_width; }

	inline unsigned int Texture2D::getHeight() const { return this->_height; }

	inline TextureTypeTarget Texture2D::getType() const { return this->_type; }

	inline Handle Texture2D::getHandle() const { return this->_handle; }

	inline void Texture2D::bind(const TextureTarget target) { OpenGL::bindTexture(target, this->_handle); }
}