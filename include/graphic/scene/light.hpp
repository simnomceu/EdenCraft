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

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "graphic/config.hpp"
#include "utility/mathematics.hpp"
#include "core/resource.hpp"
#include <optional>

namespace ece
{
	namespace renderer
	{
		namespace shader
		{
			class Shader;
		} // namespace shader
	} // namespace renderable

	namespace graphic
	{
		namespace scene
		{
			using renderer::shader::Shader;

			/**
			 * @class Light
			 * @brief
			 */
			class ECE_GRAPHIC_API Light
			{
			public:
				using Reference = ResourceHandler<Light>;

				struct CutOff
				{
					float inner;
					float outer;
				};

				struct Attenuation
				{
					float constant;
					float linear;
					float quadratic;
				};

				/**
				 * @fn Light() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Light() noexcept;

				/**
				 * @fn Light(const Light & copy) noexcept
				 * @param[in] copy The Light to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Light(const Light & copy) noexcept = default;

				/**
				 * @fn Light(Light && move) noexcept
				 * @param[in] move The Light to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Light(Light && move) noexcept = default;

				/**
				 * @fn ~Light() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Light() noexcept = default;

				/**
				 * @fn Light & operator=(const Light & copy) noexcept
				 * @param[in] copy The Light to copy from.
				 * @return The Light copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Light & operator=(const Light & copy) noexcept = default;

				/**
				 * @fn Light & operator=(Light && move) noexcept
				 * @param[in] move The Light to move.
				 * @return The Light moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Light & operator=(Light && move) noexcept = default;

				inline void setAmbient(const float ambient) noexcept;
				inline void setDiffuse(const float diffuse) noexcept;
				inline void setSpecular(const float specular) noexcept;
				inline void setColor (const FloatVector3u & color) noexcept;
				inline void setPosition(const FloatVector3u & position) noexcept;
				inline void setDirection(const FloatVector3u & direction) noexcept;
				inline void setAttenuation(const Attenuation & attenuation) noexcept;
				inline void setCutOff(const CutOff & cutOff) noexcept;

				inline float getAmbient() const noexcept;
				inline float getDiffuse() const noexcept;
				inline float getSpecular() const noexcept;
				inline const FloatVector3u & getColor() const noexcept;
				inline const FloatVector3u & getPosition() const noexcept;
				inline const FloatVector3u & getDirection() const noexcept;
				inline Attenuation getAttenuation() const noexcept;
				inline CutOff getCutoff() const noexcept;

				inline void resetPosition() noexcept;
				inline void resetDirection() noexcept;
				inline void resetAttenuation() noexcept;
				inline void resetCutOff() noexcept;
				inline void useBlinn(const bool used) noexcept;

				inline bool isPositionUsed() const noexcept;
				inline bool isDirectionUsed() const noexcept;
				inline bool isAttenuationUsed() const noexcept;
				inline bool isCutOffUsed() const noexcept;
				inline bool isBlinnUsed() const noexcept;

				void apply(Shader & shader);

			protected:
				// Use structure here ? "factors" ?
				float _ambient;
				float _diffuse;
				float _specular;

				FloatVector3u _color;

				std::optional<FloatVector3u> _position;
				std::optional<FloatVector3u> _direction;

				std::optional<Attenuation> _attenuation;

				std::optional<CutOff> _cutOff;

				bool _useBlinn;
			};
		} // namespace scene
	} // namespace graphic
} // namespace ece

#include "graphic/scene/light.inl"

#endif // LIGHT_HPP
