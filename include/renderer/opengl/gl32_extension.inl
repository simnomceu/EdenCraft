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


inline GLenum glGetError() { R_CALLGL32(PFNGLGETERRORPROC, "glGetError"); }

inline void glVertexAttrib1f(GLuint index, GLfloat v0) { CALLGL32_V(PFNGLVERTEXATTRIB1FPROC, "glVertexAttrib1f", index, v0); }

inline void glVertexAttrib1s(GLuint index, GLshort v0) { CALLGL32_V(PFNGLVERTEXATTRIB1SPROC, "glVertexAttrib1s", index, v0); }

inline void glVertexAttrib1d(GLuint index, GLdouble v0) { CALLGL32_V(PFNGLVERTEXATTRIB1DPROC, "glVertexAttrib1d", index, v0); }

inline void glVertexAttribI1i(GLuint index, GLint v0) { CALLGL32_V(PFNGLVERTEXATTRIBI1IPROC, "glVertexAttribI1i", index, v0); }

inline void glVertexAttribI1ui(GLuint index, GLuint v0) { CALLGL32_V(PFNGLVERTEXATTRIBI1UIPROC, "glVertexAttribI1ui", index, v0); }

inline void glVertexAttrib2f(GLuint index, GLfloat v0, GLfloat v1) { CALLGL32_V(PFNGLVERTEXATTRIB2FPROC, "glVertexAttrib2f", index, v0, v1); }

inline void glVertexAttrib2s(GLuint index, GLshort v0, GLshort v1) { CALLGL32_V(PFNGLVERTEXATTRIB2SPROC, "glVertexAttrib2s", index, v0, v1); }

inline void glVertexAttrib2d(GLuint index, GLdouble v0, GLdouble v1) { CALLGL32_V(PFNGLVERTEXATTRIB2DPROC, "glVertexAttrib2d", index, v0, v1); }

inline void glVertexAttribI2i(GLuint index, GLint v0, GLint v1) { CALLGL32_V(PFNGLVERTEXATTRIBI2IPROC, "glVertexAttribI2i", index, v0, v1); }

inline void glVertexAttribI2ui(GLuint index, GLuint v0, GLuint v1) { CALLGL32_V(PFNGLVERTEXATTRIBI2UIPROC, "glVertexAttribI2ui", index, v0, v1); }

inline void glVertexAttrib3f(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2) { CALLGL32_V(PFNGLVERTEXATTRIB3FPROC, "glVertexAttrib3f", index, v0, v1, v2); }

inline void glVertexAttrib3s(GLuint index, GLshort v0, GLshort v1, GLshort v2) { CALLGL32_V(PFNGLVERTEXATTRIB3SPROC, "glVertexAttrib3s", index, v0, v1, v2); }

inline void glVertexAttrib3d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2) { CALLGL32_V(PFNGLVERTEXATTRIB3DPROC, "glVertexAttrib3d", index, v0, v1, v2); }

inline void glVertexAttribI3i(GLuint index, GLint v0, GLint v1, GLint v2) { CALLGL32_V(PFNGLVERTEXATTRIBI3IPROC, "glVertexAttribI3i", index, v0, v1, v2); }

inline void glVertexAttribI3ui(GLuint index, GLuint v0, GLuint v1, GLuint v2) { CALLGL32_V(PFNGLVERTEXATTRIBI3UIPROC, "glVertexAttribI3ui", index, v0, v1, v2); }

inline void glVertexAttrib4f(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { CALLGL32_V(PFNGLVERTEXATTRIB4FPROC, "glVertexAttrib4f", index, v0, v1, v2, v3); }

inline void glVertexAttrib4s(GLuint index, GLshort v0, GLshort v1, GLshort v2, GLshort v3) { CALLGL32_V(PFNGLVERTEXATTRIB4SPROC, "glVertexAttrib4s", index, v0, v1, v2, v3); }

inline void glVertexAttrib4d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) { CALLGL32_V(PFNGLVERTEXATTRIB4DPROC, "glVertexAttrib4d", index, v0, v1, v2, v3); }

inline void glVertexAttrib4Nub(GLuint index, GLubyte v0, GLubyte v1, GLubyte v2, GLubyte v3) { CALLGL32_V(PFNGLVERTEXATTRIB4NUBPROC, "glVertexAttrib4Nub", index, v0, v1, v2, v3); }

inline void glVertexAttribI4i(GLuint index, GLint v0, GLint v1, GLint v2, GLint v3) { CALLGL32_V(PFNGLVERTEXATTRIBI4IPROC, "glVertexAttribI4i", index, v0, v1, v2, v3); }

