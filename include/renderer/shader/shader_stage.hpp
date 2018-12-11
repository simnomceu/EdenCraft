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


#ifndef SHADER_STAGE_HPP
#define SHADER_STAGE_HPP

#include "renderer/config.hpp"
#include "renderer/pch.hpp"
#include "utility/types.hpp"

namespace ece
{
	namespace renderer
	{
		namespace shader
		{
			/**
			 * @class ShaderStage
			 * @brief A shader stage is a step in the render pipeline.
			 */
			class ECE_RENDERER_API ShaderStage
			{
			public:
				enum class Type : unsigned char
				{
					COMPUTE			=	0x0,
					FRAGMENT		=	0x1,
					GEOMETRY		=	0x2,
					VERTEX			=	0x3,
					TESS_EVALUATION	=	0x4,
					TESS_CONTROL	=	0x5
				};

				/**
				 * @fn ShaderStage() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline ShaderStage() noexcept;

				/**
				 * @fn ShaderStage(const ShaderStage & copy) noexcept
				 * @param[in] copy The stage to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				inline ShaderStage(const ShaderStage & copy) noexcept;

				/**
				 * @fn ShaderStage(ShaderStage && move) noexcept
				 * @param[in] move The stage to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				inline ShaderStage(ShaderStage && move) noexcept;

				/**
				 * @fn ~ShaderStage() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				inline ~ShaderStage() noexcept;

				/**
				 * @fn ShaderStage & operator=(const ShaderStage & copy) noexcept
				 * @param[in] copy The stage to copy from.
				 * @return The stage copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				ShaderStage & operator=(const ShaderStage & copy) noexcept;

				/**
				 * @fn ShaderStage & operator=(ShaderStage && move) noexcept
				 * @param[in] move The stage to move.
				 * @return The stage moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ShaderStage & operator=(ShaderStage && move) noexcept;

				/**
				 * @fn void loadFromFile(const Type type, const std::string & filename)
				 * @param[in] type The stage to define.
				 * @param[in] filename The file that contain the source of the shader stage.
				 * @brief Load the stage from a source file.
				 * @throw
				 */
				void loadFromFile(const Type type, const std::string & filename);

				/**
				 * @fn void loadFromFile(const Type type, const std::string & sourceCode)
				 * @param[in] type The stage to define.
				 * @param[in] sourceCode The source of the shader stage.
				 * @brief Load the stage from a string.
				 * @throw
				 */
				void loadFromString(const Type type, const std::string & sourceCode);

				/**
				 * @fn const std::string & getFilename() const
				 * @return The filename containing the source.
				 * @brief Get the filename containing the source.
				 * @throw
				 */
				inline const std::string & getFilename() const;

				/**
				 * @fn const std::string & getSource() const
				 * @return The source of the stage.
				 * @brief Get the source of the stage.
				 * @throw
				 */
				inline const std::string & getSource() const;

				/**
				 * @fn Type getType() const
				 * @return The type of stage.
				 * @brief Get the type of stage.
				 * @throw
				 */
				inline Type getType() const;

				/**
				 * @fn Handle getHandle() const
				 * @return The id of the stage.
				 * @brief Get the id of the shader stage.
				 * @throw
				 */
				inline Handle getHandle() const;

				/**
				 * @fn bool isCompilationRequired() const
				 * @return True, if compilation of the shader stage is required, else false.
				 * @brief Check if it is required to compile the shader stage or not.
				 * @throw
				 */
				inline bool isCompilationRequired() const;

				/**
				 * @fn void compile()
				 * @brief Compile the shader stage.
				 * @throw
				 */
				void compile();

				/**
				 * @fn void terminate()
				 * @brief Clear and delete the shader stage.
				 * @throw
				 */
				void terminate();

			private:
				/**
				 * @property _filename
				 * @brief The file that contains the source.
				 */
				std::string _filename;

				/**
				 * @property _source
				 * @brief The source of the shader stage.
				 */
				std::string _source;

				/**
				 * @property _ type
				 * @brief The type of shader stage.
				 */
				Type _type;

				/**
				 * @property _handle
				 * @brief The id of the shader stage.
				 */
				Handle _handle;

				/**
				 * @property _compilationRequired
				 * @brief Tag to indicate that the stage need to be compiled.
				 */
				bool _compilationRequired;
			};
		} // namespace shader
	} // namespace renderer
} // namespace ece

#include "renderer/shader/shader_stage.inl"

#endif // SHADER_STAGE_HPP
