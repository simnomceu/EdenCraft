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

#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include "renderer/config.hpp"
#include "renderer/resource/object_opengl.hpp"

namespace ece
{
	namespace renderer
	{
		namespace buffer
		{
			using resource::ObjectOpenGL;

			/**
			 * @class VertexArray
			 * @brief
			 */
			class ECE_RENDERER_API VertexArray: public ObjectOpenGL
			{
			public:
				/**
				 * @fn constexpr VertexArray() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline VertexArray() noexcept;

				/**
				 * @fn VertexArray(const VertexArray & copy) noexcept
				 * @param[in] copy The VertexArray to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				VertexArray(const VertexArray & copy) noexcept = default;

				/**
				 * @fn VertexArray(VertexArray && move) noexcept
				 * @param[in] move The VertexArray to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				VertexArray(VertexArray && move) noexcept = default;

				/**
				 * @fn ~VertexArray() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~VertexArray() noexcept = default;

				/**
				 * @fn VertexArray & operator=(const VertexArray & copy) noexcept
				 * @param[in] copy The VertexArray to copy from.
				 * @return The VertexArray copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				VertexArray & operator=(const VertexArray & copy) noexcept = default;

				/**
				 * @fn VertexArray & operator=(VertexArray && move) noexcept
				 * @param[in] move The VertexArray to move.
				 * @return The VertexArray moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				VertexArray & operator=(VertexArray && move) noexcept = default;

				inline virtual void bind() const override;

				inline virtual void terminate() override;

				inline int addLocation() noexcept;

			private:
				int _globalLocation;
			};
		} // namespace buffer
	} // namespace renderer
} // namespace ece

#include "renderer/buffer/vertex_array.inl"

#endif // VERTEX_ARRAY_HPP