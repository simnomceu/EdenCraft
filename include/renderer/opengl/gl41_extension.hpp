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


#ifndef GL41_EXTENSION_HPP
#define GL41_EXTENSION_HPP

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

ECE_RENDERER_API inline void glVertexAttribL1d(GLuint index, GLdouble v0);
ECE_RENDERER_API inline void glVertexAttribL2d(GLuint index, GLdouble v0, GLdouble v1);
ECE_RENDERER_API inline void glVertexAttribL3d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2);
ECE_RENDERER_API inline void glVertexAttribL4d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
ECE_RENDERER_API inline void glVertexAttribL1dv(GLuint index, const GLdouble * v);
ECE_RENDERER_API inline void glVertexAttribL2dv(GLuint index, const GLdouble * v);
ECE_RENDERER_API inline void glVertexAttribL3dv(GLuint index, const GLdouble * v);
ECE_RENDERER_API inline void glVertexAttribL4dv(GLuint index, const GLdouble * v);
ECE_RENDERER_API inline void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
ECE_RENDERER_API inline void glDepthRangef(GLfloat nearVal, GLfloat farVal);
ECE_RENDERER_API inline void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params);
ECE_RENDERER_API inline void glClearDepthf(GLfloat depth);
ECE_RENDERER_API inline void glGetFloati_v(GLenum target, GLuint index, GLfloat * data);
ECE_RENDERER_API inline void glGetDoublei_v(GLenum target, GLuint index, GLdouble * data);
ECE_RENDERER_API inline void glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const GLvoid *binary, GLsizei length);
ECE_RENDERER_API inline void glReleaseShaderCompiler();
ECE_RENDERER_API inline GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar **strings);
ECE_RENDERER_API inline void glProgramParameteri(GLuint program, GLenum pname, GLint value);
ECE_RENDERER_API inline void glGenProgramPipelines(GLsizei n, GLuint *pipelines);
ECE_RENDERER_API inline void glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines);
ECE_RENDERER_API inline GLboolean glIsProgramPipeline(GLuint pipeline);
ECE_RENDERER_API inline void glBindProgramPipeline(GLuint pipeline);
ECE_RENDERER_API inline void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);
ECE_RENDERER_API inline void glActiveShaderProgram(GLuint pipeline, GLuint program);
ECE_RENDERER_API inline void glGetProgramBinary(GLuint program, GLsizei bufsize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary);
ECE_RENDERER_API inline void glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length);
ECE_RENDERER_API inline void glProgramUniform1f(GLuint program, GLint location, GLfloat v0);
ECE_RENDERER_API inline void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
ECE_RENDERER_API inline void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
ECE_RENDERER_API inline void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
ECE_RENDERER_API inline void glProgramUniform1i(GLuint program, GLint location, GLint v0);
ECE_RENDERER_API inline void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1);
ECE_RENDERER_API inline void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
ECE_RENDERER_API inline void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
ECE_RENDERER_API inline void glProgramUniform1ui(GLuint program, GLint location, GLuint v0);
ECE_RENDERER_API inline void glProgramUniform2ui(GLuint program, GLint location, GLint v0, GLuint v1);
ECE_RENDERER_API inline void glProgramUniform3ui(GLuint program, GLint location, GLint v0, GLint v1, GLuint v2);
ECE_RENDERER_API inline void glProgramUniform4ui(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLuint v3);
ECE_RENDERER_API inline void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
ECE_RENDERER_API inline void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
ECE_RENDERER_API inline void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
ECE_RENDERER_API inline void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
ECE_RENDERER_API inline void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value);
ECE_RENDERER_API inline void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value);
ECE_RENDERER_API inline void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value);
ECE_RENDERER_API inline void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value);
ECE_RENDERER_API inline void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
ECE_RENDERER_API inline void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
ECE_RENDERER_API inline void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
ECE_RENDERER_API inline void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
ECE_RENDERER_API inline void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params);
ECE_RENDERER_API inline void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
ECE_RENDERER_API inline void glGetShaderPrecisionFormat(GLenum shaderType, GLenum precisionType, GLint *range, GLint *precision);
ECE_RENDERER_API inline void glValidateProgramPipeline(GLuint pipeline);
ECE_RENDERER_API inline void glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble *v);
ECE_RENDERER_API inline void glDepthRangeIndexed(GLuint index, GLdouble nearVal, GLdouble farVal);
ECE_RENDERER_API inline void glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v);
ECE_RENDERER_API inline void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
ECE_RENDERER_API inline void glViewportIndexedfv(GLuint index, const GLfloat *v);
ECE_RENDERER_API inline void glScissorArrayv(GLuint first, GLsizei count, const GLint *v);
ECE_RENDERER_API inline void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
ECE_RENDERER_API inline void glScissorIndexedv(GLuint index, const GLint *v);

/**
 * fn CALLGL41(SIGNATURE, NAME)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 4.1 extension and call it.
 */
#define CALLGL41(SIGNATURE, NAME) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 1 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	proxy();

/**
 * fn R_CALLGL41(SIGNATURE, NAME)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 4.1 extension and call it.
 */
#define R_CALLGL41(SIGNATURE, NAME) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 1 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy();

/**
 * fn CALLGL41_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 4.1 extension and call it.
 */
#define CALLGL41_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 1 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	proxy(__VA_ARGS__);

/**
 * fn R_CALLGL41_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 4.1 extension and call it.
 */
#define R_CALLGL41_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 1 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy(__VA_ARGS__);

#include "renderer/opengl/gl41_extension.inl"

#endif // GL41_EXTENSION_HPP
