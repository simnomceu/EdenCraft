/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
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

#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#define PI 3.14159265359

/**
  * @remark is it possible to use a forward declaration of class here ?
  */
#include "utility/mathematics/matrix4u.hpp"
#include "utility/mathematics/vector3u.hpp"
#include "utility/mathematics/rectangle.hpp"

namespace ece
{
    namespace utility
    {
        namespace mathematics
        {
        	/**
        	 * @fn FloatMatrix4u lookAt(const FloatVector3u & eye, const FloatVector3u & target, const FloatVector3u & upAxis)
        	 * @param[in] eye The position of the camera.
        	 * @param[in] target The target to look at.
        	 * @param[in] upAxis The axis used as up direction.
        	 * @return A view matrix corresponding to the camera settings.
        	 * @brief Get a view matrix of the camera settings wished.
        	 */
        	FloatMatrix4u lookAt(const FloatVector3u & eye, const FloatVector3u & target, const FloatVector3u & upAxis);

        	/**
        	 * @fn FloatMatrix4u perspective(const float FOV, const float ratio, const float nearClipping, const float farClipping)
        	 * @param[in] FOV Field of view of the camera.
        	 * @param[in] ratio Ratio of the screen.
        	 * @param[in] nearClipping Nearest distance of the frustum view.
        	 * @param[in] farClipping Furthest distance of the frustum view.
        	 * @return A projection matrix corresponding to the rendering frustum settings with perspective.
        	 * @brief Get a perspective projection matrix of the frustum view.
        	 */
        	FloatMatrix4u perspective(const float FOV, const float ratio, const float nearClipping, const float farClipping);

        	/**
        	 * @fn FloatMatrix4u orthographic(const Rectangle<float> & screen, const float nearClipping, const float farClipping)
        	 * @param[in] screen The screen rectangle to project the rendering.
        	 * @param[in] nearClipping Nearest distance of the frustum view.
        	 * @param[in] farClipping Furthest distance of the frustum view.
        	 * @return A projection matrix corresponding to the rendering frustum settings, in an orthographic view.
        	 * @brief Get an orthographic projection matrix of the frustum view.
        	 */
        	FloatMatrix4u orthographic(const Rectangle<float> & screen, const float nearClipping, const float farClipping);
        } // namespace mathematics
    } // namespace utility
} // namespace ece

#endif // TRANSFORM_HPP
