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
#include "renderer/debug/debugging.hpp"

#include "utility/log.hpp"
#include "renderer/opengl.hpp"

namespace ece
{
	namespace renderer
	{
		namespace debug
		{
			void checkErrors_(const char * file, const int line, const char * function)
			{
				auto error(OpenGL::getError());
				while (error != ErrorGL::NO_ERROR) {
					auto errorMessage = std::string{};

					switch (error) {
					case ErrorGL::INVALID_ENUM:	errorMessage = "INVALID_ENUM"; break;
					case ErrorGL::INVALID_VALUE: errorMessage = "INVALID_VALUE"; break;
					case ErrorGL::INVALID_OPERATION: errorMessage = "INVALID_OPERATION"; break;
					case ErrorGL::INVALID_FRAMEBUFFER_OPERATION: errorMessage = "INVALID_FRAMEBUFFER_OPERATION"; break;
					case ErrorGL::OUT_OF_MEMORY: errorMessage = "OUT_OF_MEMORY"; break;
					case ErrorGL::STACK_UNDERFLOW: errorMessage = "STACK_UNDERFLOW"; break;
					case ErrorGL::STACK_OVERFLOW: errorMessage = "STACK_OVERFLOW"; break;
					default: break;
					}

					ERROR << "Error OpenGL: (" << static_cast<unsigned short int>(error) << ") " << errorMessage << " in " << function << " from " << file << ":" << line << "." << flush;
					error = OpenGL::getError();
				}
			}

			void APIENTRY glDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei /*length*/, const GLchar *message, const void * /*userParam*/)
			{
				auto debugMessage = std::string{ " Debug OpenGL: (" + std::to_string(id) + "): " + message };

				switch (source)
				{
				case GL_DEBUG_SOURCE_API:             debugMessage += "[Source: API]"; break;
				case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   debugMessage += "[Source: Window System]"; break;
				case GL_DEBUG_SOURCE_SHADER_COMPILER: debugMessage += "[Source: Shader Compiler]"; break;
				case GL_DEBUG_SOURCE_THIRD_PARTY:     debugMessage += "[Source: Third Party]"; break;
				case GL_DEBUG_SOURCE_APPLICATION:     debugMessage += "[Source: Application]"; break;
				case GL_DEBUG_SOURCE_OTHER:           debugMessage += "[Source: Other]"; break;
				}

				switch (type)
				{
				case GL_DEBUG_TYPE_ERROR:               debugMessage += "[Type: Error]"; break;
				case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: debugMessage += "[Type: Deprecated Behaviour]"; break;
				case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  debugMessage += "[Type: Undefined Behaviour]"; break;
				case GL_DEBUG_TYPE_PORTABILITY:         debugMessage += "[Type: Portability]"; break;
				case GL_DEBUG_TYPE_PERFORMANCE:         debugMessage += "[Type: Performance]"; break;
				case GL_DEBUG_TYPE_MARKER:              debugMessage += "[Type: Marker]"; break;
				case GL_DEBUG_TYPE_PUSH_GROUP:          debugMessage += "[Type: Push Group]"; break;
				case GL_DEBUG_TYPE_POP_GROUP:           debugMessage += "[Type: Pop Group]"; break;
				case GL_DEBUG_TYPE_OTHER:               debugMessage += "[Type: Other]"; break;
				}

				switch (severity)
				{
				case GL_DEBUG_SEVERITY_HIGH:         debugMessage += "[Severity: high]"; break;
				case GL_DEBUG_SEVERITY_MEDIUM:       debugMessage += "[Severity: medium]"; break;
				case GL_DEBUG_SEVERITY_LOW:          debugMessage += "[Severity: low]"; break;
				case GL_DEBUG_SEVERITY_NOTIFICATION: debugMessage += "[Severity: notification]"; break;
				}
				if (severity == GL_DEBUG_SEVERITY_NOTIFICATION) {
					WARNING << debugMessage << flush;
				}
				else {
					ERROR << debugMessage << flush;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece
