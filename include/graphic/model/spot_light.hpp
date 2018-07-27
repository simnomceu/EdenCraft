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

#ifndef SPOT_LIGHT_HPP
#define SPOT_LIGHT_HPP

#include "graphic/config.hpp"
#include "graphic/model/light.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			/**
			 * @class SpotLight
			 * @brief
			 */
			class ECE_GRAPHIC_API SpotLight: public Light
			{
			public:
				/**
				 * @fn constexpr SpotLight() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				SpotLight() noexcept = default;

				/**
				 * @fn SpotLight(const SpotLight & copy) noexcept
				 * @param[in] copy The SpotLight to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				SpotLight(const SpotLight & copy) noexcept = default;

				/**
				 * @fn SpotLight(SpotLight && move) noexcept
				 * @param[in] move The SpotLight to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				SpotLight(SpotLight && move) noexcept = default;

				/**
				 * @fn ~SpotLight() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~SpotLight() noexcept = default;

				/**
				 * @fn SpotLight & operator=(const SpotLight & copy) noexcept
				 * @param[in] copy The SpotLight to copy from.
				 * @return The SpotLight copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				SpotLight & operator=(const SpotLight & copy) noexcept = default;

				/**
				 * @fn SpotLight & operator=(SpotLight && move) noexcept
				 * @param[in] move The SpotLight to move.
				 * @return The SpotLight moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				SpotLight & operator=(SpotLight && move) noexcept = default;

				inline void setInnerCutoff(const float innerCutoff) noexcept;
				inline void setOuterCutoff(const float outerCutoff) noexcept;
				inline void setPosition(const FloatVector3u & position) noexcept;
				inline void setDirection(const FloatVector3u & direction) noexcept;
				inline void setConstant(const float constant) noexcept;
				inline void setLinear(const float linear) noexcept;
				inline void setQuadratic(const float quadratic) noexcept;

				inline float getInnerCutoff() const noexcept;
				inline float getOuterCutoff() const noexcept;
				inline const FloatVector3u & getPosition() const noexcept;
				inline const FloatVector3u & getDirection() const noexcept;
				inline float getConstant() const noexcept;
				inline float getLinear() const noexcept;
				inline float getQuadratic() const noexcept;

				virtual void apply(Shader & shader) override;

			private:
				float _innerCutoff;
				float _outerCutoff;

				FloatVector3u _position;
				FloatVector3u _direction;

				float _constant;
				float _linear;
				float _quadratic;
			};
		} // namespace model
	} // namespace graphic
} // namespace ece

#include "graphic/model/spot_light.inl"

#endif // SPOT_LIGHT_HPP