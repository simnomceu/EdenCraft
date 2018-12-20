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
			class ECE_RENDERER_API Texture : public virtual_enable_shared_from_this<Texture>
			{
			public:
				enum class TypeTarget : unsigned short int
				{
					TEXTURE_2D = 0x00,
					PROXY_2D = 0x01,
					TEXTURE_1D_ARRAY = 0x02,
					PROXY_1D_ARRAY = 0x03,
					RECTANGLE = 0x04,
					PROXY_RECTANGLE = 0x05,
					CUBE_MAP_POSITIVE_X = 0x06,
					CUBE_MAP_NEGATIVE_X = 0x07,
					CUBE_MAP_POSITIVE_Y = 0x08,
					CUBE_MAP_NEGATIVE_Y = 0x09,
					CUBE_MAP_POSITIVE_Z = 0x10,
					CUBE_MAP_NEGATIVE_Z = 0x11,
					PROXY_CUBE_MAP = 0x12
				};

				enum class Target : unsigned short int
				{
					TEXTURE_1D = 0x00,
					TEXTURE_2D = 0x01,
					TEXTURE_3D = 0x02,
					TEXTURE_1D_ARRAY = 0x03,
					TEXTURE_2D_ARRAY = 0x04,
					RECTANGLE = 0x05,
					CUBE_MAP = 0x06,
					CUBE_MAP_ARRAY = 0x07,
					BUFFER = 0x08,
					TEXTURE_2D_MULTISAMPLE = 0x09,
					TEXTURE_2D_MULTISAMPLE_ARRAY = 0x10
				};

				enum class Parameter : unsigned short int
				{
					DEPTH_STENCIL_MODE = 0x00,
					BASE_LEVEL = 0x01,
					COMPARE_FUNC = 0x02,
					COMPARE_MODE = 0x03,
					LOD_BIAS = 0x04,
					MIN_FILTER = 0x05,
					MAG_FILTER = 0x06,
					MIN_LOD = 0x07,
					MAX_LOD = 0x08,
					MAX_LEVEL = 0x09,
					SWIZZLE_R = 0x10,
					SWIZZLE_G = 0x11,
					SWIZZLE_B = 0x12,
					SWIZZLE_A = 0x13,
					WRAP_S = 0x14,
					WRAP_T = 0x15,
					WRAP_R = 0x16
				};

				/**
				 * @fn void loadFromFile(const TypeTarget type, const std::string & filename)
				 * @param[in] type The type of texture to define.
				 * @param[in] filename The source file to use.
				 * @brief Load a texture from a file.
				 * @throw
				 */
				virtual void loadFromFile(const TypeTarget type, const std::string & filename) = 0;

				/**
				 * @fn const std::string & getFilename() const
				 * @return The filename of the texture.
				 * @brief Get he filename which is the source of the texture.
				 * @throw
				 */
				virtual auto getFilename() const -> const std::string & = 0;

				/**
				 * @fn const std::vector<std::byte> & getData() const
				 * @return The array of pixels of the texture.
				 * @brief Get the texture as an array of pixels.
				 * @throw
				 */
				virtual auto getData() const -> const std::vector<std::byte> & = 0;

				/**
				 * @fn std::size_t getWidth() const
				 * @return The width of the texture.
				 * @brief Get the width of the texture.
				 * @throw
				 */
				virtual auto getWidth() const -> std::size_t = 0;

				/**
				* @fn std::size_t getHeight() const
				* @return The height of the texture.
				* @brief Get the height of the texture.
				* @throw
				*/
				virtual auto getHeight() const -> std::size_t = 0;

				/**
				 * @fn TextureTypeTarget getType() const
				 * @return The type of texture.
				 * @brief Get the type of texture.
				 * @throw
				 */
				virtual auto getType() const -> TypeTarget = 0;

				/**
				 * @fn Handle getHandle() const
				 * @return The id of the texture.
				 * @brief Get the id of the texture.
				 * @throw
				 */
				virtual auto getHandle() const -> Handle = 0;

				/**
				 * @fn void bind(const TextureTarget target)
				 * @param[in] target The buffer to use.
				 * @brief Copy the texture in a buffer to use it.
				 * @throw
				 */
				virtual void bind(const Target target) = 0;

				virtual void active(const unsigned int channel) = 0; 

				/**
				 * @fn void terminate()
				 * @brief Clear and delete the texture.
				 * @throw
				 */
				virtual void terminate() = 0;

			protected:
				void setCurrent(Target target);
				auto isCurrent(Target target) const noexcept -> bool;
			};
		} // namespace image
	} // namespace renderer
} // namespace ece

#endif // TEXTURE_HPP
