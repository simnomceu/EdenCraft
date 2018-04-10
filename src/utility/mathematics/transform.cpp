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
	FloatMatrix4u lookAt(const FloatVector3u & eye, const FloatVector3u & target, const FloatVector3u & upAxis)
	{
		FloatVector3u x, y, z;
		z = eye - target;
		z = z.normalize();
		y = upAxis;
		x = y.cross(z);
		y = z.cross(x);
		x = x.normalize();
		y = y.normalize();

		return FloatMatrix4u{ x[0], y[0], z[0], 0.0f,
							   x[1], y[1], z[1], 0.0f,
							   x[2], y[2], z[2], 0.0f,
							   -x.dot(eye), -y.dot(eye), -z.dot(eye), 1.0f };
	}

	FloatMatrix4u perspective(const float FOV, const float ratio, const float nearClipping, const float farClipping)
	{
		float scale = static_cast<float>(std::tan(FOV * 0.5f * PI / 180.0f)) * nearClipping;
		Rectangle<float> screen(-ratio * scale, -scale, 2.0f * std::fabs(-ratio * scale), 2 * std::fabs(scale));
		float right = screen.getX() + screen.getWidth();
		float top = screen.getY() + screen.getHeight();

		return FloatMatrix4u{ 2.0f * nearClipping / screen.getWidth(), 0.0f, 0.0f, 0.0f,
							 0.0f, 2.0f * nearClipping / screen.getHeight(), 0.0f, 0.0f,
							 (right + screen.getX()) / (right - screen.getX()), (top + screen.getY()) / (top - screen.getY()),
							 -(farClipping + nearClipping) / (farClipping - nearClipping), -1.0f,
							 0.0f, 0.0f, -2.0f * farClipping * nearClipping / (farClipping - nearClipping), 0.0f };
	}


	FloatMatrix4u orthographic(const Rectangle<float> & screen, const float nearClipping, const float farClipping)
	{
		float right = screen.getX() + screen.getWidth();
		float top = screen.getY() + screen.getHeight();

		return FloatMatrix4u{ 2.0f / screen.getWidth(), 0.0f, 0.0f, 0.0f,
							 0.0f, 2.0f / screen.getHeight(), 0.0f, 0.0f,
							 0.0f, 0.0f, -2.0f / (farClipping - nearClipping), 0.0f,
							 -(right + screen.getX()) / (right - screen.getX()),
							 -(top + screen.getY()) / (top - screen.getY()),
							 -(farClipping + nearClipping) / (farClipping - nearClipping), 1.0f };
	}
}
