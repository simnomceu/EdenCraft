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

namespace ece
{
	namespace renderer
	{
		namespace resource
		{
			class Shader;
		} // namespace resource
	} // namespace renderable

	namespace graphic
	{
		namespace model
		{
			using renderer::resource::Shader;

			enum class LightType : int
			{
				BASIC_LIGHT = 0,
				DIRECTIONAL_LIGHT = 1,
				POINT_LIGHT = 2,
				SPOT_LIGHT = 3
			};

			/**
			 * @class Light
			 * @brief
			 */
			class ECE_GRAPHIC_API Light
			{
			public:
				using Reference = ResourceHandler<Light>;

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
				inline void setConstant(const float constant) noexcept;
				inline void setLinear(const float linear) noexcept;
				inline void setQuadratic(const float quadratic) noexcept;
				inline void setInnerCutOff(const float innerCutOff) noexcept;
				inline void setOuterCutOff(const float outerCutOff) noexcept;

				inline float getAmbient() const noexcept;
				inline float getDiffuse() const noexcept;
				inline float getSpecular() const noexcept;
				inline const FloatVector3u & getColor() const noexcept;
				inline const FloatVector3u & getPosition() const noexcept;
				inline const FloatVector3u & getDirection() const noexcept;
				inline float getConstant() const noexcept;
				inline float getLinear() const noexcept;
				inline float getQuadratic() const noexcept;
				inline float getInnerCutoff() const noexcept;
				inline float getOuterCutoff() const noexcept;

				inline void usePosition(const bool used) noexcept;
				inline void useDirection(const bool used) noexcept;
				inline void useAttenuation(const bool used) noexcept;
				inline void useCutOff(const bool used) noexcept;
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

				FloatVector3u _position;
				FloatVector3u _direction;

				// Use structure here
				float _constant;
				float _linear;
				float _quadratic;

				// Use structure here
				float _innerCutOff;
				float _outerCutOff;

				bool _usePosition;
				bool _useDirection;
				bool _useAttenuation;
				bool _useCutOff;
				bool _useBlinn;
			};
		} // namespace model
	} // namespace graphic
} // namespace ece

#include "graphic/model/light.inl"

#endif // LIGHT_HPP