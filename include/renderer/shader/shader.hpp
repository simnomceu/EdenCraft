/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
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

#ifndef SHADER_HPP
#define SHADER_HPP

#include "renderer/config.hpp"
#include "renderer/pch.hpp"
#include "utility/types.hpp"
#include "renderer/shader/base_uniform.hpp"

namespace ece
{
	namespace renderer
	{
		namespace shader
		{
			class ShaderStage;

			/**
			 * @class Shader
			 * @brief A shader program, as a combination of shader stages.
			 */
			class ECE_RENDERER_API Shader
			{
			public:
				/**
				 * @fn Shader()
				 * @brief Default constructor.
				 * @throw
				 */
				inline Shader();

				/**
				 * @fn Shader(const Handle handle) noexcept
				 * @param[in] handle The id to use.
				 * @brief Build a shader program with a specific id.
				 * @throw noexcept
				 */
				inline Shader(const Handle handle) noexcept;

				/**
				 * @fn Shader(const Shader & copy)
				 * @param[in] copy The shader program to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Shader(const Shader & copy) = default;

				/**
				 * @fn Shader(Shader && move) noexcept
				 * @param[in] move The shader program to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Shader(Shader && move) noexcept = default;

				/**
				 * @fn ~Shader() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Shader() noexcept;

				/**
				 * @fn Shader & operator=(const Shader & copy)
				 * @param[in] copy The shader program to copy from.
				 * @return The shader program copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Shader & operator=(const Shader & copy) = default;

				/**
				 * @fn Shader & operator=(Shader && move) noexcept
				 * @param[in] move The shader program to move.
				 * @return The shader program moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Shader & operator=(Shader && move) noexcept = default;

				/**
				 * @fn Handle getHandle() const
				 * @return The id of the shader program.
				 * @brief Get the id of the shader program.
				 * @throw
				 */
				inline auto getHandle() const;

				/**
				 * @fn void setStage(ShaderStage & stage)
				 * @param[in] stage The shader stage to add.
				 * @brief Set a shader stage of the program.
				 * @throw
				 */
				virtual void setStage(ShaderStage & stage);

				/**
				 * @fn void link()
				 * @brief Link the shader program.
				 * @throw
				 */
				void link();

				/**
				 * @fn bool isLinked() const
				 * @return True, if the program has been linked successfully, false else.
				 * @brief check if the program has been linked successfully or not.
				 * @throw noexcept
				 */
				inline auto isLinked() const noexcept;

				/**
				 * @fn void use() const
				 * @brief Put the shader program in a buffer to be used.
				 * @throw
				 */
				inline void use() const;

                inline auto getLocation(const std::string & location);

                void bind(BaseUniform & uniform, const std::string & location);
				void bind(const std::shared_ptr<BaseUniform> & uniform, const std::string & location);

				/**
				 * @fn void terminate()
				 * @brief Delete the shader program.
				 * @throw
				 */
				void terminate();

				auto getUniforms() const;

			protected:
				/**
				 * @property _handle
				 * @brief The id of the shader program.
				 */
				Handle _handle;

				bool _linkedSuccessfully;

				std::unordered_map<std::string, Handle> _cachedLocations;
			};
		} // namespace shader
	} // namespace renderer
} // namespace ece

#include "renderer/shader/shader.inl"

#endif // SHADER_HPP
