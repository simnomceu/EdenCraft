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


#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "renderer/config.hpp"
#include "renderer/pch.hpp"
#include "utility/types.hpp"
#include "utility/pattern.hpp"
#include "core/resource.hpp"
#include "renderer/image/image.hpp"
#include "renderer/image/pixel_data.hpp"
#include "renderer/opengl/enum.hpp"

namespace ece
{
	namespace renderer
	{
		namespace image
		{
			using namespace opengl;

			/**
			 * @class Texture
			 * @brief OpenGL texture.
			 * @remark Split the image and the texture implementations. A texture can use an image but it is not an image.
			 */
			class ECE_RENDERER_API Texture : public std::enable_shared_from_this<Texture>
			{
			public:
				using Reference = Resource<Texture>;

				enum class Type
				{
					TEXTURE_1D	= 0x00,
					TEXTURE_2D	= 0x01,
					TEXTURE_3D	= 0x02,
					RECTANGLE	= 0x03,
					CUBE_MAP	= 0x04,
					BUFFER		= 0x05
				};

				/**
				 * @fn Texture() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Texture(Type type = Type::TEXTURE_2D, ece::size_t samples = 1, ece::size_t nbImages = 1) noexcept;

				/**
				 * @fn Texture(const Texture & copy)
				 * @param[in] copy The texture to copy from.
				 * @brief Default copy constructor.
				 * throw
				 */
				inline Texture(const Texture & copy);

				/**
				 * @fn Texture(Texture && move) noexcept
				 * @param[in] move The texture to move.
				 * @brief Default move constructor.
				 * throw noexcept
				 */
				inline Texture(Texture && move) noexcept;

				/**
				 * @fn ~Texture() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Texture() noexcept;

				/**
				 * @fn Texture & operator=(const Texture & copy)
				 * @param[in] copy The texture to copy from.
				 * @return The texture copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Texture & operator=(const Texture & copy);

				/**
				 * @fn Texture & operator=(Texture && move) noexcept
				 * @param[in] move The texture to move.
				 * @return The texture moved.
				 * @bried Default move assignment operator.
				 * @throw noexcept
				 */
				Texture & operator=(Texture && move) noexcept;

				/**
				 * @fn void loadFromFile(const TypeTarget type, const std::string & filename)
				 * @param[in] type The type of texture to define.
				 * @param[in] filename The source file to use.
				 * @brief Load a texture from a file.
				 * @throw
				 */
				void loadFromFile(const TextureTypeTarget type, const std::string& filename);

				void loadFromImage(const TextureTypeTarget type, Image<RGBA32>::Reference image);

				void saveToFile(const std::filesystem::path & filename);

				void saveToImage(Image<RGBA32>::Reference image);

				/**
				 * @fn const std::string & getFilename() const
				 * @return The filename of the texture.
				 * @brief Get he filename which is the source of the texture.
				 * @throw
				 */
				auto getFilename() const -> const std::string &;

				/**
				 * @fn const std::vector<std::byte> & getData() const
				 * @return The array of pixels of the texture.
				 * @brief Get the texture as an array of pixels.
				 * @throw
				 */
				auto getData() const -> std::uint8_t *;

				/**
				 * @fn std::size_t getWidth() const
				 * @return The width of the texture.
				 * @brief Get the width of the texture.
				 * @throw
				 */
				auto getWidth() const -> ece::size_t;

				/**
				* @fn std::size_t getHeight() const
				* @return The height of the texture.
				* @brief Get the height of the texture.
				* @throw
				*/
				auto getHeight() const -> ece::size_t;

				/**
				 * @fn Handle getHandle() const
				 * @return The id of the texture.
				 * @brief Get the id of the texture.
				 * @throw
				 */
				auto getHandle() const -> Handle;

				/**
				 * @fn void bind(const TextureTarget target)
				 * @param[in] target The buffer to use.
				 * @brief Copy the texture in a buffer to use it.
				 * @throw
				 */
				void bind();
				void bind(TextureTarget target);

				void active(const unsigned int channel);

				template <typename T> void setParameter(const TextureParameter name, const T value);
				template <typename T> void setParameter(const TextureParameter name, const std::vector<T>& value);

				inline void setPixelData(PixelData pixelData);
				inline PixelData getPixelData() const;

				void generateMipmap();

				/**
				 * @fn void terminate()
				 * @brief Clear and delete the texture.
				 * @throw
				 */
				void terminate();

				void create();

				auto getTextureTarget() -> TextureTarget;

			protected:
				void setCurrent(TextureTarget target);
				auto isCurrent(TextureTarget target) const noexcept -> bool;

			//	TextureTarget _target;

				Type _type;
				ece::size_t _samples;
				ece::size_t _nbImages;

				/**
				 * @property _filename
				 * @brief
				 */
				std::string _filename;

				/**
				 * @property _data
				 * @brief The pixels of the texture.
				 */
				Image<RGBA32>::Reference _data;

				/**
				 * @property _width
				 * @brief The width of the texture.
				 */
				ece::size_t _width;

				/**
				 * @property _height
				 * @brief The height of the texture.
				 */
				ece::size_t _height;

				ece::size_t _depth;

				/**
				 * @property _type
				 * @brief Type of texture used.
				 */
			//	TextureTypeTarget _type;

				PixelData _pixelData;

				/**
				 * @property _handle
				 * @brief The texture handle to use for any OpenGL call.
				 */
				Handle _handle;
			};
		} // namespace image
	} // namespace renderer
} // namespace ece

#include "renderer/image/texture.inl"

#endif // TEXTURE_HPP
