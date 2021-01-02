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

#include "renderer/pch.hpp"
#include "renderer/shader/shader_stage.hpp"

#include "utility/file_system.hpp"
#include "utility/debug.hpp"
#include "utility/log.hpp"
#include "renderer/opengl.hpp"

namespace ece
{
	namespace renderer
	{
		namespace shader
		{
			ShaderStage & ShaderStage::operator=(const ShaderStage & copy) noexcept
			{
				if (this != &copy) {
					this->_filename = copy._filename;
					this->_source = copy._filename;
					this->_type = copy._type;
					this->_handle = copy._handle;
					this->_compilationRequired = copy._compilationRequired;
				}
				return *this;
			}

			ShaderStage & ShaderStage::operator=(ShaderStage && move) noexcept
			{
				if (this != &move) {
					this->_filename = std::move(move._filename);
					this->_source = std::move(move._filename);
					this->_type = move._type;
					this->_handle = move._handle;
					this->_compilationRequired = move._compilationRequired;

					move._filename.clear();
					move._handle = NULL_HANDLE;
					move._compilationRequired = false;
				}
				return *this;
			}

			void ShaderStage::loadFromFile(const Type type, const std::string & filename)
			{
				this->terminate();

				if (this->_filename != filename) {
					this->_filename = filename;

					this->_source.clear();
					auto shaderFile = File();
					try {
						shaderFile.open(this->_filename);
						this->_source = shaderFile.parseToString();
						shaderFile.close();
					}
					catch (const FileException & e) {
						ERROR << e.what() << flush;
					}
					this->_type = type;
					this->_compilationRequired = true;
				}
			}

			void ShaderStage::loadFromString(const Type type, const std::string & sourceCode)
			{
				this->terminate();

				this->_filename = "";
				this->_source = sourceCode;
				this->_type = type;
				this->_compilationRequired = true;
			}

			void ShaderStage::compile()
			{
				this->_handle = OpenGL::createShader(getShaderType(this->_type));
				OpenGL::shaderSource(this->_handle, this->_source);
				OpenGL::compileShader(this->_handle);

				if (OpenGL::getShader(this->_handle, ShaderParameter::COMPILE_STATUS)) {
    				this->_compilationRequired = false;
				} else {
                    auto infoLog = OpenGL::getShaderInfoLog(this->_handle);
					ERROR << infoLog << flush;
                }
			}

			void ShaderStage::terminate()
			{
				if (this->_handle != NULL_HANDLE) {
					OpenGL::deleteShader(this->_handle);
					this->_handle = NULL_HANDLE;
					this->_compilationRequired = true;
				}
			}
		} // namespace shader
	} // namespace renderer
} // namespace ece
