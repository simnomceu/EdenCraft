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


#ifndef GL43_EXTENSION_HPP
#define GL43_EXTENSION_HPP

#include "renderer/config.hpp"

#include <GL/glcorearb.h>

#include "utility/indexing/version.hpp"
#include "renderer/opengl/extension_loader.hpp"
#include "renderer/opengl/opengl_exception.hpp"

namespace ece
{
    using utility::indexing::Version;
	using renderer::opengl::OpenGLExtensionException;
}

ECE_RENDERER_API inline void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid * data);
ECE_RENDERER_API inline void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const GLvoid * data);
ECE_RENDERER_API inline void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length);
ECE_RENDERER_API inline void glInvalidateBufferData(GLuint buffer);
ECE_RENDERER_API inline void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint * params);
ECE_RENDERER_API inline GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar * name);
ECE_RENDERER_API inline void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
ECE_RENDERER_API inline void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params);
ECE_RENDERER_API inline GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar * name);
ECE_RENDERER_API inline GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar * name);
ECE_RENDERER_API inline void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
ECE_RENDERER_API inline void glGetPointerv(GLenum pname, GLvoid ** params);
ECE_RENDERER_API inline void glTexBufferRange(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size);
ECE_RENDERER_API inline void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
ECE_RENDERER_API inline void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
ECE_RENDERER_API inline void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
ECE_RENDERER_API inline void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
ECE_RENDERER_API inline void glInvalidateTexImage(GLuint texture, GLint level);
ECE_RENDERER_API inline void glFramebufferParameteri(GLenum target, GLenum pname, GLint param);
ECE_RENDERER_API inline void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params);
ECE_RENDERER_API inline void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
ECE_RENDERER_API inline void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
ECE_RENDERER_API inline void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
ECE_RENDERER_API inline void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLintptr stride);
ECE_RENDERER_API inline void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex);
ECE_RENDERER_API inline void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor);
ECE_RENDERER_API inline void glMultiDrawArraysIndirect(GLenum mode, const GLvoid *indirect, GLsizei drawcount, GLsizei stride);
ECE_RENDERER_API inline void glMultiDrawArraysIndirectCount(GLenum mode, const GLvoid *indirect, GLintptr drawcount, GLintptr maxdrawcount, GLsizei stride);
ECE_RENDERER_API inline void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid *indirect, GLsizei drawcount, GLsizei stride);
ECE_RENDERER_API inline void glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const GLvoid *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
ECE_RENDERER_API inline void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
ECE_RENDERER_API inline void glDispatchComputeIndirect(GLintptr indirect);
ECE_RENDERER_API inline void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLint width, GLint height);
ECE_RENDERER_API inline void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments);
ECE_RENDERER_API inline void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
ECE_RENDERER_API inline void glDebugMessageCallback(GLDEBUGPROC callback, const GLvoid * userParam);
ECE_RENDERER_API inline void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
ECE_RENDERER_API inline void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message);
ECE_RENDERER_API inline void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar * message);
ECE_RENDERER_API inline void glPopDebugGroup();
ECE_RENDERER_API inline void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar * label);
ECE_RENDERER_API inline void glObjectPtrLabel(GLvoid * ptr, GLsizei length, const GLchar * label);
ECE_RENDERER_API inline GLuint glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
ECE_RENDERER_API inline void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bifSize, GLsizei * length, GLchar * label);
ECE_RENDERER_API inline void glGetObjectPtrLabel(GLvoid * ptr, GLsizei bifSize, GLsizei * length, GLchar * label);
ECE_RENDERER_API inline void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);

/**
 * fn CALLGL43(SIGNATURE, NAME)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 4.3 extension and call it.
 */
#define CALLGL43(SIGNATURE, NAME) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 3 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	proxy();

/**
 * fn R_CALLGL43(SIGNATURE, NAME)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 4.3 extension and call it.
 */
#define R_CALLGL43(SIGNATURE, NAME) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 3 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy();

/**
 * fn CALLGL43_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 4.3 extension and call it.
 */
#define CALLGL43_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 3 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	proxy(__VA_ARGS__);

/**
 * fn R_CALLGL43_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 4.3 extension and call it.
 */
#define R_CALLGL43_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 3 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy(__VA_ARGS__);

#include "renderer/opengl/gl43_extension.inl"

#endif // GL43_EXTENSION_HPP
