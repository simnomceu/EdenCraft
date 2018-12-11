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
#include "renderer/opengl/extension_loader.hpp"

#include "renderer/x11/glx_extension.hpp"
#include "utility/log.hpp"
#include "renderer/opengl/context_opengl.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			void * loadOpenGLProc(const std::string & name, const Version<2> & requiredVersion)
			{
				auto addr = name.data();
				auto proc = glXGetProcAddress(reinterpret_cast<const GLubyte *>(addr));
				if (proc == nullptr) {
					if (requiredVersion > ece::Version<2>{ 3, 2} && ContextOpenGL::getMaxVersionAvailable() < requiredVersion) {
						ServiceLoggerLocator::getService().logError(name + " is not available. You need at least a " + std::to_string(requiredVersion[0]) + "." + std::to_string(requiredVersion[1]) + " context.");
					}
					else {
						ServiceLoggerLocator::getService().logError(name + " cannot be loaded.");
					}
				}
				return reinterpret_cast<void *>(proc);
			}

			Version<2> initLoader(const Version<2> & minVersionGL, const Version<2> & maxVersionGL)
			{
				Version<2> latestVersionAvailable;
				auto version = glGetString(GL_VERSION);
				if (version) {
					std::string versionPtr(reinterpret_cast<const char *>(version));
					latestVersionAvailable[0] = static_cast<unsigned short int>(std::stoi(versionPtr.substr(0, 1)));
					latestVersionAvailable[1] = static_cast<unsigned short int>(std::stoi(versionPtr.substr(2, 1)));
				}
				return max(min(maxVersionGL, latestVersionAvailable), minVersionGL);
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece
