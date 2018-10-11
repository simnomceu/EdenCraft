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

#ifndef LINE_HPP
#define LINE_HPP

#include "graphic/config.hpp"
#include "utility/mathematics.hpp"
#include "core/resource.hpp"
#include "graphic/renderable/renderable.hpp"

namespace ece
{
	namespace graphic
	{
		namespace renderable
		{
			/**
			 * @class Line
			 * @brief
			 */
			class ECE_GRAPHIC_API Line : public Renderable
			{
			public:
				using LineReference = ResourceHandler<Line>;

				/**
				 * @fn constexpr Line() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Line() noexcept;

				Line(const FloatVector3u & begin, const FloatVector3u & end, const FloatVector3u & color, const float width) noexcept;

				/**
				 * @fn Line(const Line & copy) noexcept
				 * @param[in] copy The Line to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Line(const Line & copy) = default;

				/**
				 * @fn Line(Line && move) noexcept
				 * @param[in] move The Line to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Line(Line && move) noexcept = default;

				/**
				 * @fn ~Line() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Line() noexcept = default;

				/**
				 * @fn Line & operator=(const Line & copy) noexcept
				 * @param[in] copy The Line to copy from.
				 * @return The Line copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Line & operator=(const Line & copy) = default;

				/**
				 * @fn Line & operator=(Line && move) noexcept
				 * @param[in] move The Line to move.
				 * @return The Line moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Line & operator=(Line && move) noexcept = default;

				inline const FloatVector3u & getBegin() const noexcept;
				inline const FloatVector3u & getEnd() const noexcept;
				inline const FloatVector3u & getColor() const noexcept;
				inline float getWidth() const noexcept;

				inline void setBegin(const FloatVector3u & begin) noexcept;
				inline void setEnd(const FloatVector3u & end) noexcept;
				inline void setColor(const FloatVector3u & color) noexcept;
				inline void set(const float width) noexcept;

				virtual void draw() override;

			private:
				FloatVector3u _begin;
				FloatVector3u _end;
				FloatVector3u _color;
				float _width;

				VertexBuffer<SymetricStorage, std::vector<FloatVector3u>> _vertices;
			};
		} // namespace renderable
	} // namespace graphic
} // namespace ece

#include "graphic/renderable/line.inl"

#endif // LINE_HPP