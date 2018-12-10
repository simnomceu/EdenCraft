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
			auto lookAt(const FloatVector3u & eye, const FloatVector3u & target, const FloatVector3u & upAxis) -> FloatMatrix4u
			{
				auto z = FloatVector3u{ eye - target };
				z = z.normalize();
				auto x = upAxis.cross(z);
				x = x.normalize();
				const auto y = z.cross(x);

				return FloatMatrix4u{ x[0], y[0], z[0], 0.0f,
									   x[1], y[1], z[1], 0.0f,
									   x[2], y[2], z[2], 0.0f,
									   -x.dot(eye), -y.dot(eye), -z.dot(eye), 1.0f };
			}

			auto perspective(const float FOV, const float ratio, const float nearClipping, const float farClipping) -> FloatMatrix4u
			{
				const auto tanFOV = static_cast<float>(std::tan(FOV * 0.5f * PI / 180.0f));
				const auto rangeClipping = nearClipping - farClipping;

				return FloatMatrix4u{ 1.0f / (tanFOV * ratio), 0.0f, 0.0f, 0.0f,
									 0.0f, 1.0f / tanFOV, 0.0f, 0.0f,
									 0.0f, 0.0f, (-nearClipping - farClipping) / -rangeClipping, -1.0f,
									 0.0f, 0.0f, 2.0f * farClipping * nearClipping / rangeClipping, 0.0f };
			}


			auto orthographic(const Rectangle<float> & screen, const float nearClipping, const float farClipping) -> FloatMatrix4u
			{
				const auto right = screen.x + screen.width;
				const auto top = screen.y + screen.height;

				const auto rangeClipping = farClipping - nearClipping;

				return FloatMatrix4u{ 2.0f / screen.width, 0.0f, 0.0f, 0.0f,
									 0.0f, 2.0f / screen.height, 0.0f, 0.0f,
									 0.0f, 0.0f, 2.0f / rangeClipping, 0.0f,
									 -(right + screen.x) / screen.width, -(top + screen.y) / screen.height, -(farClipping + nearClipping) / rangeClipping, 1.0f };
			}

			auto scale(const FloatVector3u &  scale) -> FloatMatrix4u
			{
				return FloatMatrix4u{
					scale[0], 0.0f, 0.0f, 0.0f,
					0.0f, scale[1], 0.0f, 0.0f,
					0.0f, 0.0f, scale[2], 0.0f,
					0.0f, 0.0f, 0.0f, 1.0f
				};
			}

			auto translate(const FloatVector3u & translation) -> FloatMatrix4u
			{
				return FloatMatrix4u{
					1.0f, 0.0f, 0.0f, translation[0],
					0.0f, 1.0f, 0.0f, translation[1],
					0.0f, 0.0f, 1.0f, translation[2],
					0.0f, 0.0f, 0.0f, 1.0f
				};
			}

			auto rotate(const FloatVector3u & axis, const float angle) -> FloatMatrix4u
			{
				const auto angleCos = std::cos(angle);
				const auto angleSin = std::sin(angle);

				const auto minusAngleCos = 1 - angleCos;

				const auto ac = axis[0] * axis[1] * minusAngleCos;
				const auto bc = axis[0] * axis[2] * minusAngleCos;
				const auto cc = axis[1] * axis[2] * minusAngleCos;

				const auto as = axis[0] * angleSin;
				const auto bs = axis[1] * angleSin;
				const auto cs = axis[2] * angleSin;

				return FloatMatrix4u{
					angleCos + axis[0] * axis[0] * minusAngleCos, ac - cs, bc + bs, 0.0f,
					ac + cs, angleCos + axis[1] * axis[1] * minusAngleCos, cc - as, 0.0f,
					bc - bs, cc + as, angleCos + axis[2] * axis[2] * minusAngleCos, 0.0f,
					0.0f, 0.0f, 0.0f, 1.0f
				};
			}
		} // namespace mathematics
	} // namespace utility
} // namespace ece
