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

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "graphic/config.hpp"
#include "graphic/model.hpp"
#include "utility/mathematics.hpp"
#include "graphic/scene/projection.hpp"

namespace ece
{
	namespace graphic
	{
		namespace scene
		{
			/**
			 * @class Camera
			 * @brief
			 */
			class ECE_GRAPHIC_API Camera
			{
			public:
				/**
				 * @fn Camera() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline Camera() noexcept;

				/**
				 * @fn Camera(const Camera & copy)
				 * @param[in] copy The Camera to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Camera(const Camera & copy) = default;

				/**
				 * @fn Camera(Camera && move) noexcept
				 * @param[in] move The Camera to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Camera(Camera && move) noexcept = default;

				/**
				 * @fn ~Camera() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Camera() noexcept = default;

				/**
				 * @fn Camera & operator=(const Camera & copy)
				 * @param[in] copy The Camera to copy from.
				 * @return The Camera copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Camera & operator=(const Camera & copy) = default;

				/**
				 * @fn Camera & operator=(Camera && move) noexcept
				 * @param[in] move The Camera to move from.
				 * @return The Camera moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Camera & operator=(Camera && move) noexcept = default;

				/**
				 * @fn void lookAt(const Movable & object)
				 * @param[in] object The object target to look at.
				 * @brief Look at the center of a specific object.
				 * @throw
				 */
				inline void lookAt(const Movable & object);

				/**
				 * @fn void lookAt(const FloatVector3u & target)
				 * @param[in] target The point in space to look at.
				 * @brief Look at a specific location in space.
				 * @throw
				 */
				inline void lookAt(const FloatVector3u & target);

				/**
				 * @fn void lookUpTo(const FloatVector3u & direction)
				 * @param[in] direction The direction to look up to.
				 * @brief Look up to a specific direction.
				 * @throw
				 */
				inline void lookUpTo(const FloatVector3u & direction);

				/**
				 * @fn void moveTo(const Movable & object)
				 * @param[in] object The object to move to.
				 * @brief Move the camera to the specific object location.
				 * @throw
				 */
				inline void moveTo(const Movable & object);

				/**
				 * @fn void moveTo(const FloatVector3u & position)
				 * @param[in] position The position in space to move to.
				 * @brief Move to a specific location in space.
				 * @throw
				 */
				inline void moveTo(const FloatVector3u & position);

				/**
				 * @fn void moveIn(const FloatVector3u & direction)
				 * @param[in] direction The direction to move in.
				 * @brief Move in a direction.
				 * @throw
				 */
				inline void moveIn(const FloatVector3u & direction);

				/**
				 * @fn FloatMatrix4u getView() const
				 * @return The view matrix.
				 * @brief Get the view matrix according to the camera.
				 * @throw
				 */
				inline auto getView() const -> FloatMatrix4u;

                /**
                 * @fn const FloatMatrix4u & getProjection() const
                 * @return The projection matrix.
                 * @brief Get the projection matrix.
                 * @throw
                 */
                inline auto getProjection() const -> const Projection &;
                inline auto getProjection() -> Projection &;
			private:
				/**
				 * @fn void updatePosition(const FloatVector3u & position, const FloatVector3u & target)
				 * @param[in] position The position to set.
				 * @param[in] target The target to look at.
				 * @brief Update the view matrix.
				 * @throw
				 */
				void updatePosition(const FloatVector3u & position, const FloatVector3u & target);

				/**
				 * @property _position
				 * @brief The position of the camera.
				 */
				FloatVector3u _position;

				/**
				 * @property _target
				 * @brief The target to look at.
				 */
				FloatVector3u _target;

				/**
				 * @property _upAxis
				 * @brief The vector that defines the up axis.
				 */
				FloatVector3u _upAxis;

                /**
                 * @property _projection
                 * @brief The projection of the scene in a 2D plane by the camera.
                 */
                Projection _projection;
			};
		} // namespace scene
	} // namespace graphic
} // namespace ece

#include "graphic/scene/camera.inl"

#endif // CAMERA_HPP
