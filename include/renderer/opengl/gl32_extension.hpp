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


#ifndef GL32_EXTENSION_HPP
#define GL32_EXTENSION_HPP

#include "renderer/config.hpp"

#include "GL/glcorearb.h"

#include "utility/indexing.hpp"
#include "renderer/opengl/extension_loader.hpp"
#include "renderer/opengl/opengl_exception.hpp"

namespace ece
{
	using renderer::opengl::OpenGLExtensionException;
}

ECE_RENDERER_API inline GLenum glGetError();
ECE_RENDERER_API inline void glVertexAttrib1f(GLuint index, GLfloat v0);
ECE_RENDERER_API inline void glVertexAttrib1s(GLuint index, GLshort v0);
ECE_RENDERER_API inline void glVertexAttrib1d(GLuint index, GLdouble v0);
ECE_RENDERER_API inline void glVertexAttribI1i(GLuint index, GLint v0);
ECE_RENDERER_API inline void glVertexAttribI1ui(GLuint index, GLuint v0);
ECE_RENDERER_API inline void glVertexAttrib2f(GLuint index, GLfloat v0,	GLfloat v1);
ECE_RENDERER_API inline void glVertexAttrib2s(GLuint index, GLshort v0,	GLshort v1);
ECE_RENDERER_API inline void glVertexAttrib2d(GLuint index, GLdouble v0, GLdouble v1);
ECE_RENDERER_API inline void glVertexAttribI2i(GLuint index, GLint v0, GLint v1);
ECE_RENDERER_API inline void glVertexAttribI2ui(GLuint index, GLuint v0, GLuint v1);
ECE_RENDERER_API inline void glVertexAttrib3f(GLuint index, GLfloat v0,	GLfloat v1,	GLfloat v2);
ECE_RENDERER_API inline void glVertexAttrib3s(GLuint index, GLshort v0,	GLshort v1,	GLshort v2);
ECE_RENDERER_API inline void glVertexAttrib3d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2);
ECE_RENDERER_API inline void glVertexAttribI3i(GLuint index, GLint v0, GLint v1, GLint v2);
ECE_RENDERER_API inline void glVertexAttribI3ui(GLuint index, GLuint v0, GLuint v1, GLuint v2);
ECE_RENDERER_API inline void glVertexAttrib4f(GLuint index, GLfloat v0,	GLfloat v1,	GLfloat v2,	GLfloat v3);
ECE_RENDERER_API inline void glVertexAttrib4s(GLuint index, GLshort v0, GLshort v1,GLshort v2, GLshort v3);
ECE_RENDERER_API inline void glVertexAttrib4d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
ECE_RENDERER_API inline void glVertexAttrib4Nub(GLuint index, GLubyte v0, GLubyte v1, GLubyte v2, GLubyte v3);
ECE_RENDERER_API inline void glVertexAttribI4i(GLuint index, GLint v0, GLint v1, GLint v2, GLint v3);
ECE_RENDERER_API inline void glVertexAttribI4ui(GLuint index, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
ECE_RENDERER_API inline void glVertexAttrib1fv(GLuint index, const GLfloat *v);
ECE_RENDERER_API inline void glVertexAttrib1sv(GLuint index, const GLshort *v);
ECE_RENDERER_API inline void glVertexAttrib1dv(GLuint index, const GLdouble *v);
ECE_RENDERER_API inline void glVertexAttribI1iv(GLuint index, const GLint *v);
ECE_RENDERER_API inline void glVertexAttribI1uiv(GLuint index, const GLuint *v);
ECE_RENDERER_API inline void glVertexAttrib2fv(GLuint index, const GLfloat *v);
ECE_RENDERER_API inline void glVertexAttrib2sv(GLuint index, const GLshort *v);
ECE_RENDERER_API inline void glVertexAttrib2dv(GLuint index, const GLdouble *v);
ECE_RENDERER_API inline void glVertexAttribI2iv(GLuint index, const GLint *v);
ECE_RENDERER_API inline void glVertexAttribI2uiv(GLuint index, const GLuint *v);
ECE_RENDERER_API inline void glVertexAttrib3fv(GLuint index, const GLfloat *v);
ECE_RENDERER_API inline void glVertexAttrib3sv(GLuint index, const GLshort *v);
ECE_RENDERER_API inline void glVertexAttrib3dv(GLuint index, const GLdouble *v);
ECE_RENDERER_API inline void glVertexAttribI3iv(GLuint index, const GLint *v);
ECE_RENDERER_API inline void glVertexAttribI3uiv(GLuint index, const GLuint *v);
ECE_RENDERER_API inline void glVertexAttrib4fv(GLuint index, const GLfloat *v);
ECE_RENDERER_API inline void glVertexAttrib4sv(GLuint index, const GLshort *v);
ECE_RENDERER_API inline void glVertexAttrib4dv(GLuint index, const GLdouble *v);
ECE_RENDERER_API inline void glVertexAttrib4iv(GLuint index, const GLint *v);
ECE_RENDERER_API inline void glVertexAttrib4bv(GLuint index, const GLbyte *v);
ECE_RENDERER_API inline void glVertexAttrib4ubv(GLuint index, const GLubyte *v);
ECE_RENDERER_API inline void glVertexAttrib4usv(GLuint index, const GLushort *v);
ECE_RENDERER_API inline void glVertexAttrib4uiv(GLuint index, const GLuint *v);
ECE_RENDERER_API inline void glVertexAttrib4Nbv(GLuint index, const GLbyte *v);
ECE_RENDERER_API inline void glVertexAttrib4Nsv(GLuint index, const GLshort *v);
ECE_RENDERER_API inline void glVertexAttrib4Niv(GLuint index, const GLint *v);
ECE_RENDERER_API inline void glVertexAttrib4Nubv(GLuint index, const GLubyte *v);
ECE_RENDERER_API inline void glVertexAttrib4Nusv(GLuint index, const GLushort *v);
ECE_RENDERER_API inline void glVertexAttrib4Nuiv(GLuint index, const GLuint *v);
ECE_RENDERER_API inline void glVertexAttribI4bv(GLuint index, const GLbyte *v);
ECE_RENDERER_API inline void glVertexAttribI4ubv(GLuint index, const GLubyte *v);
ECE_RENDERER_API inline void glVertexAttribI4sv(GLuint index, const GLshort *v);
ECE_RENDERER_API inline void glVertexAttribI4usv(GLuint index, const GLushort * v);
ECE_RENDERER_API inline void glVertexAttribI4iv(GLuint index, const GLint * v);
ECE_RENDERER_API inline void glVertexAttribI4uiv(GLuint index, const GLuint * v);
ECE_RENDERER_API inline void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
ECE_RENDERER_API inline void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
ECE_RENDERER_API inline void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
ECE_RENDERER_API inline void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
ECE_RENDERER_API inline void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
ECE_RENDERER_API inline void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
ECE_RENDERER_API inline void glEnableVertexAttribArray(GLuint index);
ECE_RENDERER_API inline void glDisableVertexAttribArray(GLuint index);
ECE_RENDERER_API inline void glEnable(GLenum cap);
ECE_RENDERER_API inline void glDisable(GLenum cap);
ECE_RENDERER_API inline void glEnablei(GLenum cap, GLuint index);
ECE_RENDERER_API inline void glDisablei(GLenum cap, GLuint index);
ECE_RENDERER_API inline void glPrimitiveRestartIndex(GLuint index);
ECE_RENDERER_API inline void glDrawArrays(GLenum mode, GLint first, GLsizei count);
ECE_RENDERER_API inline void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
ECE_RENDERER_API inline void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);
ECE_RENDERER_API inline void glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const GLvoid * const * indices, GLsizei drawcount);
ECE_RENDERER_API inline void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices);
ECE_RENDERER_API inline void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
ECE_RENDERER_API inline void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices, GLsizei primcount);
ECE_RENDERER_API inline void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLint basevertex);
ECE_RENDERER_API inline void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid * indices, GLint basevertex);
ECE_RENDERER_API inline void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLsizei primcount, GLint basevertex);
ECE_RENDERER_API inline void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei * count, GLenum type, const GLvoid * const * indices, GLsizei drawcount, const GLint * basevertex);
ECE_RENDERER_API inline void glGenBuffers(GLsizei n, GLuint * buffers);
ECE_RENDERER_API inline void glDeleteBuffers(GLsizei n, const GLuint * buffers);
ECE_RENDERER_API inline void glDeleteBuffers(GLsizei n, const GLuint * buffers);
ECE_RENDERER_API inline void glBindBuffer(GLenum target, GLuint buffer);
ECE_RENDERER_API inline void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
ECE_RENDERER_API inline void glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
ECE_RENDERER_API inline void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
ECE_RENDERER_API inline void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
ECE_RENDERER_API inline void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
ECE_RENDERER_API inline void * glMapBuffer(GLenum target, GLenum access);
ECE_RENDERER_API inline void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
ECE_RENDERER_API inline GLboolean glUnmapBuffer(GLenum target);
ECE_RENDERER_API inline void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
ECE_RENDERER_API inline void glGenVertexArrays(GLsizei n, GLuint *arrays);
ECE_RENDERER_API inline void glDeleteVertexArrays(GLsizei n, const GLuint *arrays);
ECE_RENDERER_API inline void glBindVertexArray(GLuint array);
ECE_RENDERER_API inline GLboolean glIsBuffer(GLuint buffer);
ECE_RENDERER_API inline void glGetBufferParameteriv(GLenum target, GLenum value, GLint * data);
ECE_RENDERER_API inline void glGetBufferParameteri64v(GLenum target, GLenum value, GLint64 * data);
ECE_RENDERER_API inline void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);
ECE_RENDERER_API inline void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params);
ECE_RENDERER_API inline GLboolean glIsVertexArray(GLuint array);
ECE_RENDERER_API inline void glDepthRange(GLdouble nearVal, GLdouble farVal);
ECE_RENDERER_API inline void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
ECE_RENDERER_API inline void glClampColor(GLenum target, GLenum clamp);
ECE_RENDERER_API inline void glProvokingVertex(GLenum provokeMode);
ECE_RENDERER_API inline void glBeginConditionalRender(GLuint id, GLenum mode);
ECE_RENDERER_API inline void glEndConditionalRender();
ECE_RENDERER_API inline void glBeginTransformFeedback(GLenum primitiveMode);
ECE_RENDERER_API inline void glEndTransformFeedback();
ECE_RENDERER_API inline void glBeginQuery(GLenum target, GLuint id);
ECE_RENDERER_API inline void glEndQuery(GLenum target);
ECE_RENDERER_API inline void glGenQueries(GLsizei n, GLuint * ids);
ECE_RENDERER_API inline void glDeleteQueries(GLsizei n, const GLuint * ids);
ECE_RENDERER_API inline GLboolean glIsQuery(GLuint id);
ECE_RENDERER_API inline void glGetQueryiv(GLenum target, GLenum pname, GLint * params);
ECE_RENDERER_API inline void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params);
ECE_RENDERER_API inline void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params);
ECE_RENDERER_API inline void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params);
ECE_RENDERER_API inline void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params);
ECE_RENDERER_API inline GLuint glCreateShader(GLenum shaderType);
ECE_RENDERER_API inline void glShaderSource(GLuint shader, GLsizei count, const GLchar **string, const GLint *length);
ECE_RENDERER_API inline void glCompileShader(GLuint shader);
ECE_RENDERER_API inline void glDeleteShader(GLuint shader);
ECE_RENDERER_API inline GLuint glCreateProgram();
ECE_RENDERER_API inline void glAttachShader(GLuint program, GLuint shader);
ECE_RENDERER_API inline void glDetachShader(GLuint program, GLuint shader);
ECE_RENDERER_API inline void glLinkProgram(GLuint program);
ECE_RENDERER_API inline void glUseProgram(GLuint program);
ECE_RENDERER_API inline void glDeleteProgram(GLuint program);
ECE_RENDERER_API inline void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
ECE_RENDERER_API inline GLint glGetAttribLocation(GLuint program, const GLchar *name);
ECE_RENDERER_API inline void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name);
ECE_RENDERER_API inline GLint glGetUniformLocation(GLuint program, const GLchar *name);
ECE_RENDERER_API inline GLuint glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName);
ECE_RENDERER_API inline void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
ECE_RENDERER_API inline void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
ECE_RENDERER_API inline void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar **uniformNames, GLuint *uniformIndices);
ECE_RENDERER_API inline void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
ECE_RENDERER_API inline void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
ECE_RENDERER_API inline void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
ECE_RENDERER_API inline void glUniform1f(GLint location, GLfloat v0);
ECE_RENDERER_API inline void glUniform2f(GLint location, GLfloat v0, GLfloat v1);
ECE_RENDERER_API inline void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
ECE_RENDERER_API inline void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
ECE_RENDERER_API inline void glUniform1i(GLint location, GLint v0);
ECE_RENDERER_API inline void glUniform2i(GLint location, GLint v0, GLint v1);
ECE_RENDERER_API inline void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
ECE_RENDERER_API inline void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
ECE_RENDERER_API inline void glUniform1ui(GLint location, GLuint v0);
ECE_RENDERER_API inline void glUniform2ui(GLint location, GLuint v0, GLuint v1);
ECE_RENDERER_API inline void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
ECE_RENDERER_API inline void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
ECE_RENDERER_API inline void glUniform1fv(GLint location, GLsizei count, const GLfloat *value);
ECE_RENDERER_API inline void glUniform2fv(GLint location, GLsizei count, const GLfloat *value);
ECE_RENDERER_API inline void glUniform3fv(GLint location, GLsizei count, const GLfloat *value);
ECE_RENDERER_API inline void glUniform4fv(GLint location, GLsizei count, const GLfloat *value);
ECE_RENDERER_API inline void glUniform1iv(GLint location, GLsizei count, const GLint *value);
ECE_RENDERER_API inline void glUniform2iv(GLint location, GLsizei count, const GLint *value);
ECE_RENDERER_API inline void glUniform3iv(GLint location, GLsizei count, const GLint *value);
ECE_RENDERER_API inline void glUniform4iv(GLint location, GLsizei count, const GLint *value);
ECE_RENDERER_API inline void glUniform1uiv(GLint location, GLsizei count, const GLuint *value);
ECE_RENDERER_API inline void glUniform2uiv(GLint location, GLsizei count, const GLuint *value);
ECE_RENDERER_API inline void glUniform3uiv(GLint location, GLsizei count, const GLuint *value);
ECE_RENDERER_API inline void glUniform4uiv(GLint location, GLsizei count, const GLuint *value);
ECE_RENDERER_API inline void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
ECE_RENDERER_API inline void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
ECE_RENDERER_API inline void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar **varyings, GLenum bufferMode);
ECE_RENDERER_API inline void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
ECE_RENDERER_API inline void glValidateProgram(GLuint program);
ECE_RENDERER_API inline void glGetProgramiv(GLuint program, GLenum pname, GLint *params);
ECE_RENDERER_API inline void glBindFragDataLocation(GLuint program, GLuint colorNumber, const GLchar * name);
ECE_RENDERER_API inline GLint glGetFragDataLocation(GLuint program, const GLchar * name);
ECE_RENDERER_API inline GLboolean glIsShader(GLuint shader);
ECE_RENDERER_API inline void glGetShaderiv(GLuint shader, GLenum pname, GLint *params);
ECE_RENDERER_API inline void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
ECE_RENDERER_API inline void glGetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog);
ECE_RENDERER_API inline void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
ECE_RENDERER_API inline void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params);
ECE_RENDERER_API inline void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params);
ECE_RENDERER_API inline void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params);
ECE_RENDERER_API inline void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params);
ECE_RENDERER_API inline void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params);
ECE_RENDERER_API inline void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer);
ECE_RENDERER_API inline void glGetUniformfv(GLuint program, GLint location, GLfloat *params);
ECE_RENDERER_API inline void glGetUniformiv(GLuint program, GLint location, GLint *params);
ECE_RENDERER_API inline void glGetUniformuiv(GLuint program, GLint location, GLuint *params);
ECE_RENDERER_API inline GLboolean glIsProgram(GLuint program);
ECE_RENDERER_API inline void glGetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei *length, GLchar *infoLog);
ECE_RENDERER_API inline void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val);
ECE_RENDERER_API inline void glPointSize(GLfloat size);
ECE_RENDERER_API inline void glPointParameterf(GLenum pname, GLfloat param);
ECE_RENDERER_API inline void glPointParameteri(GLenum pname, GLint param);
ECE_RENDERER_API inline void glPointParameterfv(GLenum pname, const GLfloat * params);
ECE_RENDERER_API inline void glPointParameteriv(GLenum pname, const GLint * params);
ECE_RENDERER_API inline void glLineWidth(GLfloat width);
ECE_RENDERER_API inline void glFrontFace(GLenum mode);
ECE_RENDERER_API inline void glCullFace(GLenum mode);
ECE_RENDERER_API inline void glPolygonMode(GLenum face, GLenum mode);
ECE_RENDERER_API inline void glPolygonOffset(GLfloat factor, GLfloat units);
ECE_RENDERER_API inline void glPixelStoref(GLenum pname, GLfloat param);
ECE_RENDERER_API inline void glPixelStorei(GLenum pname, GLint param);
ECE_RENDERER_API inline void glActiveTexture(GLenum texture);
ECE_RENDERER_API inline void glTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * data);
ECE_RENDERER_API inline void glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * data);
ECE_RENDERER_API inline void glTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * data);
ECE_RENDERER_API inline void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
ECE_RENDERER_API inline void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
ECE_RENDERER_API inline void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
ECE_RENDERER_API inline void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
ECE_RENDERER_API inline void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels);
ECE_RENDERER_API inline void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
ECE_RENDERER_API inline void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
ECE_RENDERER_API inline void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
ECE_RENDERER_API inline void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data);
ECE_RENDERER_API inline void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
ECE_RENDERER_API inline void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data);
ECE_RENDERER_API inline void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data);
ECE_RENDERER_API inline void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
ECE_RENDERER_API inline void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data);
ECE_RENDERER_API inline void glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
ECE_RENDERER_API inline void glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
ECE_RENDERER_API inline void glTexBuffer(GLenum target, GLenum internalFormat, GLuint buffer);
ECE_RENDERER_API inline void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
ECE_RENDERER_API inline void glTexParameteri(GLenum target, GLenum pname, GLint param);
ECE_RENDERER_API inline void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params);
ECE_RENDERER_API inline void glTexParameteriv(GLenum target, GLenum pname, const GLint * params);
ECE_RENDERER_API inline void glTexParameterIiv(GLenum target, GLenum pname, const GLint * params);
ECE_RENDERER_API inline void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint * params);
ECE_RENDERER_API inline void glGenerateMipmap(GLenum target);
ECE_RENDERER_API inline void glBindTexture(GLenum target, GLuint texture);
ECE_RENDERER_API inline void glDeleteTextures(GLsizei n, const GLuint * textures);
ECE_RENDERER_API inline void glGenTextures(GLsizei n, GLuint * textures);
ECE_RENDERER_API inline void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params);
ECE_RENDERER_API inline void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params);
ECE_RENDERER_API inline void glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params);
ECE_RENDERER_API inline void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params);
ECE_RENDERER_API inline void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params);
ECE_RENDERER_API inline void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params);
ECE_RENDERER_API inline void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels);
ECE_RENDERER_API inline void glGetCompressedTexImage(GLenum target, GLint level, GLvoid * pixels);
ECE_RENDERER_API inline GLboolean glIsTexture(GLuint texture);
ECE_RENDERER_API inline void glHint(GLenum target, GLenum mode);
ECE_RENDERER_API inline void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * data);
ECE_RENDERER_API inline void glReadBuffer(GLenum mode);
ECE_RENDERER_API inline void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
ECE_RENDERER_API inline void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
ECE_RENDERER_API inline void glSampleCoverage(GLfloat value, GLboolean invert);
ECE_RENDERER_API inline void glSampleMaski(GLuint maskNumber, GLbitfield mask);
ECE_RENDERER_API inline void glStencilFunc(GLenum func, GLint ref, GLuint mask);
ECE_RENDERER_API inline void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
ECE_RENDERER_API inline void glStencilOp(GLenum sfail, GLenum dpfail, GLenum dppass);
ECE_RENDERER_API inline void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
ECE_RENDERER_API inline void glDepthFunc(GLenum func);
ECE_RENDERER_API inline void glBlendEquation(GLenum mode);
ECE_RENDERER_API inline void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
ECE_RENDERER_API inline void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
ECE_RENDERER_API inline void glBlendFunc(GLenum sfactor, GLenum dfactor);
ECE_RENDERER_API inline void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
ECE_RENDERER_API inline void glLogicOp(GLenum opcode);
ECE_RENDERER_API inline void glDrawBuffer(GLenum buf);
ECE_RENDERER_API inline void glDrawBuffers(GLsizei n, const GLenum *bufs);
ECE_RENDERER_API inline void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
ECE_RENDERER_API inline void glColorMaski(GLuint buf, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
ECE_RENDERER_API inline void glDepthMask(GLboolean flag);
ECE_RENDERER_API inline void glStencilMask(GLuint mask);
ECE_RENDERER_API inline void glStencilMaskSeparate(GLenum face, GLuint mask);
ECE_RENDERER_API inline void glClear(GLbitfield mask);
ECE_RENDERER_API inline void glClearColor(GLfloat red, 	GLfloat green, GLfloat blue, GLfloat alpha);
ECE_RENDERER_API inline void glClearDepth(GLdouble depth);
ECE_RENDERER_API inline void glClearStencil(GLint s);
ECE_RENDERER_API inline void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint * value);
ECE_RENDERER_API inline void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint * value);
ECE_RENDERER_API inline void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat * value);
ECE_RENDERER_API inline void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
ECE_RENDERER_API inline void glBindFramebuffer(GLenum target, GLuint framebuffer);
ECE_RENDERER_API inline void glDeleteFramebuffers(GLsizei n, GLuint *framebuffers);
ECE_RENDERER_API inline void glGenFramebuffers(GLsizei n, GLuint *ids);
ECE_RENDERER_API inline void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
ECE_RENDERER_API inline void glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers);
ECE_RENDERER_API inline void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers);
ECE_RENDERER_API inline void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
ECE_RENDERER_API inline void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
ECE_RENDERER_API inline void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
ECE_RENDERER_API inline void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level);
ECE_RENDERER_API inline void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
ECE_RENDERER_API inline void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
ECE_RENDERER_API inline void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint layer);
ECE_RENDERER_API inline void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
ECE_RENDERER_API inline GLenum glCheckFramebufferStatus(GLenum target);
ECE_RENDERER_API inline GLboolean glIsFramebuffer(GLuint framebuffer);
ECE_RENDERER_API inline void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params);
ECE_RENDERER_API inline GLboolean glIsRenderbuffer(GLuint renderbuffer);
ECE_RENDERER_API inline void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params);
ECE_RENDERER_API inline void glFlush();
ECE_RENDERER_API inline void glFinish();
ECE_RENDERER_API inline GLsync glFenceSync(GLenum condition, GLbitfield flags);
ECE_RENDERER_API inline void glDeleteSync(GLsync sync);
ECE_RENDERER_API inline GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
ECE_RENDERER_API inline void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
ECE_RENDERER_API inline void glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
ECE_RENDERER_API inline GLboolean glIsSync(GLsync sync);
ECE_RENDERER_API inline void glGetBooleanv(GLenum pname, GLboolean * data);
ECE_RENDERER_API inline void glGetDoublev(GLenum pname, GLdouble * data);
ECE_RENDERER_API inline void glGetFloatv(GLenum pname, GLfloat * data);
ECE_RENDERER_API inline void glGetIntegerv(GLenum pname, GLint * data);
ECE_RENDERER_API inline void glGetInteger64v(GLenum pname, GLint64 * data);
ECE_RENDERER_API inline void glGetBooleani_v(GLenum target, GLuint index, GLboolean * data);
ECE_RENDERER_API inline void glGetIntegeri_v(GLenum target, GLuint index, GLint * data);
ECE_RENDERER_API inline void glGetInteger64i_v(GLenum target, GLuint index, GLint64 * data);
ECE_RENDERER_API inline GLboolean glIsEnabled(GLenum cap);
ECE_RENDERER_API inline GLboolean glIsEnabledi(GLenum cap, GLuint index);
ECE_RENDERER_API inline const GLubyte *glGetString(GLenum name);
ECE_RENDERER_API inline const GLubyte *glGetStringi(GLenum name, GLuint index);
ECE_RENDERER_API inline void glQueryCounter(GLuint id, GLenum target);
ECE_RENDERER_API inline void glGenSamplers(GLsizei n, GLuint *samplers);
ECE_RENDERER_API inline void glBindSampler(GLuint unit, GLuint sampler);
ECE_RENDERER_API inline void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
ECE_RENDERER_API inline void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param);
ECE_RENDERER_API inline void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat * params);
ECE_RENDERER_API inline void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint * params);
ECE_RENDERER_API inline void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *params);
ECE_RENDERER_API inline void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *params);
ECE_RENDERER_API inline void glDeleteSamplers(GLsizei n, const GLuint * samplers);
ECE_RENDERER_API inline GLboolean glIsSampler(GLuint id);
ECE_RENDERER_API inline void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params);
ECE_RENDERER_API inline void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params);
ECE_RENDERER_API inline void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params);
ECE_RENDERER_API inline void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params);
ECE_RENDERER_API inline void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
ECE_RENDERER_API inline GLint glGetFragDataIndex(GLuint program, const GLchar * name);

/**
 * fn CALLGL32(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 3.2 extension and call it.
 */
#define CALLGL32(SIGNATURE, NAME) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 3, 2 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	proxy();

/**
 * fn R_CALLGL32(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 3.2 extension and call it.
 */
#define R_CALLGL32(SIGNATURE, NAME) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 3, 2 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy();

/**
 * fn CALLGL32_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 3.2 extension and call it.
 */
#define CALLGL32_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 3, 2 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	proxy(__VA_ARGS__);

/**
 * fn R_CALLGL32_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 3.2 extension and call it.
 */
#define R_CALLGL32_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 3, 2 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy(__VA_ARGS__);

#include "renderer/opengl/gl32_extension.inl"

#endif // GL32_EXTENSION_HPP
