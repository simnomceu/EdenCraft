/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.    ooooo     ooo ooooo
															 d8P'  `Y8b   `888'     `8' `888'
															888            888       8   888
															888            888       8   888
															888     ooooo  888       8   888
															`88.    .88'   `88.    .8'   888
															 `Y8bood8P'      `YbodP'    o888o


				This file is part of EdenCraft Engine - GUI module.
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

#ifndef IMGUI_INTERFACE_HPP
#define IMGUI_INTERFACE_HPP

#include "gui/pch.hpp"
#include "gui/config.hpp"
#include "graphic/renderable.hpp"

namespace ece
{
	namespace gui
	{
		namespace imgui
		{
			/**
			 * @class Interface
			 * @brief
			 */
			class Interface: public Renderable
			{
			public:
				/**
				 * @fn constexpr Interface() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Interface() noexcept;

				/**
				 * @fn Interface(const Interface & copy) noexcept
				 * @param[in] copy The Interface to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Interface(const Interface & copy) noexcept = default;

				/**
				 * @fn Interface(Interface && move) noexcept
				 * @param[in] move The Interface to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Interface(Interface && move) noexcept = default;

				/**
				 * @fn ~Interface() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Interface() noexcept;

				/**
				 * @fn Interface & operator=(const Interface & copy) noexcept
				 * @param[in] copy The Interface to copy from.
				 * @return The Interface copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Interface & operator=(const Interface & copy) noexcept = default;

				/**
				 * @fn Interface & operator=(Interface && move) noexcept
				 * @param[in] move The Interface to move.
				 * @return The Interface moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Interface & operator=(Interface && move) noexcept = default;

				virtual void prepare() override;
				virtual void draw(std::shared_ptr<Shader> program) override;
				void update();

			private:
//				VertexBuffer<SymetricStorage, std::vector<ImDrawVert>> _vbo;
//				IndexBuffer<SymetricStorage, std::vector<Submesh::Face>> _ibo;

				IntVector2u _displaySize;
				FloatMatrix4u _projection;
			};
		} // namespace imgui
	} // namespace gui
} // namespace ece

#endif // IMGUI_INTERFACE_HPP