inline void glVertexAttribI4ui(GLuint index, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { CALLGL32_V(PFNGLVERTEXATTRIBI4UIPROC, "glVertexAttribI4ui", index, v0, v1, v2, v3); }

inline void glVertexAttrib1fv(GLuint index, const GLfloat *v) { CALLGL32_V(PFNGLVERTEXATTRIB1FVPROC, "glVertexAttrib1fv", index, v); }

inline void glVertexAttrib1sv(GLuint index, const GLshort *v) { CALLGL32_V(PFNGLVERTEXATTRIB1SVPROC, "glVertexAttrib1sv", index, v); }

inline void glVertexAttrib1dv(GLuint index, const GLdouble *v) { CALLGL32_V(PFNGLVERTEXATTRIB1DVPROC, "glVertexAttrib1dv", index, v); }

inline void glVertexAttribI1iv(GLuint index, const GLint *v) { CALLGL32_V(PFNGLVERTEXATTRIBI1IVPROC, "glVertexAttribI1iv", index, v); }

inline void glVertexAttribI1uiv(GLuint index, const GLuint *v) { CALLGL32_V(PFNGLVERTEXATTRIBI1UIVPROC, "glVertexAttribI1uiv", index, v); }

inline void glVertexAttrib2fv(GLuint index, const GLfloat *v) { CALLGL32_V(PFNGLVERTEXATTRIB2FVPROC, "glVertexAttrib2fv", index, v); }

inline void glVertexAttrib2sv(GLuint index, const GLshort *v) { CALLGL32_V(PFNGLVERTEXATTRIB2SVPROC, "glVertexAttrib2sv", index, v); }

inline void glVertexAttrib2dv(GLuint index, const GLdouble *v) { CALLGL32_V(PFNGLVERTEXATTRIB2DVPROC, "glVertexAttrib2dv", index, v); }

inline void glVertexAttribI2iv(GLuint index, const GLint *v) { CALLGL32_V(PFNGLVERTEXATTRIBI2IVPROC, "glVertexAttribI2iv", index, v); }

inline void glVertexAttribI2uiv(GLuint index, const GLuint *v) { CALLGL32_V(PFNGLVERTEXATTRIBI2UIVPROC, "glVertexAttribI2uiv", index, v); }

inline void glVertexAttrib3fv(GLuint index, const GLfloat *v) { CALLGL32_V(PFNGLVERTEXATTRIB3FVPROC, "glVertexAttrib3fv", index, v); }

inline void glVertexAttrib3sv(GLuint index, const GLshort *v) { CALLGL32_V(PFNGLVERTEXATTRIB3SVPROC, "glVertexAttrib3sv", index, v); }

inline void glVertexAttrib3dv(GLuint index, const GLdouble *v) { CALLGL32_V(PFNGLVERTEXATTRIB3DVPROC, "glVertexAttrib3dv", index, v); }

inline void glVertexAttribI3iv(GLuint index, const GLint *v) { CALLGL32_V(PFNGLVERTEXATTRIBI3IVPROC, "glVertexAttribI3iv", index, v); }

inline void glVertexAttribI3uiv(GLuint index, const GLuint *v) { CALLGL32_V(PFNGLVERTEXATTRIBI3UIVPROC, "glVertexAttribI3uiv", index, v); }

inline void glVertexAttrib4fv(GLuint index, const GLfloat *v) { CALLGL32_V(PFNGLVERTEXATTRIB4FVPROC, "glVertexAttrib4fv", index, v); }

inline void glVertexAttrib4sv(GLuint index, const GLshort *v) { CALLGL32_V(PFNGLVERTEXATTRIB4SVPROC, "glVertexAttrib4sv", index, v); }

inline void glVertexAttrib4dv(GLuint index, const GLdouble *v) { CALLGL32_V(PFNGLVERTEXATTRIB4DVPROC, "glVertexAttrib4dv", index, v); }

inline void glVertexAttrib4iv(GLuint index, const GLint *v) { CALLGL32_V(PFNGLVERTEXATTRIB4IVPROC, "glVertexAttrib4iv", index, v); }

inline void glVertexAttrib4bv(GLuint index, const GLbyte *v) { CALLGL32_V(PFNGLVERTEXATTRIB4BVPROC, "glVertexAttrib4bv", index, v); }

inline void glVertexAttrib4ubv(GLuint index, const GLubyte *v) { CALLGL32_V(PFNGLVERTEXATTRIB4UBVPROC, "glVertexAttrib4ubv", index, v); }

inline void glVertexAttrib4usv(GLuint index, const GLushort *v) { CALLGL32_V(PFNGLVERTEXATTRIB4USVPROC, "glVertexAttrib4usv", index, v); }

inline void glVertexAttrib4uiv(GLuint index, const GLuint *v) { CALLGL32_V(PFNGLVERTEXATTRIB4UIVPROC, "glVertexAttrib4uiv", index, v); }

inline void glVertexAttrib4Nbv(GLuint index, const GLbyte *v) { CALLGL32_V(PFNGLVERTEXATTRIB4NBVPROC, "glVertexAttrib4Nbv", index, v); }

inline void glVertexAttrib4Nsv(GLuint index, const GLshort *v) { CALLGL32_V(PFNGLVERTEXATTRIB4NSVPROC, "glVertexAttrib4Nsv", index, v); }

inline void glVertexAttrib4Niv(GLuint index, const GLint *v) { CALLGL32_V(PFNGLVERTEXATTRIB4NIVPROC, "glVertexAttrib4Niv", index, v); }

inline void glVertexAttrib4Nubv(GLuint index, const GLubyte *v) { CALLGL32_V(PFNGLVERTEXATTRIB4NUBVPROC, "glVertexAttrib4Nubv", index, v); }

inline void glVertexAttrib4Nusv(GLuint index, const GLushort *v) { CALLGL32_V(PFNGLVERTEXATTRIB4NUSVPROC, "glVertexAttrib4Nusv", index, v); }

inline void glVertexAttrib4Nuiv(GLuint index, const GLuint *v) { CALLGL32_V(PFNGLVERTEXATTRIB4NUIVPROC, "glVertexAttrib4Nuiv", index, v); }

inline void glVertexAttribI4bv(GLuint index, const GLbyte *v) { CALLGL32_V(PFNGLVERTEXATTRIBI4BVPROC, "glVertexAttribI4bv", index, v); }

inline void glVertexAttribI4ubv(GLuint index, const GLubyte *v) { CALLGL32_V(PFNGLVERTEXATTRIBI4UBVPROC, "glVertexAttribI4ubv", index, v); }

inline void glVertexAttribI4sv(GLuint index, const GLshort *v) { CALLGL32_V(PFNGLVERTEXATTRIBI4SVPROC, "glVertexAttribI4sv", index, v); }

inline void glVertexAttribI4usv(GLuint index, const GLushort * v) { CALLGL32_V(PFNGLVERTEXATTRIBI4USVPROC, "glVertexAttribI4usv", index, v); }

inline void glVertexAttribI4iv(GLuint index, const GLint * v) { CALLGL32_V(PFNGLVERTEXATTRIBI4IVPROC, "glVertexAttribI4iv", index, v); }

inline void glVertexAttribI4uiv(GLuint index, const GLuint * v) { CALLGL32_V(PFNGLVERTEXATTRIBI4UIVPROC, "glVertexAttribI4uiv", index, v); }

inline void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { CALLGL32_V(PFNGLVERTEXATTRIBP1UIPROC, "glVertexAttribP1ui", index, type, normalized, value); }

inline void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { CALLGL32_V(PFNGLVERTEXATTRIBP2UIPROC, "glVertexAttribP2ui", index, type, normalized, value); }

inline void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { CALLGL32_V(PFNGLVERTEXATTRIBP3UIPROC, "glVertexAttribP3ui", index, type, normalized, value); }

inline void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { CALLGL32_V(PFNGLVERTEXATTRIBP4UIPROC, "glVertexAttribP4ui", index, type, normalized, value); }

inline void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer)
	{ CALLGL32_V(PFNGLVERTEXATTRIBPOINTERPROC, "glVertexAttribPointer", index, size, type, normalized, stride, pointer); }

inline void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
	{ CALLGL32_V(PFNGLVERTEXATTRIBIPOINTERPROC, "glVertexAttribIPointer", index, size, type, stride, pointer); }

inline void glEnableVertexAttribArray(GLuint index) { CALLGL32_V(PFNGLENABLEVERTEXATTRIBARRAYPROC, "glEnableVertexAttribArray", index); }

inline void glDisableVertexAttribArray(GLuint index) { CALLGL32_V(PFNGLDISABLEVERTEXATTRIBARRAYPROC, "glDisableVertexAttribArray", index); }

inline void glEnable(GLenum cap) { CALLGL32_V(PFNGLENABLEPROC, "glEnable", cap); }

inline void glDisable(GLenum cap) { CALLGL32_V(PFNGLDISABLEPROC, "glDisable", cap); }

inline void glEnablei(GLenum cap, GLuint index) { CALLGL32_V(PFNGLENABLEIPROC, "glEnablei", cap, index); }

inline void glDisablei(GLenum cap, GLuint index) { CALLGL32_V(PFNGLDISABLEIPROC, "glDisablei", cap, index); }

inline void glPrimitiveRestartIndex(GLuint index) { CALLGL32_V(PFNGLPRIMITIVERESTARTINDEXPROC, "glPrimitiveRestartIndex", index); }

inline void glDrawArrays(GLenum mode, GLint first, GLsizei count) { CALLGL32_V(PFNGLDRAWARRAYSEXTPROC, "glDrawArraysEXT", mode, first, count); }

inline void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) { CALLGL32_V(PFNGLMULTIDRAWARRAYSPROC, "glMultiDrawArrays", mode, first, count, drawcount); }

inline void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) { CALLGL32_V(PFNGLDRAWELEMENTSPROC, "glDrawElements", mode, count, type, indices); }

inline void glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const GLvoid * const * indices, GLsizei drawcount)
	{ CALLGL32_V(PFNGLMULTIDRAWELEMENTSPROC, "glMultiDrawElements", mode, count, type, indices, drawcount); }

inline void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices)
	{ CALLGL32_V(PFNGLDRAWRANGEELEMENTSPROC, "glDrawRangeElements", mode, start, end, count, type, indices); }

