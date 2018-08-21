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

#ifndef PROJECTION_HPP
#define PROJECTION_HPP

#include "graphic/config.hpp"
#include "window/common/ratio.hpp"
#include "utility/mathematics/matrix4u.hpp"

namespace ece
{
	namespace utility
	{
		namespace mathematics
		{
			template <typename T> class Rectangle;
		}
	}

	namespace graphic
	{
		namespace scene
		{
			using utility::mathematics::FloatMatrix4u;
			using window::common::Ratio;
			using utility::mathematics::Rectangle;

			/**
			 * @class Projection
			 * @brief
			 */
			class ECE_GRAPHIC_API Projection
			{
			public:
				/**
				 * @fn Projection() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline Projection() noexcept;

				/**
				 * @fn Projection(const Projection & copy)
				 * @param[in] copy The Projection to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Projection(const Projection & copy) = default;

				/**
				 * @fn Projection(Projection && move) noexcept
				 * @param[in] move The Projection to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Projection(Projection && move) noexcept = default;

				/**
				 * @fn ~Projection() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Projection() noexcept = default;

				/**
				 * @fn Projection & operator=(const Projection & copy)
				 * @param[in] copy The Projection to copy from.
				 * @return The Projection copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Projection & operator=(const Projection & copy) = default;

				/**
				 * @fn Projection & operator=(Projection && move) noexcept
				 * @param[in] move The Projection to move from.
				 * @return The Projection moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Projection & operator=(Projection && move) noexcept = default;

				/**
				 * @fn void setPerspective(const double FOV, const Ratio ratio, const double nearClipping, const double farClipping)
				 * @param[in] FOV The field of view of the camera.
				 * @param[in] ratio The ratio of the screen.
				 * @param[in] nearClipping The nearest plan of the scene to capture.
				 * @param[in] farClipping The furthest plan of the scene to capture.
				 * @brief Set the projection matrix.
				 * @throw
				 */
				inline void setPerspective(const double FOV, const Ratio ratio, const double nearClipping, const double farClipping);

				/**
				 * @fn void setOrthographic(const Rectangle<float> & screen, const float nearClipping, const float farClipping)
				 * @param[in] screen The screen rectangle to project the rendering.
				 * @param[in] nearClipping Nearest distance of the frustum view.
				 * @param[in] farClipping Furthest distance of the frustum view.
				 * @brief Set the projection matrix.
				 * @throw
				 */
				inline void setOrthographic(const Rectangle<float> & screen, const float nearClipping, const float farClipping);

				/**
				 * @fn const FloatMatrix4u & getProjection() const
				 * @return The projection matrix.
				 * @brief Get the projection matrix.
				 * @throw
				 */
				inline const FloatMatrix4u & getProjection() const;

			private:
				/**
				 * @property _projection
				 * @brief The projection matrix.
				 */
				FloatMatrix4u _projection;
			};
		} // namespace scene
	} // namespace graphic
} // namespace ece

#include "graphic/scene/projection.inl"

#endif // PROJECTION_HPP
