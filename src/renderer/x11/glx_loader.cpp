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


#include "renderer/x11/glx_loader.hpp"

#include "renderer/x11/glx_extension.hpp"
#include "renderer/opengl/opengl_extension.hpp"

namespace ece
{
	GLXLoader & GLXLoader::getInstance()
	{
		static GLXLoader instance;
		return instance;
	}

	GLXLoader::~GLXLoader() noexcept
	{
	}

	GLXLoader::GLXLoader(): _latestVersionAvailable{ 0, 0 }, _dummy{ nullptr, 0, 0 }
	{
	}

	void GLXLoader::initDummyContext()
	{
		this->_dummy.display = XOpenDisplay(0);
		this->_dummy.window = XCreateSimpleWindow(this->_dummy.display, DefaultRootWindow(this->_dummy.display), 0, 0, 0, 0, 0, 0, 0);
		if (this->_dummy.window) {
			static int visual_attribs[] = {
		        GLX_RENDER_TYPE, GLX_RGBA_BIT,
		        GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
		        GLX_DOUBLEBUFFER, true,
		        GLX_RED_SIZE, 1,
		        GLX_GREEN_SIZE, 1,
		        GLX_BLUE_SIZE, 1,
		        None
		    };

			int nbFBConfig = 0;
    		GLXFBConfig * FBConfig = glXChooseFBConfig(this->_dummy.display, DefaultScreen(this->_dummy.display), visual_attribs, &nbFBConfig);
			if (!FBConfig) {
				throw std::runtime_error("No frame buffer configuration choosen for OpenGL dummy context.");
			}
			XVisualInfo * visualInfo = glXGetVisualFromFBConfig(this->_dummy.display, FBConfig[0]);
			this->_dummy.context = glXCreateContext(this->_dummy.display, visualInfo, 0, GL_TRUE);
		}

		glXCreateContextAttribs(nullptr, 0, 0, false, nullptr); //dummy call
	}

	Version<2> & GLXLoader::getLatestVersionAvailable()
	{
		if (this->_latestVersionAvailable == Version<2>{ 0, 0 }) {
			std::string versionPtr(reinterpret_cast<const char *>(glGetString(GL_VERSION)));
			this->_latestVersionAvailable[0] = static_cast<unsigned short int>(std::stoi(versionPtr.substr(0, 1)));
			this->_latestVersionAvailable[1] = static_cast<unsigned short int>(std::stoi(versionPtr.substr(2, 1)));
		}
		return this->_latestVersionAvailable;
	}

	void GLXLoader::terminateDummyContext()
	{
		if (this->_dummy.context) {
			glXMakeCurrent(this->_dummy.display, 0, 0);
			glXDestroyContext(this->_dummy.display, this->_dummy.context);

			this->_dummy.display = nullptr;
			XDestroyWindow(this->_dummy.display, this->_dummy.window);
		}
	}
}