inline void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount) { CALLGL32_V(PFNGLDRAWARRAYSINSTANCEDPROC, "glDrawArraysInstanced", mode, first, count, primcount); }

inline void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices, GLsizei primcount)
	{ CALLGL32_V(PFNGLDRAWELEMENTSINSTANCEDPROC, "glDrawElementsInstanced", mode, count, type, indices, primcount); }

inline void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLint basevertex)
	{ CALLGL32_V(PFNGLDRAWELEMENTSBASEVERTEXPROC, "glDrawElementsBaseVertex", mode, count, type, indices, basevertex); }

inline void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid * indices, GLint basevertex)
	{ CALLGL32_V(PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC, "glDrawRangeElementsBaseVertex", mode, start, end, count, type, indices, basevertex); }

inline void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLsizei primcount, GLint basevertex)
	{ CALLGL32_V(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC, "glDrawElementsInstancedBaseVertex", mode, count, type, indices, primcount, basevertex); }

inline void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei * count, GLenum type, const GLvoid * const * indices, GLsizei drawcount, const GLint * basevertex)
	{ CALLGL32_V(PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC, "glMultiDrawElementsBaseVertex", mode, count, type, indices, drawcount, basevertex); }

inline void glGenBuffers(GLsizei n, GLuint * buffers) { CALLGL32_V(PFNGLGENBUFFERSPROC, "glGenBuffers", n, buffers); }

inline void glDeleteBuffers(GLsizei n, const GLuint * buffers) { CALLGL32_V(PFNGLDELETEBUFFERSPROC, "glDeleteBuffers", n, buffers); }

inline void glBindBuffer(GLenum target, GLuint buffer) { CALLGL32_V(PFNGLBINDBUFFERPROC, "glBindBuffer", target, buffer); }

inline void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
	{ CALLGL32_V(PFNGLBINDBUFFERRANGEPROC, "glBindBufferRange", target, index, buffer, offset, size); }

inline void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) { CALLGL32_V(PFNGLBINDBUFFERBASEPROC, "glBindBufferBase", target, index, buffer); }

inline void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) { CALLGL32_V(PFNGLBUFFERDATAPROC, "glBufferData", target, size, data, usage); }

inline void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) { CALLGL32_V(PFNGLBUFFERSUBDATAPROC, "glBufferSubData", target, offset, size, data); }

inline void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) { CALLGL32_V(PFNGLMAPBUFFERRANGEPROC, "glMapBufferRange", target, offset, length, access); }

inline void * glMapBuffer(GLenum target, GLenum access) { CALLGL32_V(PFNGLMAPBUFFERPROC, "glMapBuffer", target, access); }

inline void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) { CALLGL32_V(PFNGLFLUSHMAPPEDBUFFERRANGEPROC, "glFlushMappedBufferRange", target, offset, length); }

inline GLboolean glUnmapBuffer(GLenum target) { R_CALLGL32_V(PFNGLUNMAPBUFFERPROC, "glUnmapBuffer", target); }

inline void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
	{ CALLGL32_V(PFNGLCOPYBUFFERSUBDATAPROC, "glCopyBufferSubData", readTarget, writeTarget, readOffset, writeOffset, size); }

inline void glGenVertexArrays(GLsizei n, GLuint *arrays) { CALLGL32_V(PFNGLGENVERTEXARRAYSPROC, "glGenVertexArrays", n, arrays); }

inline void glDeleteVertexArrays(GLsizei n, const GLuint *arrays) { CALLGL32_V(PFNGLDELETEVERTEXARRAYSPROC, "glDeleteVertexArrays", n, arrays); }

inline void glBindVertexArray(GLuint array) { CALLGL32_V(PFNGLBINDVERTEXARRAYPROC, "glBindVertexArray", array); }

inline GLboolean glIsBuffer(GLuint buffer) { R_CALLGL32_V(PFNGLISBUFFERPROC, "glIsBuffer", buffer); }

inline void glGetBufferParameteriv(GLenum target, GLenum value, GLint * data) { CALLGL32_V(PFNGLGETBUFFERPARAMETERIVPROC, "glGetBufferParameteriv", target, value, data); }

inline void glGetBufferParameteri64v(GLenum target, GLenum value, GLint64 * data) { CALLGL32_V(PFNGLGETBUFFERPARAMETERI64VPROC, "glGetBufferParameteri64v", target, value, data); }

inline void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) { CALLGL32_V(PFNGLGETBUFFERSUBDATAPROC, "glGetBufferSubData", target, offset, size, data); }

inline void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params) { CALLGL32_V(PFNGLGETBUFFERPOINTERVPROC, "glGetBufferPointerv", target, pname, params); }

inline GLboolean glIsVertexArray(GLuint array) { R_CALLGL32_V(PFNGLISVERTEXARRAYPROC, "glIsVertexArray", array); }

inline void glDepthRange(GLdouble nearVal, GLdouble farVal) { CALLGL32_V(PFNGLDEPTHRANGEPROC, "glDepthRange", nearVal, farVal); }

inline void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) { CALLGL32_V(PFNGLVIEWPORTPROC, "glViewport", x, y, width, height); }

inline void glClampColor(GLenum target, GLenum clamp) { CALLGL32_V(PFNGLCLAMPCOLORPROC, "glClampColor", target, clamp); }

inline void glProvokingVertex(GLenum provokeMode) { CALLGL32_V(PFNGLPROVOKINGVERTEXPROC, "glProvokingVertex", provokeMode); }

inline void glBeginConditionalRender(GLuint id, GLenum mode) { CALLGL32_V(PFNGLBEGINCONDITIONALRENDERPROC, "glBeginConditionalRender", id, mode); }

inline void glEndConditionalRender() { CALLGL32(PFNGLENDCONDITIONALRENDERPROC, "glEndConditionalRender"); }

inline void glBeginTransformFeedback(GLenum primitiveMode) { CALLGL32_V(PFNGLBEGINTRANSFORMFEEDBACKPROC, "glBeginTransformFeedback", primitiveMode); }

inline void glEndTransformFeedback() { CALLGL32(PFNGLENDTRANSFORMFEEDBACKPROC, "glEndTransformFeedback"); }

inline void glBeginQuery(GLenum target, GLuint id) { CALLGL32_V(PFNGLBEGINQUERYPROC, "glBeginQuery", target, id); }

inline void glEndQuery(GLenum target) { CALLGL32_V(PFNGLENDQUERYPROC, "glEndQuery", target); }

inline void glGenQueries(GLsizei n, GLuint * ids) { CALLGL32_V(PFNGLGENQUERIESPROC, "glGenQueries", n, ids); }

inline void glDeleteQueries(GLsizei n, const GLuint * ids) { CALLGL32_V(PFNGLDELETEQUERIESPROC, "glDeleteQueries", n, ids); }

inline GLboolean glIsQuery(GLuint id) { R_CALLGL32_V(PFNGLISQUERYPROC, "glIsQuery", id); }

inline void glGetQueryiv(GLenum target, GLenum pname, GLint * params) { CALLGL32_V(PFNGLGETQUERYIVPROC, "glGetQueryiv", target, pname, params); }

inline void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) { CALLGL32_V(PFNGLGETQUERYOBJECTIVPROC, "glGetQueryObjectiv", id, pname, params); }

inline void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) { CALLGL32_V(PFNGLGETQUERYOBJECTUIVPROC, "glGetQueryObjectuiv", id, pname, params); }

inline void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params) { CALLGL32_V(PFNGLGETQUERYOBJECTI64VPROC, "glGetQueryObjecti64v", id, pname, params); }

