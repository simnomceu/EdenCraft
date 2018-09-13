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
#include "utility/mathematics/vector3u.hpp"

#include <variant>

namespace ece
{
	namespace utility
	{
		namespace wavefront
		{
			using mathematics::FloatVector3u;

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

				inline const std::string & getName() const noexcept;
				inline const FloatVector3u & getAmbientFactor() const noexcept;
				inline const FloatVector3u & getDiffuseFactor() const noexcept;
				inline const FloatVector3u & getSpecularFactor() const noexcept;
				inline const FloatVector3u & getTransmissionFilter() const noexcept;
				inline unsigned int getIllumination() const noexcept;
				inline float getDissolveFactor() const noexcept;
				inline unsigned int getSpecularExponent() const noexcept;
				inline unsigned int getSharpness() const noexcept;
				inline float getOpticalDensity() const noexcept;
				inline const std::string & getAmbientMap() const noexcept;
				inline const std::string & getDiffuseMap() const noexcept;
				inline const std::string & getSpecularMap() const noexcept;

				inline void setName(const std::string & name) noexcept;
				inline void setAmbientFactor(const FloatVector3u & ambient) noexcept;
				inline void setDiffuseFactor(const FloatVector3u & diffuse) noexcept;
				inline void setSpecularFactor(const FloatVector3u & specular) noexcept;
				inline void setTransmissionFilter(const FloatVector3u & transmissionFilter) noexcept;
				inline void setIllumination(const unsigned int illumination) noexcept;
				inline void setDissolveFactor(const float dissolve) noexcept;
				inline void setSpecularExponent(const unsigned int exponent) noexcept;
				inline void setSharpness(const unsigned int sharpness) noexcept;
				inline void setOpticalDensity(const float opticalDensity) noexcept;
				inline void setAmbientMap(const std::string & path) noexcept;
				inline void setDiffuseMap(const std::string & path) noexcept;
				inline void setSpecularMap(const std::string & path) noexcept;

			private:


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
						std::string _file;
						float factor;
					};

					Type _statement;
					std::variant<FloatVector3u, Spectral> _value;
				};

				struct Dissolve
				{
					float _factor;
					
					struct {
						float _value;
						bool _enabled;
					} halo;
				};

				std::string _name;
				LightFactor _ka;
				LightFactor _kd;
				LightFactor _ks;
				LightFactor _tf;
				unsigned int _illum;
				Dissolve _d;
				unsigned int _ns;
				unsigned int _sharpness;
				float _ni;
				std::string _mapKa;
				std::string _mapKd;
				std::string _mapKs;
			};
		} // namespace wavefront
	} // namespace utility
} // namespace ece

#include "utility/wavefront/material_mtl.inl"

#endif // MATERIAL_MTL_HPP