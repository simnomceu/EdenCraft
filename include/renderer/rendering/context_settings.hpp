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

#ifndef CONTEXT_SETTINGS_HPP
#define CONTEXT_SETTINGS_HPP

#include "renderer/config.hpp"
#include "utility/indexing.hpp"
#include "window/common.hpp"

namespace ece
{
	namespace renderer
	{
		namespace rendering
		{
			/**
			 * @class ContextSettings
			 * @brief
			 */
			class ECE_RENDERER_API ContextSettings
			{
			public:
				/**
				 * @fn ContextSettings() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				ContextSettings() noexcept = default;

				/**
				 * @fn ContextSettings(const ContextSettings & copy) noexcept
				 * @param[in] copy The ContextSettings to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				ContextSettings(const ContextSettings & copy) noexcept = default;

				/**
				 * @fn ContextSettings(ContextSettings && move) noexcept
				 * @param[in] move The ContextSettings to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ContextSettings(ContextSettings && move) noexcept = default;

				/**
				 * @fn ~ContextSettings() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ContextSettings() noexcept = default;

				/**
				 * @fn ContextSettings & operator=(const ContextSettings & copy) noexcept
				 * @param[in] copy The ContextSettings to copy from.
				 * @return The ContextSettings copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				ContextSettings & operator=(const ContextSettings & copy) noexcept = default;

				/**
				 * @fn ContextSettings & operator=(ContextSettings && move) noexcept
				 * @param[in] move The ContextSettings to move.
				 * @return The ContextSettings moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ContextSettings & operator=(ContextSettings && move) noexcept = default;

				Version<2> minVersion;
				Version<2> maxVersion;

				bool doubleBuffering;
				std::size_t antialiasingSamples;

				std::size_t bitsPerPixel;
				std::size_t depthBits;
				std::size_t stencilBits;

				std::weak_ptr<Window> window;
				bool oldContext;
			};
		} // namespace rendering
	} // namespace renderer
} // namespace ece

#endif // CONTEXT_SETTINGS_HPP