inline void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params) { CALLGL32_V(PFNGLGETQUERYOBJECTUI64VPROC, "glGetQueryObjectui64v", id, pname, params); }

inline GLuint glCreateShader(GLenum shaderType) { R_CALLGL32_V(PFNGLCREATESHADERPROC, "glCreateShader", shaderType); }

inline void glShaderSource(GLuint shader, GLsizei count, const GLchar **string, const GLint *length) { CALLGL32_V(PFNGLSHADERSOURCEPROC, "glShaderSource", shader, count, string, length); }

inline void glCompileShader(GLuint shader) { CALLGL32_V(PFNGLCOMPILESHADERPROC, "glCompileShader", shader); }

inline void glDeleteShader(GLuint shader) { CALLGL32_V(PFNGLDELETESHADERPROC, "glDeleteShader", shader); }

inline GLuint glCreateProgram() { R_CALLGL32(PFNGLCREATEPROGRAMPROC, "glCreateProgram"); }

inline void glAttachShader(GLuint program, GLuint shader) { CALLGL32_V(PFNGLATTACHSHADERPROC, "glAttachShader", program, shader); }

inline void glDetachShader(GLuint program, GLuint shader) { CALLGL32_V(PFNGLDETACHSHADERPROC, "glDetachShader", program, shader); }

inline void glLinkProgram(GLuint program) { CALLGL32_V(PFNGLLINKPROGRAMPROC, "glLinkProgram", program); }

inline void glUseProgram(GLuint program) { CALLGL32_V(PFNGLUSEPROGRAMPROC, "glUseProgram", program); }

inline void glDeleteProgram(GLuint program) { CALLGL32_V(PFNGLDELETEPROGRAMPROC, "glDeleteProgram", program); }

inline void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
	{ CALLGL32_V(PFNGLGETACTIVEATTRIBPROC, "glGetActiveAttrib", program, index, bufSize, length, size, type, name); }

inline GLint glGetAttribLocation(GLuint program, const GLchar *name) { R_CALLGL32_V(PFNGLGETATTRIBLOCATIONPROC, "glGetAttribLocation", program, name); }

inline void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) { CALLGL32_V(PFNGLBINDATTRIBLOCATIONPROC, "glBindAttribLocation", program, index, name); }

inline GLint glGetUniformLocation(GLuint program, const GLchar *name) { R_CALLGL32_V(PFNGLGETUNIFORMLOCATIONPROC, "glGetUniformLocation", program, name); }

inline GLuint glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) { R_CALLGL32_V(PFNGLGETUNIFORMBLOCKINDEXPROC, "glGetUniformBlockIndex", program, uniformBlockName); }

inline void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName)
	{ CALLGL32_V(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC, "glGetActiveUniformBlockName", program, uniformBlockIndex, bufSize, length, uniformBlockName); }

inline void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params)
	{ CALLGL32_V(PFNGLGETACTIVEUNIFORMBLOCKIVPROC, "glGetActiveUniformBlockiv", program, uniformBlockIndex, pname, params); }

inline void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar **uniformNames, GLuint *uniformIndices)
	{ CALLGL32_V(PFNGLGETUNIFORMINDICESPROC, "glGetUniformIndices", program, uniformCount, uniformNames, uniformIndices); }

inline void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName)
	{ CALLGL32_V(PFNGLGETACTIVEUNIFORMNAMEPROC, "glGetActiveUniformName", program, uniformIndex, bufSize, length, uniformName); }

inline void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
	{ CALLGL32_V(PFNGLGETACTIVEUNIFORMPROC, "glGetActiveUniform", program, index, bufSize, length, size, type, name); }

inline void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params)
	{ CALLGL32_V(PFNGLGETACTIVEUNIFORMSIVPROC, "glGetActiveUniformsiv", program, uniformCount, uniformIndices, pname, params); }

inline void glUniform1f(GLint location, GLfloat v0) { CALLGL32_V(PFNGLUNIFORM1FPROC, "glUniform1f", location, v0); }

inline void glUniform2f(GLint location, GLfloat v0, GLfloat v1) { CALLGL32_V(PFNGLUNIFORM2FPROC, "glUniform2f", location, v0, v1); }

inline void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { CALLGL32_V(PFNGLUNIFORM3FPROC, "glUniform3f", location, v0, v1, v2); }

inline void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { CALLGL32_V(PFNGLUNIFORM4FPROC, "glUniform4f", location, v0, v1, v2, v3); }

inline void glUniform1i(GLint location, GLint v0) { CALLGL32_V(PFNGLUNIFORM1IPROC, "glUniform1i", location, v0); }

inline void glUniform2i(GLint location, GLint v0, GLint v1) { CALLGL32_V(PFNGLUNIFORM2IPROC, "glUniform2i", location, v0, v1); }

inline void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) { CALLGL32_V(PFNGLUNIFORM3IPROC, "glUniform3i", location, v0, v1, v2); }

inline void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { CALLGL32_V(PFNGLUNIFORM4IPROC, "glUniform4i", location, v0, v1, v2, v3); }

inline void glUniform1ui(GLint location, GLuint v0) { CALLGL32_V(PFNGLUNIFORM1UIPROC, "glUniform1ui", location, v0); }

inline void glUniform2ui(GLint location, GLuint v0, GLuint v1) { CALLGL32_V(PFNGLUNIFORM2UIPROC, "glUniform2ui", location, v0, v1); }

inline void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) { CALLGL32_V(PFNGLUNIFORM3UIPROC, "glUniform3ui", location, v0, v1, v2); }

inline void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { CALLGL32_V(PFNGLUNIFORM4UIPROC, "glUniform4ui", location, v0, v1, v2, v3); }

inline void glUniform1fv(GLint location, GLsizei count, const GLfloat *value) { CALLGL32_V(PFNGLUNIFORM1FVPROC, "glUniform1fv", location, count, value); }

inline void glUniform2fv(GLint location, GLsizei count, const GLfloat *value) { CALLGL32_V(PFNGLUNIFORM2FVPROC, "glUniform2fv", location, count, value); }

inline void glUniform3fv(GLint location, GLsizei count, const GLfloat *value) { CALLGL32_V(PFNGLUNIFORM3FVPROC, "glUniform3fv", location, count, value); }

inline void glUniform4fv(GLint location, GLsizei count, const GLfloat *value) { CALLGL32_V(PFNGLUNIFORM4FVPROC, "glUniform4fv", location, count, value); }

inline void glUniform1iv(GLint location, GLsizei count, const GLint *value) { CALLGL32_V(PFNGLUNIFORM1IVPROC, "glUniform1iv", location, count, value); }

inline void glUniform2iv(GLint location, GLsizei count, const GLint *value) { CALLGL32_V(PFNGLUNIFORM2IVPROC, "glUniform2iv", location, count, value); }

inline void glUniform3iv(GLint location, GLsizei count, const GLint *value) { CALLGL32_V(PFNGLUNIFORM3IVPROC, "glUniform3iv", location, count, value); }

inline void glUniform4iv(GLint location, GLsizei count, const GLint *value) { CALLGL32_V(PFNGLUNIFORM4IVPROC, "glUniform4iv", location, count, value); }

inline void glUniform1uiv(GLint location, GLsizei count, const GLuint *value) { CALLGL32_V(PFNGLUNIFORM1UIVPROC, "glUniform1uiv", location, count, value); }

