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

#ifndef POINT_HPP
#define POINT_HPP

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
			 * @class Point
			 * @brief
			 */
			class ECE_GRAPHIC_API Point : public Renderable
			{
			public:
				using PointReference = ResourceHandler<Point>;

				/**
				 * @fn constexpr Point() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Point() noexcept;

				Point(const FloatVector3u & color, const FloatVector3u position, const float size) noexcept;

				/**
				 * @fn Point(const Point & copy) noexcept
				 * @param[in] copy The Point to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Point(const Point & copy) = default;

				/**
				 * @fn Point(Point && move) noexcept
				 * @param[in] move The Point to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Point(Point && move) noexcept = default;

				/**
				 * @fn ~Point() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Point() noexcept = default;

				/**
				 * @fn Point & operator=(const Point & copy) noexcept
				 * @param[in] copy The Point to copy from.
				 * @return The Point copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Point & operator=(const Point & copy) = default;

				/**
				 * @fn Point & operator=(Point && move) noexcept
				 * @param[in] move The Point to move.
				 * @return The Point moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Point & operator=(Point && move) noexcept = default;

				inline auto getPosition() const noexcept -> const FloatVector3u &;
				inline auto getColor() const noexcept -> const FloatVector3u &;
				inline auto getSize() const noexcept -> float;

				inline void setPosition(const FloatVector3u & position) noexcept;
				inline void setColor(const FloatVector3u & color) noexcept;
				inline void setSize(const float size) noexcept;

				virtual void draw([[maybe_unused]] std::shared_ptr<Shader> program) override;

			private:
				FloatVector3u _position;
				FloatVector3u _color;
				float _size;

				VertexBuffer<SymetricStorage, std::vector<FloatVector3u>> _vertices;
			};
		} // namespace renderable
	} // namespace graphic
} // namespace ece

#include "graphic/renderable/point.inl"

#endif // POINT_HPP