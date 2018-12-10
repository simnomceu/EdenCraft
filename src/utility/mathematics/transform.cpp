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

#include "utility/mathematics/transform.hpp"

#include <cmath>

namespace ece
{
	namespace utility
	{
		namespace mathematics
		{
			FloatMatrix4u lookAt(const FloatVector3u & eye, const FloatVector3u & target, const FloatVector3u & upAxis)
			{
				FloatVector3u x, y, z;
				z = eye - target;
				z = z.normalize();
				x = upAxis.cross(z);
				x = x.normalize();
				y = z.cross(x);

				return FloatMatrix4u{ x[0], y[0], z[0], 0.0f,
									   x[1], y[1], z[1], 0.0f,
									   x[2], y[2], z[2], 0.0f,
									   -x.dot(eye), -y.dot(eye), -z.dot(eye), 1.0f };
			}

			FloatMatrix4u perspective(const float FOV, const float ratio, const float nearClipping, const float farClipping)
			{
				const float tanFOV = static_cast<float>(std::tan(FOV * 0.5f * PI / 180.0f));
				const float rangeClipping = nearClipping - farClipping;

				return FloatMatrix4u{ 1.0f / (tanFOV * ratio), 0.0f, 0.0f, 0.0f,
									 0.0f, 1.0f / tanFOV, 0.0f, 0.0f,
									 0.0f, 0.0f, (-nearClipping - farClipping) / -rangeClipping, -1.0f,
									 0.0f, 0.0f, 2.0f * farClipping * nearClipping / rangeClipping, 0.0f };
			}


			FloatMatrix4u orthographic(const Rectangle<float> & screen, const float nearClipping, const float farClipping)
			{
				float right = screen.x + screen.width;
				float top = screen.y + screen.height;

				return FloatMatrix4u{ 2.0f / screen.width, 0.0f, 0.0f, 0.0f,
									 0.0f, 2.0f / screen.height, 0.0f, 0.0f,
									 0.0f, 0.0f, 2.0f / (farClipping - nearClipping), 0.0f,
									 -(right + screen.x) / screen.width, -(top + screen.y) / screen.height, -(farClipping + nearClipping) / (farClipping - nearClipping), 1.0f };
			}

			FloatMatrix4u scale(const FloatVector3u &  scale)
			{
				FloatMatrix4u matrix;
				matrix[0][0] = scale[0];
				matrix[1][1] = scale[1];
				matrix[2][2] = scale[2];
				matrix[3][3] = 1.0f;
				return std::move(matrix);
			}

			FloatMatrix4u translate(const FloatVector3u & translation)
			{
				auto matrix = FloatMatrix4u::Identity();
				matrix[0][3] = translation[0];
				matrix[1][3] = translation[1];
				matrix[2][3] = translation[2];
				return matrix;
			}

			FloatMatrix4u rotate(const FloatVector3u & axis, const float angle)
			{
				FloatMatrix4u matrix;
				matrix[0][0] = std::cos(angle) + axis[0] * axis[0] * (1 - std::cos(angle));
				matrix[0][1] = axis[0] * axis[1] * (1 - std::cos(angle)) - axis[2] * std::sin(angle);
				matrix[0][2] = axis[0] * axis[2] * (1 - std::cos(angle)) + axis[1] * std::sin(angle);
				matrix[1][0] = axis[0] * axis[1] * (1 - std::cos(angle)) + axis[2] * std::sin(angle);
				matrix[1][1] = std::cos(angle) + axis[1] * axis[1] * (1 - std::cos(angle));
				matrix[1][2] = axis[1] * axis[2] * (1 - std::cos(angle)) - axis[0] * std::sin(angle);
				matrix[2][0] = axis[0] * axis[2] * (1 - std::cos(angle)) - axis[1] * std::sin(angle);
				matrix[2][1] = axis[1] * axis[2] * (1 - std::cos(angle)) + axis[0] * std::sin(angle);
				matrix[2][2] = std::cos(angle) + axis[2] * axis[2] * (1 - std::cos(angle));
				matrix[3][3] = 1.0f;
				return matrix;
			}
		} // namespace mathematics
	} // namespace utility
} // namespace ece