inline void glUniform2uiv(GLint location, GLsizei count, const GLuint *value) { CALLGL32_V(PFNGLUNIFORM2UIVPROC, "glUniform2uiv", location, count, value); }

inline void glUniform3uiv(GLint location, GLsizei count, const GLuint *value) { CALLGL32_V(PFNGLUNIFORM3UIVPROC, "glUniform3uiv", location, count, value); }

inline void glUniform4uiv(GLint location, GLsizei count, const GLuint *value) { CALLGL32_V(PFNGLUNIFORM4UIVPROC, "glUniform4uiv", location, count, value); }

inline void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { CALLGL32_V(PFNGLUNIFORMMATRIX2FVPROC, "glUniformMatrix2fv", location, count, transpose, value); }

inline void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { CALLGL32_V(PFNGLUNIFORMMATRIX3FVPROC, "glUniformMatrix3fv", location, count, transpose, value); }

inline void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { CALLGL32_V(PFNGLUNIFORMMATRIX4FVPROC, "glUniformMatrix4fv", location, count, transpose, value); }

inline void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL32_V(PFNGLUNIFORMMATRIX2X3FVPROC, "glUniformMatrix2x3fv", location, count, transpose, value); }

inline void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL32_V(PFNGLUNIFORMMATRIX3X2FVPROC, "glUniformMatrix3x2fv", location, count, transpose, value); }

inline void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL32_V(PFNGLUNIFORMMATRIX2X4FVPROC, "glUniformMatrix2x4fv", location, count, transpose, value); }

inline void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL32_V(PFNGLUNIFORMMATRIX4X2FVPROC, "glUniformMatrix4x2fv", location, count, transpose, value); }

inline void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL32_V(PFNGLUNIFORMMATRIX3X4FVPROC, "glUniformMatrix3x4fv", location, count, transpose, value); }

inline void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL32_V(PFNGLUNIFORMMATRIX4X3FVPROC, "glUniformMatrix4x3fv", location, count, transpose, value); }

inline void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
	{ CALLGL32_V(PFNGLUNIFORMBLOCKBINDINGPROC, "glUniformBlockBinding", program, uniformBlockIndex, uniformBlockBinding); }

inline void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar **varyings, GLenum bufferMode)
	{ CALLGL32_V(PFNGLTRANSFORMFEEDBACKVARYINGSPROC, "glTransformFeedbackVaryings", program, count, varyings, bufferMode); }

inline void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)
	{ CALLGL32_V(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC, "glGetTransformFeedbackVarying", program, index, bufSize, length, size, type, name); }

inline void glValidateProgram(GLuint program) { CALLGL32_V(PFNGLVALIDATEPROGRAMPROC, "glValidateProgram", program); }

inline void glGetProgramiv(GLuint program, GLenum pname, GLint *params) { CALLGL32_V(PFNGLGETPROGRAMIVPROC, "glGetProgramiv", program, pname, params); }

inline void glBindFragDataLocation(GLuint program, GLuint colorNumber, const GLchar * name) { CALLGL32_V(PFNGLBINDFRAGDATALOCATIONPROC, "glBindFragDataLocation", program, colorNumber, name); }

inline GLint glGetFragDataLocation(GLuint program, const GLchar * name) { R_CALLGL32_V(PFNGLGETFRAGDATALOCATIONPROC, "glGetFragDataLocation", program, name); }

inline GLboolean glIsShader(GLuint shader) { R_CALLGL32_V(PFNGLISSHADERPROC, "glIsShader", shader); }

inline void glGetShaderiv(GLuint shader, GLenum pname, GLint *params) { CALLGL32_V(PFNGLGETSHADERIVPROC, "glGetShaderiv", shader, pname, params); }

inline void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) { CALLGL32_V(PFNGLGETATTACHEDSHADERSPROC, "glGetAttachedShaders", program, maxCount, count, shaders); }

inline void glGetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog) { CALLGL32_V(PFNGLGETSHADERINFOLOGPROC, "glGetShaderInfoLog", shader, maxLength, length, infoLog); }

inline void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) { CALLGL32_V(PFNGLGETSHADERSOURCEPROC, "glGetShaderSource", shader, bufSize, length, source); }

inline void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params) { CALLGL32_V(PFNGLGETVERTEXATTRIBDVPROC, "glGetVertexAttribdv", index, pname, params); }

inline void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) { CALLGL32_V(PFNGLGETVERTEXATTRIBFVPROC, "glGetVertexAttribfv", index, pname, params); }

inline void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) { CALLGL32_V(PFNGLGETVERTEXATTRIBIVPROC, "glGetVertexAttribiv", index, pname, params); }

inline void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params) { CALLGL32_V(PFNGLGETVERTEXATTRIBIIVPROC, "glGetVertexAttribIiv", index, pname, params); }

inline void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params) { CALLGL32_V(PFNGLGETVERTEXATTRIBIUIVPROC, "glGetVertexAttribIuiv", index, pname, params); }

inline void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer) { CALLGL32_V(PFNGLGETVERTEXATTRIBPOINTERVPROC, "glGetVertexAttribPointerv", index, pname, pointer); }

inline void glGetUniformfv(GLuint program, GLint location, GLfloat *params) { CALLGL32_V(PFNGLGETUNIFORMFVPROC, "glGetUniformfv", program, location, params); }

inline void glGetUniformiv(GLuint program, GLint location, GLint *params) { CALLGL32_V(PFNGLGETUNIFORMIVPROC, "glGetUniformiv", program, location, params); }

inline void glGetUniformuiv(GLuint program, GLint location, GLuint *params) { CALLGL32_V(PFNGLGETUNIFORMUIVPROC, "glGetUniformuiv", program, location, params); }

inline GLboolean glIsProgram(GLuint program) { R_CALLGL32_V(PFNGLISPROGRAMPROC, "glIsProgram", program); }

inline void glGetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei *length, GLchar *infoLog) { CALLGL32_V(PFNGLGETPROGRAMINFOLOGPROC, "glGetProgramInfoLog", program, maxLength, length, infoLog); }

inline void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val) { CALLGL32_V(PFNGLGETMULTISAMPLEFVPROC, "glGetMultisamplefv", pname, index, val); }

inline void glPointSize(GLfloat size) { CALLGL32_V(PFNGLPOINTSIZEPROC, "glPointSize", size); }

inline void glPointParameterf(GLenum pname, GLfloat param) { CALLGL32_V(PFNGLPOINTPARAMETERFPROC, "glPointParameterf", pname, param); }

inline void glPointParameteri(GLenum pname, GLint param) { CALLGL32_V(PFNGLPOINTPARAMETERIPROC, "glPointParameteri", pname, param); }

inline void glPointParameterfv(GLenum pname, const GLfloat * params) { CALLGL32_V(PFNGLPOINTPARAMETERFVPROC, "glPointParameterfv", pname, params); }

inline void glPointParameteriv(GLenum pname, const GLint * params) { CALLGL32_V(PFNGLPOINTPARAMETERIVPROC, "glPointParameteriv", pname, params); }

inline void glLineWidth(GLfloat width) { CALLGL32_V(PFNGLLINEWIDTHPROC, "glLineWidth", width); }

inline void glFrontFace(GLenum mode) { CALLGL32_V(PFNGLFRONTFACEPROC, "glFrontFace", mode); }

inline void glCullFace(GLenum mode) { CALLGL32_V(PFNGLCULLFACEPROC, "glCullFace", mode); }

inline void glPolygonMode(GLenum face, GLenum mode) { CALLGL32_V(PFNGLPOLYGONMODEPROC, "glPolygonMode", face, mode); }

