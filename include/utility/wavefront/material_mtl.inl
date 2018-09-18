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

namespace ece
{
	namespace utility
	{
		namespace wavefront
		{
			inline MaterialMTL::MaterialMTL(const std::string & name) noexcept : _name(name), _ka{ LightFactor::Type::K, FloatVector3u{1.0f, 1.0f, 1.0f} }, _kd{ LightFactor::Type::K, FloatVector3u{ 1.0f, 1.0f, 1.0f } }, _ks{ LightFactor::Type::K, FloatVector3u{ 1.0f, 1.0f, 1.0f } },
				_tf{ LightFactor::Type::K, FloatVector3u{ 1.0f, 1.0f, 1.0f } }, _illum(0), _d{ 0.0f, { 0.0f, false } }, _ns(0), _sharpness(60), _ni(1.0f), _mapKa(), _mapKd(), _mapKs() {}

			inline const std::string & MaterialMTL::getName() const noexcept { return this->_name; }

			inline const FloatVector3u & MaterialMTL::getAmbientFactor() const noexcept { return std::get<FloatVector3u>(this->_ka._value); }

			inline const FloatVector3u & MaterialMTL::getDiffuseFactor() const noexcept { return std::get<FloatVector3u>(this->_kd._value); }

			inline const FloatVector3u & MaterialMTL::getSpecularFactor() const noexcept { return std::get<FloatVector3u>(this->_ks._value); }

			inline const FloatVector3u & MaterialMTL::getTransmissionFilter() const noexcept { return std::get<FloatVector3u>(this->_tf._value); }

			inline unsigned int MaterialMTL::getIllumination() const noexcept { return this->_illum; }

			inline float MaterialMTL::getDissolveFactor() const noexcept { return this->_d._factor; }

			inline float MaterialMTL::getSpecularExponent() const noexcept { return this->_ns; }

			inline unsigned int MaterialMTL::getSharpness() const noexcept { return this->_sharpness; }

			inline float MaterialMTL::getOpticalDensity() const noexcept { return this->_ni; }

			inline const std::string & MaterialMTL::getAmbientMap() const noexcept { return this->_mapKa; }

			inline const std::string & MaterialMTL::getDiffuseMap() const noexcept { return this->_mapKd; }

			inline const std::string &MaterialMTL::getSpecularMap() const noexcept { return this->_mapKs; }

			inline void MaterialMTL::setName(const std::string & name) noexcept { this->_name = name; }

			inline void MaterialMTL::setAmbientFactor(const FloatVector3u & ambient) noexcept { this->_ka._value = ambient; }

			inline void MaterialMTL::setDiffuseFactor(const FloatVector3u & diffuse) noexcept { this->_kd._value = diffuse; }

			inline void MaterialMTL::setSpecularFactor(const FloatVector3u & specular) noexcept { this->_ks._value = specular; }

			inline void MaterialMTL::setTransmissionFilter(const FloatVector3u & transmissionFilter) noexcept { this->_tf._value = transmissionFilter; }

			inline void MaterialMTL::setIllumination(const unsigned int illumination) noexcept { this->_illum = illumination; }

			inline void MaterialMTL::setDissolveFactor(const float dissolve) noexcept { this->_d._factor = dissolve; }

			inline void MaterialMTL::setSpecularExponent(const float exponent) noexcept { this->_ns = exponent; }

			inline void MaterialMTL::setSharpness(const unsigned int sharpness) noexcept { this->_sharpness = sharpness; }

			inline void MaterialMTL::setOpticalDensity(const float opticalDensity) noexcept { this->_ni = opticalDensity; }

			inline void MaterialMTL::setAmbientMap(const std::string & path) noexcept { this->_mapKa = path; }

			inline void MaterialMTL::setDiffuseMap(const std::string & path) noexcept { this->_mapKd = path; }

			inline void MaterialMTL::setSpecularMap(const std::string & path) noexcept { this->_mapKs = path; }
		} // namespace wavefront
	} // namespace utility
} // namespace ece