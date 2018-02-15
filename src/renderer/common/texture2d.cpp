#include "renderer/common/texture2d.hpp"

#include "utility/file_system/parser_bmp.hpp"

namespace ece
{
	Texture2D & Texture2D::operator=(const Texture2D & copy)
	{
		this->_filename = copy._filename;
		this->_data = copy._data;
		this->_width = copy._width;
		this->_height = copy._height;
		this->_type = copy._type;
		this->_handle = copy._handle;

		return *this;
	}

	Texture2D & Texture2D::operator=(Texture2D && move) noexcept
	{
		this->_filename = std::move(move._filename);
		this->_data = std::move(move._data);
		this->_width = move._width;
		this->_height = move._height;
		this->_type = move._type;
		this->_handle = move._handle;

		move._data.clear();
		move._handle = 0;

		return *this;
	}

	void Texture2D::loadFromFile(const TextureTypeTarget type, const std::string & filename)
	{
		this->terminate();

		if (this->_filename != filename) {
			this->_filename = filename;

			this->_data.clear();

			ece::ParserBMP parserBMP;
			parserBMP.loadFromFile(filename);

			auto buffer = parserBMP.getBuffer();
			for (auto it : buffer) {
				this->_data.push_back(it.red);
				this->_data.push_back(it.green);
				this->_data.push_back(it.blue);
			}

			this->_width = parserBMP.getWidth();
			this->_height = parserBMP.getHeight();
			this->_type = type;
		}
	}

	void Texture2D::update()
	{
		ece::OpenGL::texImage2D(this->_type, 0, ece::PixelInternalFormat::RGB, this->_width, this->_height, ece::PixelFormat::RGB, ece::PixelDataType::UNSIGNED_BYTE, &this->_data[0]);
		ece::OpenGL::generateMipmap(ece::MipmapTarget::TEXTURE_2D);
		ece::OpenGL::texParameter(ece::TextureTarget::TEXTURE_2D, ece::TextureParameter::TEXTURE_WRAP_S, GL_REPEAT);
		ece::OpenGL::texParameter(ece::TextureTarget::TEXTURE_2D, ece::TextureParameter::TEXTURE_WRAP_T, GL_REPEAT);
		ece::OpenGL::texParameter(ece::TextureTarget::TEXTURE_2D, ece::TextureParameter::TEXTURE_MAG_FILTER, GL_NEAREST);
		ece::OpenGL::texParameter(ece::TextureTarget::TEXTURE_2D, ece::TextureParameter::TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	}

	void Texture2D::terminate() {}
}