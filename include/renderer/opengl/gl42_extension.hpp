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

#ifndef GL42_EXTENSION_HPP
#define GL42_EXTENSION_HPP

#include <GL/glcorearb.h>

#include "utility/indexing/version.hpp"
#include "renderer/opengl/extension_loader.hpp"
#include "renderer/opengl/opengl_exception.hpp"

namespace ece
{
    using namespace utility::indexing;
}

inline void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
inline void glMemoryBarrier(GLbitfield barriers);
inline void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
inline void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
inline void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
inline void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
inline void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance);
inline void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices, GLsizei primcount, GLuint baseinstance);
inline void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, GLvoid *indices, GLsizei primcount, GLint basevertex, GLuint baseinstance);
inline void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei primcount);
inline void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei primcount);
inline void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);

/**
 * fn CALLGL42(SIGNATURE, NAME)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 4.2 extension and call it.
 */
#define CALLGL42(SIGNATURE, NAME) \
	static auto proxy = ece::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 2 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	proxy();

/**
 * fn R_CALLGL42(SIGNATURE, NAME)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 4.2 extension and call it.
 */
#define R_CALLGL42(SIGNATURE, NAME) \
	static auto proxy = ece::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 2 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy();

/**
 * fn CALLGL42_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 4.2 extension and call it.
 */
#define CALLGL42_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 2 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	proxy(__VA_ARGS__);

/**
 * fn R_CALLGL42_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 4.2 extension and call it.
 */
#define R_CALLGL42_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 2 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy(__VA_ARGS__);

#include "renderer/opengl/gl42_extension.inl"

#endif // GL42_EXTENSION_HPP
