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

#ifndef PHONG_MATERIAL_HPP
#define PHONG_MATERIAL_HPP

#include "graphic/config.hpp"
#include "graphic/material/material.hpp"
#include "utility/mathematics.hpp"
#include "renderer/image/texture2d.hpp"

namespace ece
{
	namespace graphic
	{
		namespace material
		{
			using renderer::image::Texture2D;

			/**
			 * @class PhongMaterial
			 * @brief
			 */
			class ECE_GRAPHIC_API PhongMaterial: public Material
			{
			public:
				using Reference = ResourceHandler<PhongMaterial>;

				/**
				 * @fn constexpr PhongMaterial()
				 * @brief Default constructor.
				 * @throw
				 */
				PhongMaterial() = default;

				/**
				 * @fn PhongMaterial(const PhongMaterial & copy) noexcept
				 * @param[in] copy The PhongMaterial to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				PhongMaterial(const PhongMaterial & copy) noexcept = default;

				/**
				 * @fn PhongMaterial(PhongMaterial && move) noexcept
				 * @param[in] move The PhongMaterial to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				PhongMaterial(PhongMaterial && move) noexcept = default;

				/**
				 * @fn ~PhongMaterial() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~PhongMaterial() noexcept = default;

				/**
				 * @fn PhongMaterial & operator=(const PhongMaterial & copy) noexcept
				 * @param[in] copy The PhongMaterial to copy from.
				 * @return The PhongMaterial copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				PhongMaterial & operator=(const PhongMaterial & copy) noexcept = default;

				/**
				 * @fn PhongMaterial & operator=(PhongMaterial && move) noexcept
				 * @param[in] move The PhongMaterial to move.
				 * @return The PhongMaterial moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				PhongMaterial & operator=(PhongMaterial && move) noexcept = default;

				virtual void apply(Shader & shader) override;

				inline void setAmbient(const FloatVector3u & ambient);
				inline void setDiffuse(const FloatVector3u & diffuse);
				inline void setSpecular(const FloatVector3u & specular);
				inline void setShininess(const float shininess);
				inline void setDiffuseMap(const Texture2D::Texture2DReference & texture);
				inline void setSpecularMap(const Texture2D::Texture2DReference & texture);

				inline const FloatVector3u & getAmbient() const;
				inline const FloatVector3u & getDiffuse() const;
				inline const FloatVector3u & getSpecular() const;
				inline float getShininess() const;
				inline Texture2D::Texture2DReference getDiffuseMap() const;
				inline Texture2D::Texture2DReference getSpecularMap() const;

			private:
				FloatVector3u _ambient;
				FloatVector3u _diffuse;
				FloatVector3u _specular;
				float _shininess;

				Texture2D::Texture2DReference _diffuseMap;
				Texture2D::Texture2DReference _specularMap;
			};
		} // namespace material
	} // namespace graphic
} // namespace ece

#include "graphic/material/phong_material.inl"

#endif // PHONG_MATERIAL_HPP