inline void glPolygonOffset(GLfloat factor, GLfloat units) { CALLGL32_V(PFNGLPOLYGONOFFSETEXTPROC, "glPolygonOffsetEXT", factor, units); }

inline void glPixelStoref(GLenum pname, GLfloat param) { CALLGL32_V(PFNGLPIXELSTOREFPROC, "glPixelStoref", pname, param); }

inline void glPixelStorei(GLenum pname, GLint param) { CALLGL32_V(PFNGLPIXELSTOREIPROC, "glPixelStorei", pname, param); }

inline void glActiveTexture(GLenum texture) { CALLGL32_V(PFNGLACTIVETEXTUREPROC, "glActiveTexture", texture); }

inline void glTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL32_V(PFNGLTEXIMAGE3DPROC, "glTexImage3D", target, level, internalFormat, width, height, depth, border, format, type, data); }

inline void glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL32_V(PFNGLTEXIMAGE2DPROC, "glTexImage2D", target, level, internalFormat, width, height, border, format, type, data); }

inline void glTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL32_V(PFNGLTEXIMAGE1DPROC, "glTexImage1D", target, level, internalFormat, width, border, format, type, data); }

inline void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
	{ CALLGL32_V(PFNGLCOPYTEXIMAGE2DPROC, "glCopyTexImage2D", target, level, internalformat, x, y, width, height, border); }

inline void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
	{ CALLGL32_V(PFNGLCOPYTEXIMAGE1DPROC, "glCopyTexImage1D", target, level, internalformat, x, y, width, border); }

inline void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels)
	{ CALLGL32_V(PFNGLTEXSUBIMAGE3DPROC, "glTexSubImage3D", target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }

inline void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels)
	{ CALLGL32_V(PFNGLTEXSUBIMAGE2DPROC, "glTexSubImage2D", target, level, xoffset, yoffset, width, height, format, type, pixels); }

inline void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels)
	{ CALLGL32_V(PFNGLTEXSUBIMAGE1DPROC, "glTexSubImage1D", target, level, xoffset, width, format, type, pixels); }

inline void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
	{ CALLGL32_V(PFNGLCOPYTEXSUBIMAGE3DPROC, "glCopyTexSubImage3D", target, level, xoffset, yoffset, zoffset, x, y, width, height); }

inline void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
	{ CALLGL32_V(PFNGLCOPYTEXSUBIMAGE2DPROC, "glCopyTexSubImage2D", target, level, xoffset, yoffset, x, y, width, height); }

inline void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
	{ CALLGL32_V(PFNGLCOPYTEXSUBIMAGE1DPROC, "glCopyTexSubImage1D", target, level, xoffset, x, y, width); }

inline void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data)
	{ CALLGL32_V(PFNGLCOMPRESSEDTEXIMAGE3DPROC, "glCompressedTexImage3D", target, level, internalformat, width, height, depth, border, imageSize, data); }

inline void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data)
	{ CALLGL32_V(PFNGLCOMPRESSEDTEXIMAGE2DPROC, "glCompressedTexImage2D", target, level, internalformat, width, height, border, imageSize, data); }

inline void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data)
	{ CALLGL32_V(PFNGLCOMPRESSEDTEXIMAGE1DPROC, "glCompressedTexImage1D", target, level, internalformat, width, border, imageSize, data); }

inline void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize,
										const GLvoid * data)
	{ CALLGL32_V(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC, "glCompressedTexSubImage3D", target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }

inline void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data)
	{ CALLGL32_V(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC, "glCompressedTexSubImage2D", target, level, xoffset, yoffset, width, height, format, imageSize, data); }

inline void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data)
	{ CALLGL32_V(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC, "glCompressedTexSubImage1D", target, level, xoffset, width, format, imageSize, data); }

inline void glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
	{ CALLGL32_V(PFNGLTEXIMAGE3DMULTISAMPLEPROC, "glTexImage3DMultisample", target, samples, internalformat, width, height, depth, fixedsamplelocations); }

inline void glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
	{ CALLGL32_V(PFNGLTEXIMAGE2DMULTISAMPLEPROC, "glTexImage2DMultisample", target, samples, internalformat, width, height, fixedsamplelocations); }

inline void glTexBuffer(GLenum target, GLenum internalFormat, GLuint buffer) { CALLGL32_V(PFNGLTEXBUFFERPROC, "glTexBuffer", target, internalFormat, buffer); }

inline void glTexParameterf(GLenum target, GLenum pname, GLfloat param) { CALLGL32_V(PFNGLTEXPARAMETERFPROC, "glTexParameterf", target, pname, param); }

inline void glTexParameteri(GLenum target, GLenum pname, GLint param) { CALLGL32_V(PFNGLTEXPARAMETERIPROC, "glTexParameteri", target, pname, param); }

inline void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) { CALLGL32_V(PFNGLTEXPARAMETERFVPROC, "glTexParameterfv", target, pname, params); }

inline void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) { CALLGL32_V(PFNGLTEXPARAMETERIVPROC, "glTexParameteriv", target, pname, params); }

inline void glTexParameterIiv(GLenum target, GLenum pname, const GLint * params) { CALLGL32_V(PFNGLTEXPARAMETERIIVPROC, "glTexParameterIiv", target, pname, params); }

inline void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint * params) { CALLGL32_V(PFNGLTEXPARAMETERIUIVPROC, "glTexParameterIuiv", target, pname, params); }

inline void glGenerateMipmap(GLenum target) { CALLGL32_V(PFNGLGENERATEMIPMAPPROC, "glGenerateMipmap", target); }

inline void glBindTexture(GLenum target, GLuint texture) { CALLGL32_V(PFNGLBINDTEXTUREPROC, "glBindTexture", target, texture); }

inline void glDeleteTextures(GLsizei n, const GLuint * textures) { CALLGL32_V(PFNGLDELETETEXTURESEXTPROC, "glDeleteTexturesEXT", n, textures); }

inline void glGenTextures(GLsizei n, GLuint * textures) { CALLGL32_V(PFNGLGENTEXTURESEXTPROC, "glGenTexturesEXT", n, textures); }

inline void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) { CALLGL32_V(PFNGLGETTEXPARAMETERFVPROC, "glGetTexParameterfv", target, pname, params); }

inline void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) { CALLGL32_V(PFNGLGETTEXPARAMETERIVPROC, "glGetTexParameteriv", target, pname, params); }

inline void glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params) { CALLGL32_V(PFNGLGETTEXPARAMETERIIVPROC, "glGetTexParameterIiv", target, pname, params); }

inline void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params) { CALLGL32_V(PFNGLGETTEXPARAMETERIUIVPROC, "glGetTexParameterIuiv", target, pname, params); }

inline void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) { CALLGL32_V(PFNGLGETTEXLEVELPARAMETERFVPROC, "glGetTexLevelParameterfv", target, level, pname, params); }

inline void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) { CALLGL32_V(PFNGLGETTEXLEVELPARAMETERIVPROC, "glGetTexLevelParameteriv", target, level, pname, params); }

inline void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels) { CALLGL32_V(PFNGLGETTEXIMAGEPROC, "glGetTexImage", target, level, format, type, pixels); }

inline void glGetCompressedTexImage(GLenum target, GLint level, GLvoid * pixels) { CALLGL32_V(PFNGLGETCOMPRESSEDTEXIMAGEPROC, "glGetCompressedTexImage", target, level, pixels); }

