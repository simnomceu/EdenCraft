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


#include "renderer/resource/texture2d.hpp"

#include "utility/formats/bitmap/parser_bmp.hpp"
#include "utility/file_system/file.hpp"
#include "renderer/image/loader_image.hpp"
#include "core/format/service_format.hpp"

#include <memory>

namespace ece
{
	namespace renderer
	{
		namespace resource
		{
			using utility::formats::bitmap::ParserBMP;
			using utility::file_system::File;
			using utility::FileException;
			using utility::OpenMode;
			using utility::FileCodeError;
			using renderer::image::LoaderImage;
			using core::format::ServiceFormatLocator;

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

					try {
						this->_data.clear();

						auto loader = std::static_pointer_cast<LoaderImage>(ServiceFormatLocator::getService().getLoader(filename).lock());

						loader->loadFromFile(this->_filename);

						auto & image = loader->getImage();
						auto buffer = image.data();
						for (std::size_t i = 0; i < image.getHeight() * image.getWidth(); ++i) {
							this->_data.push_back(buffer[i].red); // red
							this->_data.push_back(buffer[i].green); // green
							this->_data.push_back(buffer[i].blue); // blue
						}

						this->_width = image.getWidth();
						this->_height = image.getHeight();
						this->_type = type;
					}
					catch (FileException & e) {
						throw e;
					}
				}
			}

			void Texture2D::update()
			{
				// TODO: adding setParameter method to Texture2D class to call OpenGL::texParameter for external.
				// TODO: adding properties for each texParameter here ?
				OpenGL::texImage2D(this->_type, 0, PixelInternalFormat::RGB, this->_width, this->_height, PixelFormat::RGB, PixelDataType::UNSIGNED_BYTE, &this->_data[0]);
				OpenGL::generateMipmap(MipmapTarget::TEXTURE_2D);
				OpenGL::texParameter(TextureTarget::TEXTURE_2D, TextureParameter::TEXTURE_WRAP_S, GL_REPEAT);
				OpenGL::texParameter(TextureTarget::TEXTURE_2D, TextureParameter::TEXTURE_WRAP_T, GL_REPEAT);
				OpenGL::texParameter(TextureTarget::TEXTURE_2D, TextureParameter::TEXTURE_MAG_FILTER, GL_NEAREST);
				OpenGL::texParameter(TextureTarget::TEXTURE_2D, TextureParameter::TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
			}

			void Texture2D::terminate() {}
		} // namespace resource
	} // namespace renderer
} // namespace ece