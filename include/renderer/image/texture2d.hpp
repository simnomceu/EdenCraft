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


#ifndef TEXTURE_2D_HPP
#define TEXTURE_2D_HPP

#include "renderer/config.hpp"
#include "renderer/image/texture.hpp"
#include "core/resource.hpp"
#include "renderer/image/color.hpp"

namespace ece
{
	namespace renderer
	{
		namespace image
		{
			/**
			 * @class Texture2D
			 * @brief OpenGL 2D texture.
			 * @remark Split the image and the texture implementations. A texture can use an image but it is not an image.
			 */
			class ECE_RENDERER_API Texture2D: public Texture
			{
			public:
				using Reference = ResourceHandler<Texture2D>;

				/**
				 * @fn Texture2D() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Texture2D(bool defaultClamping = true) noexcept;

				/**
				 * @fn Texture2D(const Texture2D & copy)
				 * @param[in] copy The texture to copy from.
				 * @brief Default copy constructor.
				 * throw
				 */
				inline Texture2D(const Texture2D & copy);

				/**
				 * @fn Texture2D(Texture2D && move) noexcept
				 * @param[in] move The texture to move.
				 * @brief Default move constructor.
				 * throw noexcept
				 */
				inline Texture2D(Texture2D && move) noexcept;

				/**
				 * @fn ~Texture2D() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Texture2D() noexcept = default;

				/**
				 * @fn Texture2D & operator=(const Texture2D & copy)
				 * @param[in] copy The texture to copy from.
				 * @return The texture copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Texture2D & operator=(const Texture2D & copy);

				/**
				 * @fn Texture2D & operator=(Texture2D && move) noexcept
				 * @param[in] move The texture to move.
				 * @return The texture moved.
				 * @bried Default move assignment operator.
				 * @throw noexcept
				 */
				Texture2D & operator=(Texture2D && move) noexcept;

				/**
				 * @fn void loadFromFile(const TypeTarget type, const std::string & filename)
				 * @param[in] type The type of texture to define.
				 * @param[in] filename The source file to use.
				 * @brief Load a texture from a file.
				 * @throw
				 */
				virtual void loadFromFile(const TypeTarget type, const std::string & filename) override;

				virtual void loadFromImage(const TypeTarget type, const Image<RGBA32> & image) override;

				/**
				 * @fn const std::string & getFilename() const
				 * @return The filename of the texture.
				 * @brief Get he filename which is the source of the texture.
				 * @throw
				 */
				inline virtual auto getFilename() const -> const std::string & override;

				/**
				 * @fn const std::vector<std::byte> & getData() const
				 * @return The array of pixels of the texture.
				 * @brief Get the texture as an array of pixels.
				 * @throw
				 */
				inline virtual auto getData() const -> const std::vector<std::byte> & override;

				/**
				 * @fn std::size_t getWidth() const
				 * @return The width of the texture.
				 * @brief Get the width of the texture.
				 * @throw
				 */
				inline virtual auto getWidth() const -> ece::size_t override;

				/**
				* @fn std::size_t getHeight() const
				* @return The height of the texture.
				* @brief Get the height of the texture.
				* @throw
				*/
				inline virtual auto getHeight() const -> ece::size_t override;

				/**
				 * @fn TextureTypeTarget getType() const
				 * @return The type of texture.
				 * @brief Get the type of texture.
				 * @throw
				 */
				inline virtual auto getType() const -> TypeTarget override;

				/**
				 * @fn Handle getHandle() const
				 * @return The id of the texture.
				 * @brief Get the id of the texture.
				 * @throw
				 */
				inline virtual auto getHandle() const -> Handle override;

				/**
				 * @fn void bind(const TextureTarget target)
				 * @param[in] target The buffer to use.
				 * @brief Copy the texture in a buffer to use it.
				 * @throw
				 */
				void virtual bind(const Target target) override;

				inline virtual void active(const unsigned int channel) override;

				template <typename T> void setParameter(const Parameter name, const T value);
				template <typename T> void setParameter(const Parameter name, const std::vector<T> & value);

				void generateMipmap();

				/**
				 * @fn void terminate()
				 * @brief Clear and delete the texture.
				 * @throw
				 */
				void terminate();

			private:
				/**
				 * @property _filename
				 * @brief
				 */
				std::string _filename;

				/**
				 * @property _data
				 * @brief The pixels of the texture.
				 */
				std::vector<std::byte> _data;

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

				/**
				 * @property _type
				 * @brief Type of texture used.
				 */
				TypeTarget _type;

				/**
				 * @property _handle
				 * @brief The texture handle to use for any OpenGL call.
				 */
				Handle _handle;
			};
		} // namespace image
	} // namespace renderer
} // namespace ece

#include "renderer/image/texture2d.inl"

#endif // TEXTURE_2D_HPP
