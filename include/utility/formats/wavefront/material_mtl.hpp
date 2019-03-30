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

#ifndef MATERIAL_MTL_HPP
#define MATERIAL_MTL_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/mathematics.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace wavefront
			{
				/**
				 * @class MaterialMTL
				 * @brief
				 */
				class ECE_UTILITY_API MaterialMTL
				{
				public:
					/**
					 * @fn MaterialMTL() noexcept
					 * @brief Default constructor.
					 * @throw noexcept
					 */
					inline MaterialMTL(const std::string & name = "unnamed") noexcept;

					/**
					 * @fn MaterialMTL(const MaterialMTL & copy)
					 * @param[in] copy The MaterialMTL to copy from.
					 * @brief Default copy constructor.
					 * @throw
					 */
					MaterialMTL(const MaterialMTL & copy) = default;

					/**
					 * @fn MaterialMTL(MaterialMTL && move) noexcept
					 * @param[in] move The MaterialMTL to move.
					 * @brief Default move constructor.
					 * @throw noexcept
					 */
					MaterialMTL(MaterialMTL && move) noexcept = default;

					/**
					 * @fn ~MaterialMTL() noexcept
					 * @brief Default destructor.
					 * @throw noexcept
					 */
					~MaterialMTL() noexcept = default;

					/**
					 * @fn MaterialMTL & operator=(const MaterialMTL & copy)
					 * @param[in] copy The MaterialMTL to copy from.
					 * @return The MaterialMTL copied.
					 * @brief Default copy assignment operator.
					 * @throw
					 */
					MaterialMTL & operator=(const MaterialMTL & copy) = default;

					/**
					 * @fn MaterialMTL & operator=(MaterialMTL && move) noexcept
					 * @param[in] move The MaterialMTL to move.
					 * @return The MaterialMTL moved.
					 * @brief Default move assignment operator.
					 * @throw noexcept
					 */
					MaterialMTL & operator=(MaterialMTL && move) noexcept = default;

					struct LightFactor
					{
						enum Type
						{
							K,
							K_SPECTRAL,
							K_XYZ
						};

						struct Spectral
						{
							std::string file;
							float factor;
						};

						Type statement;
						std::variant<FloatVector3u, Spectral> value;
					};

					struct Dissolve
					{
						float factor;

						struct {
							float value;
							bool enabled;
						} halo;
					};

					std::string name;
					LightFactor ambient;
					LightFactor diffuse;
					LightFactor specular;
					LightFactor transmissionFilter;
					unsigned int illumination;
					Dissolve dissolve;
					float specularExponent;
					unsigned int sharpness;
					float opticalDensity;
					std::string mapAmbient;
					std::string mapDiffuse;
					std::string mapSpecular;
				};
			} // namespace wavefront
		} // namespace formats
	} // namespace utility
} // namespace ece

#include "utility/formats/wavefront/material_mtl.inl"

#endif // MATERIAL_MTL_HPP