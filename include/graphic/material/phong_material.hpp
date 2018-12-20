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
#include "graphic/material/material_visitor.hpp"
#include "graphic/material/computed_property.hpp"
#include "graphic/material/property.hpp"
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
			class ECE_GRAPHIC_API PhongMaterial: public Material::Visitor
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

				inline virtual void setMaterial(const std::weak_ptr<Material> & material) override;
				inline virtual auto getMaterial() -> std::weak_ptr<Material> override;

				virtual auto isValid() -> bool override;
				virtual void initialize() override;
				virtual void clear() override;

				inline void setAmbient(const FloatVector3u & ambient);
				inline void setDiffuse(const FloatVector3u & diffuse);
				inline void setSpecular(const FloatVector3u & specular);
				inline void setShininess(const float shininess);
				inline void setDiffuseMap(const Texture2D::Reference & texture);
				inline void setSpecularMap(const Texture2D::Reference & texture);

				inline const auto & getAmbient() const;
				inline const auto & getDiffuse() const;
				inline const auto & getSpecular() const;
				inline auto getShininess() const;
				inline auto getDiffuseMap() const;
				inline auto getSpecularMap() const;

			private:
				std::weak_ptr<Material> _material;

				using DiffuseMap = Property<Texture2D::Reference, int>;
				using SpecularMap = Property<Texture2D::Reference, int>;
				using DiffuseMapEnabled = ComputedProperty<bool>;
				using SpecularMapEnabled = ComputedProperty<bool>;
				using Ambient = Property<FloatVector3u, std::array<float, 3>>;
				using Diffuse = Property<FloatVector3u, std::array<float, 3>>;
				using Specular = Property<FloatVector3u, std::array<float, 3>>;
				using Shininess = Property<float, float>;
			};
		} // namespace material
	} // namespace graphic
} // namespace ece

#include "graphic/material/phong_material.inl"

#endif // PHONG_MATERIAL_HPP