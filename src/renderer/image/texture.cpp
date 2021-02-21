/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#include "renderer/pch.hpp"
#include "renderer/image/texture.hpp"
#include "renderer/rendering/renderer.hpp"
#include "utility/log.hpp"
#include "utility/formats/bitmap.hpp"
#include "utility/file_system.hpp"
#include "core/format.hpp"
#include "utility/debug.hpp"
#include "core/resource.hpp"

namespace ece
{
	namespace renderer
	{
		namespace image
		{
			using rendering::Renderer;

			Texture::Texture(Type type, ece::size_t samples, ece::size_t nbImages) noexcept: std::enable_shared_from_this<Texture>(), /*_target(TextureTarget::TEXTURE_2D), */_type(type), _samples(samples),
				_nbImages(nbImages), _filename(), _data(), _width(), _height(), /*_type(TextureTypeTarget::TEXTURE_2D), */_pixelData(), _handle(OpenGL::genTexture())
			{
				this->_pixelData.format = PixelFormat::RGBA;
				this->_pixelData.internalFormat = PixelInternalFormat::RGBA;
				this->_pixelData.type = PixelDataType::UNSIGNED_BYTE;

				this->setParameter<int>(TextureParameter::TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				this->setParameter<int>(TextureParameter::TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
				this->setParameter<int>(TextureParameter::TEXTURE_MIN_FILTER, GL_LINEAR);
			}

			Texture::~Texture() noexcept
			{
				OpenGL::deleteTextures({ this->_handle });
			}

			Texture & Texture::operator=(const Texture & copy)
			{
				if (this != &copy) {
					this->_filename = copy._filename;
					this->_data = copy._data;
					this->_width = copy._width;
					this->_height = copy._height;
					this->_type = copy._type;
					this->_pixelData = copy._pixelData;
					this->_handle = copy._handle;
				}

				return *this;
			}

			Texture & Texture::operator=(Texture && move) noexcept
			{
				if (this != &move) {
					this->_filename = std::move(move._filename);
					this->_data = std::move(move._data);
					this->_width = move._width;
					this->_height = move._height;
					this->_type = move._type;
					this->_pixelData = move._pixelData;
					this->_handle = move._handle;

					move._data.content.reset();
					move._handle = NULL_HANDLE;
				}

				return *this;
			}

			void Texture::loadFromFile(const TextureTypeTarget type, const std::string& filename)
			{
				this->terminate();

				if (this->_filename != filename) {
					this->_filename = filename;

					auto image = ResourceLoader().loadFromFile(filename)[0].get<Image<RGBA32>>();
					this->loadFromImage(type, image);
				}
			}

			void Texture::loadFromImage(const TextureTypeTarget type, Image<RGBA32>::Reference image)
			{
				this->_data = image;

				this->_width = image->getWidth();
				this->_height = image->getHeight();

				this->create();
			}

			void Texture::saveToFile(const std::filesystem::path& filename)
			{
				auto resource = makeResource<Image<RGBA32>>(filename.stem().generic_string());
				this->saveToImage(resource);

				ResourceLoader().saveToFile(filename, { resource });
			}

			void Texture::saveToImage(Image<RGBA32>::Reference image)
			{
				auto bufferIn = this->_data->data();

				image->resize(this->_width, this->_height);
				auto buffer = image->data();
				for (auto i = std::size_t{ 0 }; i < static_cast<std::size_t>(image->getHeight() * image->getWidth()); ++i) {
					buffer[i] = bufferIn[i];
				}
			}

			void Texture::bind()
			{
				this->bind(this->getTextureTarget());
			}

			void Texture::bind(TextureTarget target)
			{
				if (!this->isCurrent(target)) {
					this->setCurrent(target);
					OpenGL::bindTexture(target, this->_handle);
				}
			}

			void Texture::generateMipmap()
			{
				this->setParameter<int>(TextureParameter::TEXTURE_MAG_FILTER, GL_NEAREST);
				this->setParameter<int>(TextureParameter::TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
				OpenGL::generateMipmap(MipmapTarget::TEXTURE_2D);
			}

			void Texture::terminate() {}

			void Texture::create()
			{
				auto buffer = this->_data ? reinterpret_cast<std::uint8_t*>(this->_data->data()) : nullptr;
				switch (this->_type) {
				case Texture::Type::TEXTURE_1D:
					if (this->_nbImages > 1) {
						OpenGL::texImage2D(TextureTypeTarget::TEXTURE_1D_ARRAY, 0, this->_pixelData.internalFormat, this->_width, this->_nbImages, this->_pixelData.format, 
							this->_pixelData.type, &buffer[0]);
					}
					else {
						OpenGL::texImage1D(TargetTexture1D::TEXTURE_1D, 0, this->_pixelData.internalFormat, this->_width, this->_pixelData.format, this->_pixelData.type, &buffer[0]);
					}
					break;
				case Texture::Type::TEXTURE_2D:
					if (this->_samples > 1) {
						if (this->_nbImages > 1) {
							OpenGL::texImage3DMultisample(TargetTextureMultisample::TEXTURE_2D_MULTISAMPLE_ARRAY, this->_samples, this->_pixelData.internalFormat, this->_width, 
								this->_height, this->_nbImages, true);
						}
						else {
							OpenGL::texImage2DMultisample(TargetTextureMultisample::TEXTURE_2D_MULTISAMPLE, this->_samples, this->_pixelData.internalFormat, this->_width,
								this->_height, true);
						}
					}
					else {
						if (this->_nbImages > 1) {
							OpenGL::texImage3D(TargetTexture3D::TEXTURE_2D_ARRAY, 0, this->_pixelData.internalFormat, this->_width, this->_height, this->_nbImages, 
								this->_pixelData.format, this->_pixelData.type, &buffer[0]);
						}
						else {
							OpenGL::texImage2D(TextureTypeTarget::TEXTURE_2D, 0, this->_pixelData.internalFormat, this->_width, this->_height,
								this->_pixelData.format, this->_pixelData.type, &buffer[0]);
						}
					}
					break;
				case Texture::Type::TEXTURE_3D: 
					OpenGL::texImage3D(TargetTexture3D::TEXTURE_3D, 0, this->_pixelData.internalFormat, this->_width, this->_height, this->_depth,
						this->_pixelData.format, this->_pixelData.type, &buffer[0]);
					break;
				case Texture::Type::RECTANGLE:
					OpenGL::texImage2D(TextureTypeTarget::TEXTURE_RECTANGLE, 0, this->_pixelData.internalFormat, this->_width, this->_height,
						this->_pixelData.format, this->_pixelData.type, &buffer[0]);
					break;
				case Texture::Type::CUBE_MAP:  
					OpenGL::texImage2D(TextureTypeTarget::TEXTURE_CUBE_MAP_POSITIVE_X, 0, this->_pixelData.internalFormat, this->_width, this->_height, this->_pixelData.format, 
						this->_pixelData.type, &buffer[0]);
					OpenGL::texImage2D(TextureTypeTarget::TEXTURE_CUBE_MAP_POSITIVE_Y, 0, this->_pixelData.internalFormat, this->_width, this->_height, this->_pixelData.format, 
						this->_pixelData.type, &buffer[0]);
					OpenGL::texImage2D(TextureTypeTarget::TEXTURE_CUBE_MAP_POSITIVE_Z, 0, this->_pixelData.internalFormat, this->_width, this->_height, this->_pixelData.format, 
						this->_pixelData.type, &buffer[0]);
					OpenGL::texImage2D(TextureTypeTarget::TEXTURE_CUBE_MAP_NEGATIVE_X, 0, this->_pixelData.internalFormat, this->_width, this->_height, this->_pixelData.format, 
						this->_pixelData.type, &buffer[0]);
					OpenGL::texImage2D(TextureTypeTarget::TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, this->_pixelData.internalFormat, this->_width, this->_height, this->_pixelData.format, 
						this->_pixelData.type, &buffer[0]);
					OpenGL::texImage2D(TextureTypeTarget::TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, this->_pixelData.internalFormat, this->_width, this->_height, this->_pixelData.format, 
						this->_pixelData.type, &buffer[0]);
					break;
				case Texture::Type::BUFFER:
					OpenGL::texBuffer(this->_pixelData.internalFormat, this->_handle);
					break;
				default: break;
				}
			}

			void Texture::setCurrent(TextureTarget target) { Renderer::setCurrentTexture(target, this->weak_from_this()); }

			auto Texture::isCurrent(TextureTarget target) const noexcept -> bool
			{
				try {
					return Renderer::getCurrentTexture(target).lock().get() == this;
				}
				catch (std::bad_weak_ptr & e) {
					ERROR << "A Texture need to be managed by a std::shared_ptr, according to std::enabled_shared_from_this mother class specification. " << e.what() << flushing;
					return false;
				}
			}

			auto Texture::getTextureTarget() -> TextureTarget
			{
				switch (this->_type) {
				case Texture::Type::TEXTURE_1D:
					return this->_nbImages > 1 ? TextureTarget::TEXTURE_1D_ARRAY : TextureTarget::TEXTURE_1D;
					break;
				case Texture::Type::TEXTURE_2D:
					if (this->_samples > 1) {
						return this->_nbImages > 1 ? TextureTarget::TEXTURE_2D_MULTISAMPLE_ARRAY : TextureTarget::TEXTURE_2D_MULTISAMPLE;
					}
					else {
						return this->_nbImages > 1 ? TextureTarget::TEXTURE_2D_ARRAY : TextureTarget::TEXTURE_2D;
					}
					break;
				case Texture::Type::TEXTURE_3D: return TextureTarget::TEXTURE_3D; break;
				case Texture::Type::RECTANGLE: return TextureTarget::TEXTURE_RECTANGLE; break;
				case Texture::Type::CUBE_MAP: return this->_nbImages > 1 ? TextureTarget::TEXTURE_CUBE_MAP_ARRAY : TextureTarget::TEXTURE_CUBE_MAP; break;
				case Texture::Type::BUFFER: return TextureTarget::TEXTURE_BUFFER; break;
				default: break;
				}
			}
		} // namespace image
	} // namespace renderer
} // namespace ece
