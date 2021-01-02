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
#include "renderer/image/texture2d.hpp"

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
			Texture2D::Texture2D()noexcept : Texture(), _filename(), _data(), _width(), _height(), _type(TypeTarget::TEXTURE_2D), _handle(OpenGL::genTexture())
			{
				this->setParameter<int>(Parameter::WRAP_S, GL_CLAMP_TO_EDGE);
				this->setParameter<int>(Parameter::WRAP_T, GL_CLAMP_TO_EDGE);
				this->setParameter<int>(Parameter::MIN_FILTER, GL_LINEAR);
			}

			Texture2D & Texture2D::operator=(const Texture2D & copy)
			{
				if (this != &copy) {
					this->_filename = copy._filename;
					this->_data = copy._data;
					this->_width = copy._width;
					this->_height = copy._height;
					this->_type = copy._type;
					this->_handle = copy._handle;
				}

				return *this;
			}

			Texture2D & Texture2D::operator=(Texture2D && move) noexcept
			{
				if (this != &move) {
					this->_filename = std::move(move._filename);
					this->_data = std::move(move._data);
					this->_width = move._width;
					this->_height = move._height;
					this->_type = move._type;
					this->_handle = move._handle;

					move._data.content.reset();
					move._handle = NULL_HANDLE;
				}

				return *this;
			}

			void Texture2D::loadFromFile(const TypeTarget type, const std::string & filename)
			{
				this->terminate();

				if (this->_filename != filename) {
					this->_filename = filename;

					auto image = ResourceLoader().loadFromFile(filename)[0].get<Image<RGBA32>>();
					this->loadFromImage(type, image);
				}
			}

			void Texture2D::loadFromImage(const TypeTarget type, Image<RGBA32>::Reference image)
			{
				this->_data = image;

				this->_width = image->getWidth();
				this->_height = image->getHeight();
				this->_type = type;

				auto buffer = reinterpret_cast<std::uint8_t*>(this->_data->data());
				OpenGL::texImage2D(getTextureTypeTarget(this->_type), 0, PixelInternalFormat::RGBA, this->_width, this->_height, PixelFormat::RGBA, PixelDataType::UNSIGNED_BYTE, &buffer[0]);
			}

			void Texture2D::saveToFile(const std::filesystem::path & filename)
			{
				auto resource = makeResource<Image<RGBA32>>(filename.stem().generic_string());
				this->saveToImage(resource);

				ResourceLoader().saveToFile(filename, { resource });
			}

			void Texture2D::saveToImage(Image<RGBA32>::Reference image)
			{
				auto bufferIn = this->_data->data();

				image->resize(this->_width, this->_height);
				auto buffer = image->data();
				for (auto i = std::size_t{ 0 }; i < image->getHeight() * image->getWidth(); ++i) {
					buffer[i] = bufferIn[i];
				}
			}

			void Texture2D::bind(const Target target)
			{
				if (!this->isCurrent(target)) {
					this->setCurrent(target);
					OpenGL::bindTexture(getTextureTarget(target), this->_handle);
				}
			}

			void Texture2D::generateMipmap()
			{
				this->setParameter<int>(Parameter::MAG_FILTER, GL_NEAREST);
				this->setParameter<int>(Parameter::MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
				OpenGL::generateMipmap(MipmapTarget::TEXTURE_2D);
			}

			void Texture2D::terminate() {}
		} // namespace image
	} // namespace renderer
} // namespace ece