inline GLboolean glIsTexture(GLuint texture) { R_CALLGL32_V(PFNGLISTEXTUREEXTPROC, "glIsTextureEXT", texture); }

inline void glHint(GLenum target, GLenum mode) { CALLGL32_V(PFNGLHINTPROC, "glHint", target, mode); }

inline void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * data)
	{ CALLGL32_V(PFNGLREADPIXELSPROC, "glReadPixels", x, y, width, height, format, type, data); }

inline void glReadBuffer(GLenum mode) { CALLGL32_V(PFNGLREADBUFFERPROC, "glReadBuffer", mode); }

inline void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
	{ CALLGL32_V(PFNGLBLITFRAMEBUFFERPROC, "glBlitFramebuffer", srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }

inline void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) { CALLGL32_V(PFNGLSCISSORPROC, "glScissor", x, y, width, height); }

inline void glSampleCoverage(GLfloat value, GLboolean invert) { CALLGL32_V(PFNGLSAMPLECOVERAGEPROC, "glSampleCoverage", value, invert); }

inline void glSampleMaski(GLuint maskNumber, GLbitfield mask) { CALLGL32_V(PFNGLSAMPLEMASKIPROC, "glSampleMaski", maskNumber, mask); }

inline void glStencilFunc(GLenum func, GLint ref, GLuint mask) { CALLGL32_V(PFNGLSTENCILFUNCPROC, "glStencilFunc", func, ref, mask); }

inline void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { CALLGL32_V(PFNGLSTENCILFUNCSEPARATEPROC, "glStencilFuncSeparate", face, func, ref, mask); }

inline void glStencilOp(GLenum sfail, GLenum dpfail, GLenum dppass) { CALLGL32_V(PFNGLSTENCILOPPROC, "glStencilOp", sfail, dpfail, dppass); }

inline void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) { CALLGL32_V(PFNGLSTENCILOPSEPARATEPROC, "glStencilOpSeparate", face, sfail, dpfail, dppass); }

inline void glDepthFunc(GLenum func) { CALLGL32_V(PFNGLDEPTHFUNCPROC, "glDepthFunc", func); }

inline void glBlendEquation(GLenum mode) { CALLGL32_V(PFNGLBLENDEQUATIONPROC, "glBlendEquation", mode); }

inline void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { CALLGL32_V(PFNGLBLENDEQUATIONSEPARATEPROC, "glBlendEquationSeparate", modeRGB, modeAlpha); }

inline void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { CALLGL32_V(PFNGLBLENDFUNCSEPARATEPROC, "glBlendFuncSeparate", srcRGB, dstRGB, srcAlpha, dstAlpha); }

inline void glBlendFunc(GLenum sfactor, GLenum dfactor) { CALLGL32_V(PFNGLBLENDFUNCPROC, "glBlendFunc", sfactor, dfactor); }

inline void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { CALLGL32_V(PFNGLBLENDCOLORPROC, "glBlendColor", red, green, blue, alpha); }

inline void glLogicOp(GLenum opcode) { CALLGL32_V(PFNGLLOGICOPPROC, "glLogicOp", opcode); }

inline void glDrawBuffer(GLenum buf) { CALLGL32_V(PFNGLDRAWBUFFERPROC, "glDrawBuffer", buf); }

inline void glDrawBuffers(GLsizei n, const GLenum *bufs) { CALLGL32_V(PFNGLDRAWBUFFERSPROC, "glDrawBuffers", n, bufs); }

inline void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { CALLGL32_V(PFNGLCOLORMASKPROC, "glColorMask", red, green, blue, alpha); }

inline void glColorMaski(GLuint buf, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { CALLGL32_V(PFNGLCOLORMASKIPROC, "glColorMaski", buf, red, green, blue, alpha); }

inline void glDepthMask(GLboolean flag) { CALLGL32_V(PFNGLDEPTHMASKPROC, "glDepthMask", flag); }

inline void glStencilMask(GLuint mask) { CALLGL32_V(PFNGLSTENCILMASKPROC, "glStencilMask", mask); }

inline void glStencilMaskSeparate(GLenum face, GLuint mask) { CALLGL32_V(PFNGLSTENCILMASKSEPARATEPROC, "glStencilMaskSeparate", face, mask); }

inline void glClear(GLbitfield mask) { CALLGL32_V(PFNGLCLEARPROC, "glClear", mask); }

inline void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { CALLGL32_V(PFNGLCLEARCOLORPROC, "glClearColor", red, green, blue, alpha); }

inline void glClearDepth(GLdouble depth) { CALLGL32_V(PFNGLCLEARDEPTHPROC, "glClearDepth", depth); }

inline void glClearStencil(GLint s) { CALLGL32_V(PFNGLCLEARSTENCILPROC, "glClearStencil", s); }

inline void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint * value) { CALLGL32_V(PFNGLCLEARBUFFERIVPROC, "glClearBufferiv", buffer, drawbuffer, value); }

inline void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint * value) { CALLGL32_V(PFNGLCLEARBUFFERUIVPROC, "glClearBufferuiv", buffer, drawbuffer, value); }

inline void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat * value) { CALLGL32_V(PFNGLCLEARBUFFERFVPROC, "glClearBufferfv", buffer, drawbuffer, value); }

inline void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { CALLGL32_V(PFNGLCLEARBUFFERFIPROC, "glClearBufferfi", buffer, drawbuffer, depth, stencil); }

inline void glBindFramebuffer(GLenum target, GLuint framebuffer) { CALLGL32_V(PFNGLBINDFRAMEBUFFERPROC, "glBindFramebuffer", target, framebuffer); }

inline void glDeleteFramebuffers(GLsizei n, GLuint *framebuffers) { CALLGL32_V(PFNGLDELETEFRAMEBUFFERSPROC, "glDeleteFramebuffers", n, framebuffers); }

inline void glGenFramebuffers(GLsizei n, GLuint *ids) { CALLGL32_V(PFNGLGENFRAMEBUFFERSPROC, "glGenFramebuffers", n, ids); }

inline void glBindRenderbuffer(GLenum target, GLuint renderbuffer) { CALLGL32_V(PFNGLBINDRENDERBUFFERPROC, "glBindRenderbuffer", target, renderbuffer); }

inline void glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers) { CALLGL32_V(PFNGLDELETERENDERBUFFERSPROC, "glDeleteRenderbuffers", n, renderbuffers); }

inline void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) { CALLGL32_V(PFNGLGENRENDERBUFFERSPROC, "glGenRenderbuffers", n, renderbuffers); }

inline void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
	{ CALLGL32_V(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, "glRenderbufferStorageMultisample", target, samples, internalformat, width, height); }

inline void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
	{ CALLGL32_V(PFNGLRENDERBUFFERSTORAGEPROC, "glRenderbufferStorage", target, internalformat, width, height); }

inline void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
	{ CALLGL32_V(PFNGLFRAMEBUFFERRENDERBUFFERPROC, "glFramebufferRenderbuffer", target, attachment, renderbuffertarget, renderbuffer); }

inline void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) { CALLGL32_V(PFNGLFRAMEBUFFERTEXTUREPROC, "glFramebufferTexture", target, attachment, texture, level); }

inline void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
	{ CALLGL32_V(PFNGLFRAMEBUFFERTEXTURE1DPROC, "glFramebufferTexture1D", target, attachment, textarget, texture, level); }

inline void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
	{ CALLGL32_V(PFNGLFRAMEBUFFERTEXTURE2DPROC, "glFramebufferTexture2D", target, attachment, textarget, texture, level); }

