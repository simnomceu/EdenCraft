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


#include "renderer/win32/wgl_loader.hpp"

#include "renderer/win32/wgl_extension.hpp"
#include "renderer/opengl/opengl_extension.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			WGLLoader & WGLLoader::getInstance()
			{
				static WGLLoader instance;
				return instance;
			}

			WGLLoader::~WGLLoader() noexcept
			{
				if (this->_openglLib != nullptr) {
					FreeLibrary(this->_openglLib);
					this->_openglLib = nullptr;
				}
			}

			FARPROC WGLLoader::getProcAddress(const std::string & name)
			{
				return GetProcAddress(this->_openglLib, name.data());
			}

			WGLLoader::WGLLoader() : _openglLib(nullptr), _latestVersionAvailable{ 0, 0 }, _dummy{ nullptr, nullptr, nullptr }
			{
			}

			void WGLLoader::initDummyContext()
			{
				this->_dummy.device = GetDC(GetDesktopWindow());
				if (!this->_dummy.device) {
					throw std::runtime_error("OpenGL cannot be initialized beacause no device is currently available.");
				}

				PIXELFORMATDESCRIPTOR pixelFormat;
				ZeroMemory(&pixelFormat, sizeof(pixelFormat));
				pixelFormat.nSize = sizeof(pixelFormat);
				pixelFormat.nVersion = 1;
				pixelFormat.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
				pixelFormat.iPixelType = PFD_TYPE_RGBA;
				pixelFormat.cColorBits = 32;
				pixelFormat.cAlphaBits = 8;
				pixelFormat.cDepthBits = 24;

				if (!ChoosePixelFormat(this->_dummy.device, &pixelFormat)) {
					throw std::runtime_error("No pixel format choosen for OpenGL dummy context.");
				}

				if (!SetPixelFormat(this->_dummy.device, 1, &pixelFormat)) {
					throw std::runtime_error("OpenGL cannot be initialized because no video mode fit with.");
				}

				this->_dummy.context = wglCreateContext(this->_dummy.device);
				if (!this->_dummy.context) {
					throw std::runtime_error("OpenGL cannot be initialized because it is not possible to create a context.");
				}
				if (!wglMakeCurrent(this->_dummy.device, this->_dummy.context)) {
					throw std::runtime_error("OpenGL cannot be initialized because it is not possible to use a context.");
				}

				if (this->_openglLib == nullptr) {
					this->_openglLib = LoadLibrary(L"opengl32.dll");
				}

				wglChoosePixelFormat(nullptr, nullptr, nullptr, 0, nullptr, nullptr); // dummy call
				wglCreateContextAttribs(nullptr, nullptr, nullptr); // dummy call
			}

			Version<2> & WGLLoader::getLatestVersionAvailable()
			{
				if (this->_latestVersionAvailable == Version<2>{ 0, 0 }) {
					auto version = glGetString(GL_VERSION);
					if (version) {
						std::string versionPtr(reinterpret_cast<const char *>(version));
						this->_latestVersionAvailable[0] = static_cast<unsigned short int>(std::stoi(versionPtr.substr(0, 1)));
						this->_latestVersionAvailable[1] = static_cast<unsigned short int>(std::stoi(versionPtr.substr(2, 1)));
					}
				}
				return this->_latestVersionAvailable;
			}

			void WGLLoader::terminateDummyContext()
			{
				if (this->_dummy.context != nullptr) {
					wglMakeCurrent(nullptr, nullptr);
					wglDeleteContext(this->_dummy.context);
					this->_dummy.context = nullptr;
					ReleaseDC(this->_dummy.window, this->_dummy.device);
					this->_dummy.device = nullptr;
				//	DestroyWindow(this->_dummy.window);
				//	this->_dummy.window = nullptr;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece
