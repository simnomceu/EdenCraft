/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.                                  oooo         o8o
															 d8P'  `Y8b                                 `888         `"'
															888           oooo d8b  .oooo.   oo.ooooo.   888 .oo.   oooo   .ooooo.
															888           `888""8P `P  )88b   888' `88b  888P"Y88b  `888  d88' `"Y8
															888     ooooo  888      .oP"888   888   888  888   888   888  888
															`88.    .88'   888     d8(  888   888   888  888   888   888  888   .o8
															 `Y8bood8P'   d888b    `Y888""8o  888bod8P' o888o o888o o888o `Y8bod8P'
																							  888
																							 o888o



				This file is part of EdenCraft Engine - Graphic module.
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

#ifndef SHADER_SOURCE_HPP
#define SHADER_SOURCE_HPP

#include <string>

#include "renderer/enum.hpp"

namespace ece
{
	/**
	 * @class ShaderSource
	 * @brief The sources of a shader program.
	 * @remark Not sure this class is still useful.
	 */
	class ShaderSource
	{
	public:
		/**
		 * @fn constexpr ShaderSource() noexcept
		 * @brief Default constructor.
		 * @throw noexcept
		 */
		constexpr ShaderSource() noexcept = default;

		/**
		 * @fn ShaderSource(const ShaderSource & copy) noexcept
		 * @param[in] copy The ShaderSource to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		ShaderSource(const ShaderSource & copy) noexcept = default;

		/**
		 * @fn ShaderSource(ShaderSource && move) noexcept
		 * @param[in] move The ShaderSource to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		ShaderSource(ShaderSource && move) noexcept = default;

		/**
		 * @fn ~ShaderSource() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~ShaderSource() noexcept = default;

		/**
		 * @fn ShaderSource & operator=(const ShaderSource & copy) noexcept
		 * @param[in] copy The ShaderSource to copy from.
		 * @return The ShaderSource copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		ShaderSource & operator=(const ShaderSource & copy) noexcept = default;

		/**
		 * @fn ShaderSource & operator=(ShaderSource && move) noexcept
		 * @param[in] move The ShaderSource to move from.
		 * @return The ShaderSource moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		ShaderSource & operator=(ShaderSource && move) noexcept = default;

		/**
		 * @fn const ShaderType & getType() const
		 * @return The type of shader.
		 * @brief Get the type of the shader.
		 * @throw
		 */
		virtual const ShaderType & getType() const = 0;

		/**
		 * @fn const std::string & getSource() const
		 * @return The source.
		 * @brief Get the source of the shader.
		 * @throw
		 */
		virtual const std::string & getSource() const = 0;
	};
}

#endif // SHADER_SOURCE_HPP
