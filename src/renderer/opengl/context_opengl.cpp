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


#include "renderer/opengl/context_opengl.hpp"

#include "utility/log.hpp"
#include "renderer/rendering/renderer.hpp"

#ifdef _MSC_VER
#	undef min
#	undef max
#endif

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			using rendering::Renderer;

			Version<2> ContextOpenGL::_maxVersionAvailable{ 3, 2 };

			std::shared_ptr<RenderContext> ContextOpenGL::DummyContext()
			{
				ContextSettings settings;
				settings.oldContext = true;

				auto dummy = std::make_shared<ContextOpenGL>();
				dummy->create(settings);
				return dummy;
			}

			Version<2> ContextOpenGL::getCurrentVersion() const
			{
				return this->_currentVersion;
			}

			void ContextOpenGL::logInfos() const
			{
				ServiceLoggerLocator::getService().logInfo("Renderer: " + OpenGL::getString(InfoGL::RENDERER));
				ServiceLoggerLocator::getService().logInfo("OpenGL version supported " + OpenGL::getString(InfoGL::VERSION));
				ServiceLoggerLocator::getService().logInfo("GLSL version supported " + OpenGL::getString(InfoGL::SHADING_LANGUAGE_VERSION));
			}

			void ContextOpenGL::setDebugContext()
			{
			#ifdef ECE_DEBUG
				int flags = OpenGL::getInteger(Parameter::CONTEXT_FLAGS)[0];
				if (flags && static_cast<unsigned short int>(ContextFlag::CONTEXT_FLAG_DEBUG_BIT))
				{
					OpenGL::enable(Capability::DEBUG_OUTPUT);
					OpenGL::enable(Capability::DEBUG_OUTPUT_SYNCHRONOUS);
					OpenGL::debugMessageCallback(glDebugOutput, nullptr);
					OpenGL::debugMessageControl(SourceDebugMessage::DONT_CARE, TypeDebugMessage::DONT_CARE, SeverityDebugMessage::DONT_CARE, {}, true);
				}
			#endif
			}

			void ContextOpenGL::create(const ContextSettings & settings)
			{
				if (settings.oldContext) {
					this->createOldContext();
				}
				else {
					if (!Renderer::isInitialized()) {
						auto dummy = ContextOpenGL::DummyContext();
						ContextOpenGL::_maxVersionAvailable = max(initLoader(settings.minVersion, settings.maxVersion), ContextOpenGL::_maxVersionAvailable);
					}

					this->createModernContext(settings);
				}
				this->_created = true;
				this->setCurrent();

				auto version = OpenGL::getString(InfoGL::VERSION);
				if (!version.empty()) {
					this->_currentVersion[0] = static_cast<unsigned short int>(std::stoi(version.substr(0, 1)));
					this->_currentVersion[1] = static_cast<unsigned short int>(std::stoi(version.substr(2, 1)));
				}

				if (!settings.oldContext) {
					this->logInfos();

					this->setDebugContext();
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece
