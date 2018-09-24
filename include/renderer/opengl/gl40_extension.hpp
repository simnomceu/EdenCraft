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


#ifndef GL40_EXTENSION_HPP
#define GL40_EXTENSION_HPP

#include "renderer/config.hpp"

#include <GL/glcorearb.h>

#include "utility/indexing.hpp"
#include "renderer/opengl/extension_loader.hpp"
#include "renderer/opengl/opengl_exception.hpp"

namespace ece
{
	using renderer::opengl::OpenGLExtensionException;
}

ECE_RENDERER_API inline void glGetUniformdv(GLuint program, GLint location, GLdouble *params);
ECE_RENDERER_API inline void glBlendEquationi(GLuint buf, GLenum mode);
ECE_RENDERER_API inline void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
ECE_RENDERER_API inline void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
ECE_RENDERER_API inline void glBlendFunci(GLuint buf, GLenum sfactor, GLenum dfactor);
ECE_RENDERER_API inline void glDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid *indirect);
ECE_RENDERER_API inline void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id);
ECE_RENDERER_API inline void glEndQueryIndexed(GLenum target, GLuint index);
ECE_RENDERER_API inline void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint * params);
ECE_RENDERER_API inline GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name);
ECE_RENDERER_API inline GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name);
ECE_RENDERER_API inline void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
ECE_RENDERER_API inline void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
ECE_RENDERER_API inline void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
ECE_RENDERER_API inline void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices);
ECE_RENDERER_API inline void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *values);
ECE_RENDERER_API inline void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
ECE_RENDERER_API inline void glPatchParameteri(GLenum pname, GLint value);
ECE_RENDERER_API inline  void glPatchParameterfv(GLenum pname, const GLfloat *values);
ECE_RENDERER_API inline  void glDrawArraysIndirect(GLenum mode, const void *indirect);
ECE_RENDERER_API inline  void glGenTransformFeedbacks(GLsizei n, GLuint *ids);
ECE_RENDERER_API inline  void glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids);
ECE_RENDERER_API inline  GLboolean glIsTransformFeedback(GLuint id);
ECE_RENDERER_API inline  void glBindTransformFeedback(GLenum target, GLuint id);
ECE_RENDERER_API inline  void glPauseTransformFeedback();
ECE_RENDERER_API inline  void glResumeTransformFeedback();
ECE_RENDERER_API inline  void glDrawTransformFeedback(GLenum mode, GLuint id);
ECE_RENDERER_API inline  void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
ECE_RENDERER_API inline  void glMinSampleShading(GLfloat value);

/**
 * fn CALLGL40(SIGNATURE, NAME)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 4.0 extension and call it.
 */
#define CALLGL40(SIGNATURE, NAME) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 0 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	proxy();

/**
 * fn R_CALLGL40(SIGNATURE, NAME)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 4.0 extension and call it.
 */
#define R_CALLGL40(SIGNATURE, NAME) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 0 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy();

/**
 * fn CALLGL40_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 4.0 extension and call it.
 */
#define CALLGL40_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 0 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	proxy(__VA_ARGS__);

/**
 * fn R_CALLGL40_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 4.0 extension and call it.
 */
#define R_CALLGL40_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 0 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy(__VA_ARGS__);

#include "renderer/opengl/gl40_extension.inl"

#endif // GL40_EXTENSION_HPP