inline void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint layer)
	{ CALLGL32_V(PFNGLFRAMEBUFFERTEXTURE3DPROC, "glFramebufferTexture3D", target, attachment, textarget, texture, level, layer); }

inline void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
	{ CALLGL32_V(PFNGLFRAMEBUFFERTEXTURELAYERPROC, "glFramebufferTextureLayer", target, attachment, texture, level, layer); }

inline GLenum glCheckFramebufferStatus(GLenum target) { R_CALLGL32_V(PFNGLCHECKFRAMEBUFFERSTATUSPROC, "glCheckFramebufferStatus", target); }

inline GLboolean glIsFramebuffer(GLuint framebuffer) { R_CALLGL32_V(PFNGLISFRAMEBUFFERPROC, "glIsFramebuffer", framebuffer); }

inline void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params)
	{ CALLGL32_V(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, "glGetFramebufferAttachmentParameteriv", target, attachment, pname, params); }

inline GLboolean glIsRenderbuffer(GLuint renderbuffer) { R_CALLGL32_V(PFNGLISRENDERBUFFERPROC, "glIsRenderbuffer", renderbuffer); }

inline void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) { CALLGL32_V(PFNGLGETRENDERBUFFERPARAMETERIVPROC, "glGetRenderbufferParameteriv", target, pname, params); }

inline void glFlush() { CALLGL32(PFNGLFLUSHPROC, "glFlush"); }

inline void glFinish() { CALLGL32(PFNGLFINISHPROC, "glFinish"); }

inline GLsync glFenceSync(GLenum condition, GLbitfield flags) { R_CALLGL32_V(PFNGLFENCESYNCPROC, "glFenceSync", condition, flags); }

inline void glDeleteSync(GLsync sync) { CALLGL32_V(PFNGLDELETESYNCPROC, "glDeleteSync", sync); }

inline GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { R_CALLGL32_V(PFNGLCLIENTWAITSYNCPROC, "glClientWaitSync", sync, flags, timeout); }

inline void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { CALLGL32_V(PFNGLWAITSYNCPROC, "glWaitSync", sync, flags, timeout); }

inline void glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) { CALLGL32_V(PFNGLGETSYNCIVPROC, "glGetSynciv", sync, pname, bufSize, length, values); }

inline GLboolean glIsSync(GLsync sync) { R_CALLGL32_V(PFNGLISSYNCPROC, "glIsSync", sync); }

inline void glGetBooleanv(GLenum pname, GLboolean * data) { CALLGL32_V(PFNGLGETBOOLEANVPROC, "glGetBooleanv", pname, data); }

inline void glGetDoublev(GLenum pname, GLdouble * data) { CALLGL32_V(PFNGLGETDOUBLEVPROC, "glGetDoublev", pname, data); }

inline void glGetFloatv(GLenum pname, GLfloat * data) { CALLGL32_V(PFNGLGETFLOATVPROC, "glGetFloatv", pname, data); }

inline void glGetIntegerv(GLenum pname, GLint * data) { CALLGL32_V(PFNGLGETINTEGERVPROC, "glGetIntegerv", pname, data); }

inline void glGetInteger64v(GLenum pname, GLint64 * data) { CALLGL32_V(PFNGLGETINTEGER64VPROC, "glGetInteger64v", pname, data); }

inline void glGetBooleani_v(GLenum target, GLuint index, GLboolean * data) { CALLGL32_V(PFNGLGETBOOLEANI_VPROC, "glGetBooleani_v", target, index, data); }

inline void glGetIntegeri_v(GLenum target, GLuint index, GLint * data) { CALLGL32_V(PFNGLGETINTEGERI_VPROC, "glGetIntegeri_v", target, index, data); }

inline void glGetInteger64i_v(GLenum target, GLuint index, GLint64 * data) { CALLGL32_V(PFNGLGETINTEGER64I_VPROC, "glGetInteger64i_v", target, index, data); }

inline GLboolean glIsEnabled(GLenum cap) { R_CALLGL32_V(PFNGLISENABLEDPROC, "glIsEnabled", cap); }

inline GLboolean glIsEnabledi(GLenum cap, GLuint index) { R_CALLGL32_V(PFNGLISENABLEDIPROC, "glIsEnabledi", cap, index); }

inline const GLubyte *glGetString(GLenum name) { R_CALLGL32_V(PFNGLGETSTRINGPROC, "glGetString", name); }

inline const GLubyte *glGetStringi(GLenum name, GLuint index) { R_CALLGL32_V(PFNGLGETSTRINGIPROC, "glGetStringi", name, index); }

inline void glQueryCounter(GLuint id, GLenum target) { CALLGL32_V(PFNGLQUERYCOUNTERPROC, "glQueryCounter", id, target); }

inline void glGenSamplers(GLsizei n, GLuint *samplers) { CALLGL32_V(PFNGLGENSAMPLERSPROC, "glGenSamplers", n, samplers); }

inline void glBindSampler(GLuint unit, GLuint sampler) { CALLGL32_V(PFNGLBINDSAMPLERPROC, "glBindSampler", unit, sampler); }

inline void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) { CALLGL32_V(PFNGLSAMPLERPARAMETERFPROC, "glSamplerParameterf", sampler, pname, param); }

inline void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) { CALLGL32_V(PFNGLSAMPLERPARAMETERIPROC, "glSamplerParameteri", sampler, pname, param); }

inline void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat * params) { CALLGL32_V(PFNGLSAMPLERPARAMETERFVPROC, "glSamplerParameterfv", sampler, pname, params); }

inline void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint * params) { CALLGL32_V(PFNGLSAMPLERPARAMETERIVPROC, "glSamplerParameteriv", sampler, pname, params); }

inline void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *params) { CALLGL32_V(PFNGLSAMPLERPARAMETERIIVPROC, "glSamplerParameteriv", sampler, pname, params); }

inline void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *params) { CALLGL32_V(PFNGLSAMPLERPARAMETERIUIVPROC, "glSamplerParameterIuiv", sampler, pname, params); }

inline void glDeleteSamplers(GLsizei n, const GLuint * samplers) { CALLGL32_V(PFNGLDELETESAMPLERSPROC, "glDeleteSamplers", n, samplers); }

inline GLboolean glIsSampler(GLuint id) { R_CALLGL32_V(PFNGLISSAMPLERPROC, "glIsSampler", id); }

inline void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params) { CALLGL32_V(PFNGLGETSAMPLERPARAMETERFVPROC, "glGetSamplerParameterfv", sampler, pname, params); }

inline void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params) { CALLGL32_V(PFNGLGETSAMPLERPARAMETERIVPROC, "glGetSamplerParameteriv", sampler, pname, params); }

inline void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params) { CALLGL32_V(PFNGLGETSAMPLERPARAMETERIIVPROC, "glGetSamplerParameterIiv", sampler, pname, params); }

inline void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params) { CALLGL32_V(PFNGLGETSAMPLERPARAMETERIUIVPROC, "glGetSamplerParameterIuiv", sampler, pname, params); }

inline void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name)
	{ CALLGL32_V(PFNGLBINDFRAGDATALOCATIONINDEXEDPROC, "glBindFragDataLocationIndexed", program, colorNumber, index, name); }

inline GLint glGetFragDataIndex(GLuint program, const GLchar * name) { R_CALLGL32_V(PFNGLGETFRAGDATAINDEXPROC, "glGetFragDataIndex", program, name); }
