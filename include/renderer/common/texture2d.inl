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


namespace ece
{
	namespace renderer
	{
		namespace common
		{
			inline Texture2D::Texture2D()noexcept : _filename(), _data(), _width(), _height(), _type(TextureTypeTarget::TEXTURE_2D), _handle(OpenGL::genTexture()) {}

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
		} // namespace common
	} // namespace renderer
} // namespace ece