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
#include "renderer/shader/shader.hpp"

#include "utility/log.hpp"
#include "renderer/shader/uniform.hpp"
#include "renderer/shader/shader_stage.hpp"

namespace ece
{
	namespace renderer
	{
		namespace shader
		{
			Shader::~Shader()
			{
				this->terminate();
			}

			void Shader::setStage(ShaderStage & stage)
			{
				if (stage.isCompilationRequired()) {
					stage.compile();
				}
				OpenGL::attachShader(this->_handle, stage.getHandle());
				stage.terminate();

				this->_linkedSuccessfully = false;
			}

			void Shader::link()
			{
				OpenGL::linkProgram(this->_handle);

				if (OpenGL::getProgram(this->_handle, ProgramParameter::LINK_STATUS)[0]) {
					this->use();
					this->_linkedSuccessfully = true;

					auto stages = OpenGL::getAttachedShaders(this->_handle);
					for (auto & it : stages) {
						OpenGL::detachShader(this->_handle, it);
					}
				} else {
                    auto infoLog = OpenGL::getProgramInfoLog(this->_handle);
					ERROR << infoLog << flush;
                }
			}

            void Shader::bind(BaseUniform & uniform, const std::string & location)
            {
				if (this->isLinked()) {
					auto handle = NULL_HANDLE;
					try {
						handle = this->_cachedLocations.at(location);
					}
					catch (const std::out_of_range & /*e*/) {
						handle = OpenGL::getUniformLocation(this->_handle, location);
						this->_cachedLocations[location] = handle;
					}
					catch (const std::runtime_error & e) {
						WARNING << e.what() << flush;
					}
					uniform.bind(handle);
				}
            }

			void Shader::bind(const std::shared_ptr<BaseUniform> & uniform, const std::string & location)
			{
				if (this->isLinked()) {
					auto handle = NULL_HANDLE;
					try {
						handle = this->_cachedLocations.at(location);
					}
					catch (const std::out_of_range & /*e*/) {
						handle = OpenGL::getUniformLocation(this->_handle, location);
						this->_cachedLocations[location] = handle;
					}
					catch (const std::runtime_error & e) {
						WARNING << e.what() << flush;
					}
					uniform->bind(handle);
				}
			}

			void Shader::terminate()
			{
				OpenGL::deleteShader(this->_handle);
				this->_handle = 0;
			}

			auto Shader::getUniforms() const
			{
				auto uniforms = std::vector<BaseUniform::Info>{};
				auto count = OpenGL::getProgram(this->_handle, ProgramParameter::ACTIVE_UNIFORMS)[0];
				for (auto i =  0; i < count; ++i) {
					auto uniform = OpenGL::getActiveUniform(this->_handle, static_cast<Handle>(i));
					uniforms.push_back(getUniformInfo(uniform));
				}
				return std::move(uniforms);
			}
		} // namespace shader
	} // namespace renderer
} // namespace ece
