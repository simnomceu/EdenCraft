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

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "renderer/config.hpp"
#include "renderer/pch.hpp"
#include "renderer/image/texture.hpp"

namespace ece
{
	namespace renderer
	{
		namespace rendering
		{
			class RenderTarget;
			class RenderContext;
			using image::Texture;

			/**
			 * @class Renderer
			 * @brief Manage objects that need to be rendered.
			 */
			class ECE_RENDERER_API Renderer
			{
			public:
				/**
				 * @fn constexpr Renderer() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr Renderer() noexcept = delete;

				/**
				 * @fn Renderer(const Renderer & copy) noexcept
				 * @param[in] copy The Renderer to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Renderer(const Renderer & copy) noexcept = delete;

				/**
				 * @fn Renderer(Renderer && move) noexcept
				 * @param[in] move The Renderer to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Renderer(Renderer && move) noexcept = delete;

				/**
				 * @fn ~Renderer()
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Renderer() noexcept = delete;

				/**
				 * @fn Renderer & operator=(const Renderer & copy) noexcept
				 * @param[in] copy The Renderer to copy from.
				 * @return The Renderer copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Renderer & operator=(const Renderer & copy) noexcept = delete;

				/**
				 * @fn Renderer & operator=(Renderer && move) noexcept
				 * @param[in] move The Renderer to move.
				 * @return The Renderer moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Renderer & operator=(Renderer && move) noexcept = delete;

				// NOTE: can't be inlined, else there is a bug with static attributes which are not used in the DLL scope. 
				//       So MSVC choose to optimize it and remove the attribute initialization.
				static void setCurrentTarget(const std::weak_ptr<RenderTarget> & target);
				static auto getCurrentTarget() -> std::weak_ptr<RenderTarget>;

				static void setCurrentContext(const std::weak_ptr<RenderContext> & context);
				static auto getCurrentContext() -> std::weak_ptr<RenderContext>;

				static void setCurrentTexture(Texture::Target target, const std::weak_ptr<Texture> & texture);
				static auto getCurrentTexture(Texture::Target target) -> std::weak_ptr<Texture>;

				static auto isInitialized() noexcept -> bool;

			private:
				static std::weak_ptr<RenderTarget> _currentTarget;
				static std::weak_ptr<RenderContext> _currentContext;
				static std::map<Texture::Target, std::weak_ptr<Texture>> _currentTextures;
			};
		} // namespace rendering
	} // namespace renderer
} // namespace ece

#endif // RENDERER_HPP
