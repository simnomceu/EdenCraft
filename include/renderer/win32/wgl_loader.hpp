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


#ifndef WGL_LOADER_HPP
#define WGL_LOADER_HPP

#include "GL/glcorearb.h"
#include "GL/glext.h"
#include "GL/wglext.h"

#include <array>

#include "utility/indexing/version.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			using utility::indexing::Version;

			/**
			 * @class WGLoader
			 * @brief OpenGL loader for Windows platform.
			 */
			class WGLLoader
			{
			public:
				/**
				 * @fn WGLLoader & getInstance()
				 * @return The singleton.
				 * @brief Get the unique instance of the loader.
				 * @throw
				 */
				static WGLLoader & getInstance();

				/**
				 * @fn ~WGLLoader() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~WGLLoader() noexcept;

				/**
				 * @fn FARPROC getProcAddress(const std::string & name)
				 * @param[in] name The name of the extension.
				 * @return The OpenGL method loaded.
				 * @brief Load an OpenGL extension from a Wndows platform.
				 * @throw
				 */
				FARPROC getProcAddress(const std::string & name);

				void loadLibrary();

				/**
				 * @fn Version<2> & getLatestVersionAvailable()
				 * @return The latest version available of OpenGL.
				 * @brief Get the latest version available of OpenGL.
				 * @throw
				 */
				Version<2> & getLatestVersionAvailable();

			private:
				/**
				 * @fn WGLLoader()
				 * @brief Default constructor.
				 * @throw
				 */
				WGLLoader();

				/**
				 * @property _openglLib
				 * @brief THe external library exposing OpenGL.
				 */
				HMODULE _openglLib;

				/**
				 * @property _latestVersionAvailable
				 * @brief The latest version available of OpenGL.
				 */
				Version<2> _latestVersionAvailable;
			};
		} // namespace opengl
	} // namespace renderer
} // namespace ece

#endif // WGL_LOADER_HPP
