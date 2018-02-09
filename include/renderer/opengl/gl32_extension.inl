inline GLenum glGetError() { CALLGL32(PFNGLGETERRORPROC, "glGetError"); }

inline void glVertexAttrib1f(GLuint index, GLfloat v0) { CALLGL32(PFNGLVERTEXATTRIB1FPROC, "glVertexAttrib1f", index, v0); }

inline void glVertexAttrib1s(GLuint index, GLshort v0) { CALLGL32(PFNGLVERTEXATTRIB1SPROC, "glVertexAttrib1s", index, v0); }

inline void glVertexAttrib1d(GLuint index, GLdouble v0) { CALLGL32(PFNGLVERTEXATTRIB1DPROC, "glVertexAttrib1d", index, v0); }

inline void glVertexAttribI1i(GLuint index, GLint v0) { CALLGL32(PFNGLVERTEXATTRIBI1IPROC, "glVertexAttribI1i", index, v0); }

inline void glVertexAttribI1ui(GLuint index, GLuint v0) { CALLGL32(PFNGLVERTEXATTRIBI1UIPROC, "glVertexAttribI1ui", index, v0); }

inline void glVertexAttrib2f(GLuint index, GLfloat v0, GLfloat v1) { CALLGL32(PFNGLVERTEXATTRIB2FPROC, "glVertexAttrib2f", index, v0, v1); }

inline void glVertexAttrib2s(GLuint index, GLshort v0, GLshort v1) { CALLGL32(PFNGLVERTEXATTRIB2SPROC, "glVertexAttrib2s", index, v0, v1); }

inline void glVertexAttrib2d(GLuint index, GLdouble v0, GLdouble v1) { CALLGL32(PFNGLVERTEXATTRIB2DPROC, "glVertexAttrib2d", index, v0, v1); }

inline void glVertexAttribI2i(GLuint index, GLint v0, GLint v1) { CALLGL32(PFNGLVERTEXATTRIBI2IPROC, "glVertexAttribI2i", index, v0, v1); }

inline void glVertexAttribI2ui(GLuint index, GLuint v0, GLuint v1) { CALLGL32(PFNGLVERTEXATTRIBI2UIPROC, "glVertexAttribI2ui", index, v0, v1); }

inline void glVertexAttrib3f(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2) { CALLGL32(PFNGLVERTEXATTRIB3FPROC, "glVertexAttrib3f", index, v0, v1, v2); }

inline void glVertexAttrib3s(GLuint index, GLshort v0, GLshort v1, GLshort v2) { CALLGL32(PFNGLVERTEXATTRIB3SPROC, "glVertexAttrib3s", index, v0, v1, v2); }

inline void glVertexAttrib3d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2) { CALLGL32(PFNGLVERTEXATTRIB3DPROC, "glVertexAttrib3d", index, v0, v1, v2); }

inline void glVertexAttribI3i(GLuint index, GLint v0, GLint v1, GLint v2) { CALLGL32(PFNGLVERTEXATTRIBI3IPROC, "glVertexAttribI3i", index, v0, v1, v2); }

inline void glVertexAttribI3ui(GLuint index, GLuint v0, GLuint v1, GLuint v2) { CALLGL32(PFNGLVERTEXATTRIBI3UIPROC, "glVertexAttribI3ui", index, v0, v1, v2); }

inline void glVertexAttrib4f(GLuint index, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { CALLGL32(PFNGLVERTEXATTRIB4FPROC, "glVertexAttrib4f", index, v0, v1, v2, v3); }

inline void glVertexAttrib4s(GLuint index, GLshort v0, GLshort v1, GLshort v2, GLshort v3) { CALLGL32(PFNGLVERTEXATTRIB4SPROC, "glVertexAttrib4s", index, v0, v1, v2, v3); }

inline void glVertexAttrib4d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) { CALLGL32(PFNGLVERTEXATTRIB4DPROC, "glVertexAttrib4d", index, v0, v1, v2, v3); }

inline void glVertexAttrib4Nub(GLuint index, GLubyte v0, GLubyte v1, GLubyte v2, GLubyte v3) { CALLGL32(PFNGLVERTEXATTRIB4NUBPROC, "glVertexAttrib4Nub", index, v0, v1, v2, v3); }

inline void glVertexAttribI4i(GLuint index, GLint v0, GLint v1, GLint v2, GLint v3) { CALLGL32(PFNGLVERTEXATTRIBI4IPROC, "glVertexAttribI4i", index, v0, v1, v2, v3); }

inline void glVertexAttribI4ui(GLuint index, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { CALLGL32(PFNGLVERTEXATTRIBI4UIPROC, "glVertexAttribI4ui", index, v0, v1, v2, v3); }

inline void glVertexAttrib1fv(GLuint index, const GLfloat *v) { CALLGL32(PFNGLVERTEXATTRIB1FVPROC, "glVertexAttrib1fv", index, v); }

inline void glVertexAttrib1sv(GLuint index, const GLshort *v) { CALLGL32(PFNGLVERTEXATTRIB1SVPROC, "glVertexAttrib1sv", index, v); }

inline void glVertexAttrib1dv(GLuint index, const GLdouble *v) { CALLGL32(PFNGLVERTEXATTRIB1DVPROC, "glVertexAttrib1dv", index, v); }

inline void glVertexAttribI1iv(GLuint index, const GLint *v) { CALLGL32(PFNGLVERTEXATTRIBI1IVPROC, "glVertexAttribI1iv", index, v); }

inline void glVertexAttribI1uiv(GLuint index, const GLuint *v) { CALLGL32(PFNGLVERTEXATTRIBI1UIVPROC, "glVertexAttribI1uiv", index, v); }

inline void glVertexAttrib2fv(GLuint index, const GLfloat *v) { CALLGL32(PFNGLVERTEXATTRIB2FVPROC, "glVertexAttrib2fv", index, v); }

inline void glVertexAttrib2sv(GLuint index, const GLshort *v) { CALLGL32(PFNGLVERTEXATTRIB2SVPROC, "glVertexAttrib2sv", index, v); }

inline void glVertexAttrib2dv(GLuint index, const GLdouble *v) { CALLGL32(PFNGLVERTEXATTRIB2DVPROC, "glVertexAttrib2dv", index, v); }

inline void glVertexAttribI2iv(GLuint index, const GLint *v) { CALLGL32(PFNGLVERTEXATTRIBI2IVPROC, "glVertexAttribI2iv", index, v); }

inline void glVertexAttribI2uiv(GLuint index, const GLuint *v) { CALLGL32(PFNGLVERTEXATTRIBI2UIVPROC, "glVertexAttribI2uiv", index, v); }

inline void glVertexAttrib3fv(GLuint index, const GLfloat *v) { CALLGL32(PFNGLVERTEXATTRIB3FVPROC, "glVertexAttrib3fv", index, v); }

inline void glVertexAttrib3sv(GLuint index, const GLshort *v) { CALLGL32(PFNGLVERTEXATTRIB3SVPROC, "glVertexAttrib3sv", index, v); }

inline void glVertexAttrib3dv(GLuint index, const GLdouble *v) { CALLGL32(PFNGLVERTEXATTRIB3DVPROC, "glVertexAttrib3dv", index, v); }

inline void glVertexAttribI3iv(GLuint index, const GLint *v) { CALLGL32(PFNGLVERTEXATTRIBI3IVPROC, "glVertexAttribI3iv", index, v); }

inline void glVertexAttribI3uiv(GLuint index, const GLuint *v) { CALLGL32(PFNGLVERTEXATTRIBI3UIVPROC, "glVertexAttribI3uiv", index, v); }

inline void glVertexAttrib4fv(GLuint index, const GLfloat *v) { CALLGL32(PFNGLVERTEXATTRIB4FVPROC, "glVertexAttrib4fv", index, v); }

inline void glVertexAttrib4sv(GLuint index, const GLshort *v) { CALLGL32(PFNGLVERTEXATTRIB4SVPROC, "glVertexAttrib4sv", index, v); }

inline void glVertexAttrib4dv(GLuint index, const GLdouble *v) { CALLGL32(PFNGLVERTEXATTRIB4DVPROC, "glVertexAttrib4dv", index, v); }

inline void glVertexAttrib4iv(GLuint index, const GLint *v) { CALLGL32(PFNGLVERTEXATTRIB4IVPROC, "glVertexAttrib4iv", index, v); }

inline void glVertexAttrib4bv(GLuint index, const GLbyte *v) { CALLGL32(PFNGLVERTEXATTRIB4BVPROC, "glVertexAttrib4bv", index, v); }

inline void glVertexAttrib4ubv(GLuint index, const GLubyte *v) { CALLGL32(PFNGLVERTEXATTRIB4UBVPROC, "glVertexAttrib4ubv", index, v); }

inline void glVertexAttrib4usv(GLuint index, const GLushort *v) { CALLGL32(PFNGLVERTEXATTRIB4USVPROC, "glVertexAttrib4usv", index, v); }

inline void glVertexAttrib4uiv(GLuint index, const GLuint *v) { CALLGL32(PFNGLVERTEXATTRIB4UIVPROC, "glVertexAttrib4uiv", index, v); }

inline void glVertexAttrib4Nbv(GLuint index, const GLbyte *v) { CALLGL32(PFNGLVERTEXATTRIB4NBVPROC, "glVertexAttrib4Nbv", index, v); }

inline void glVertexAttrib4Nsv(GLuint index, const GLshort *v) { CALLGL32(PFNGLVERTEXATTRIB4NSVPROC, "glVertexAttrib4Nsv", index, v); }

inline void glVertexAttrib4Niv(GLuint index, const GLint *v) { CALLGL32(PFNGLVERTEXATTRIB4NIVPROC, "glVertexAttrib4Niv", index, v); }

inline void glVertexAttrib4Nubv(GLuint index, const GLubyte *v) { CALLGL32(PFNGLVERTEXATTRIB4NUBVPROC, "glVertexAttrib4Nubv", index, v); }

inline void glVertexAttrib4Nusv(GLuint index, const GLushort *v) { CALLGL32(PFNGLVERTEXATTRIB4NUSVPROC, "glVertexAttrib4Nusv", index, v); }

inline void glVertexAttrib4Nuiv(GLuint index, const GLuint *v) { CALLGL32(PFNGLVERTEXATTRIB4NUIVPROC, "glVertexAttrib4Nuiv", index, v); }

inline void glVertexAttribI4bv(GLuint index, const GLbyte *v) { CALLGL32(PFNGLVERTEXATTRIBI4BVPROC, "glVertexAttribI4bv", index, v); }

inline void glVertexAttribI4ubv(GLuint index, const GLubyte *v) { CALLGL32(PFNGLVERTEXATTRIBI4UBVPROC, "glVertexAttribI4ubv", index, v); }

inline void glVertexAttribI4sv(GLuint index, const GLshort *v) { CALLGL32(PFNGLVERTEXATTRIBI4SVPROC, "glVertexAttribI4sv", index, v); }

inline void glVertexAttribI4usv(GLuint index, const GLushort * v) { CALLGL32(PFNGLVERTEXATTRIBI4USVPROC, "glVertexAttribI4usv", index, v); }

inline void glVertexAttribI4iv(GLuint index, const GLint * v) { CALLGL32(PFNGLVERTEXATTRIBI4IVPROC, "glVertexAttribI4iv", index, v); }

inline void glVertexAttribI4uiv(GLuint index, const GLuint * v) { CALLGL32(PFNGLVERTEXATTRIBI4UIVPROC, "glVertexAttribI4uiv", index, v); }

inline void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { CALLGL32(PFNGLVERTEXATTRIBP1UIPROC, "glVertexAttribP1ui", index, type, normalized, value); }

inline void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { CALLGL32(PFNGLVERTEXATTRIBP2UIPROC, "glVertexAttribP2ui", index, type, normalized, value); }

inline void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { CALLGL32(PFNGLVERTEXATTRIBP3UIPROC, "glVertexAttribP3ui", index, type, normalized, value); }

inline void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { CALLGL32(PFNGLVERTEXATTRIBP4UIPROC, "glVertexAttribP4ui", index, type, normalized, value); }

inline void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer)
	{ CALLGL32(PFNGLVERTEXATTRIBPOINTERPROC, "glVertexAttribPointer", index, size, type, normalized, stride, pointer); }

inline void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
	{ CALLGL32(PFNGLVERTEXATTRIBIPOINTERPROC, "glVertexAttribIPointer", index, size, type, stride, pointer); }

inline void glEnableVertexAttribArray(GLuint index) { CALLGL32(PFNGLENABLEVERTEXATTRIBARRAYPROC, "glEnableVertexAttribArray", index); }

inline void glDisableVertexAttribArray(GLuint index) { CALLGL32(PFNGLDISABLEVERTEXATTRIBARRAYPROC, "glDisableVertexAttribArray", index); }

inline void glEnable(GLenum cap) { CALLGL32(PFNGLENABLEPROC, "glEnable", cap); }

inline void glDisable(GLenum cap) { CALLGL32(PFNGLDISABLEPROC, "glDisable", cap); }

inline void glEnablei(GLenum cap, GLuint index) { CALLGL32(PFNGLENABLEIPROC, "glEnablei", cap, index); }

inline void glDisablei(GLenum cap, GLuint index) { CALLGL32(PFNGLDISABLEIPROC, "glDisablei", cap, index); }

inline void glPrimitiveRestartIndex(GLuint index) { CALLGL32(PFNGLPRIMITIVERESTARTINDEXPROC, "glPrimitiveRestartIndex", index); }

inline void glDrawArrays(GLenum mode, GLint first, GLsizei count) { CALLGL32(PFNGLDRAWARRAYSPROC, "glDrawArrays", mode, first, count); }

inline void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) { CALLGL32(PFNGLMULTIDRAWARRAYSPROC, "glMultiDrawArrays", mode, first, count, drawcount); }

inline void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) { CALLGL32(PFNGLDRAWELEMENTSPROC, "glDrawElements", mode, count, type, indices); }

inline void glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const GLvoid * const * indices, GLsizei drawcount)
	{ CALLGL32(PFNGLMULTIDRAWELEMENTSPROC, "glMultiDrawElements", mode, count, type, indices, drawcount); }

inline void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices)
	{ CALLGL32(PFNGLDRAWRANGEELEMENTSPROC, "glDrawRangeElements", mode, start, end, count, type, indices); }

inline void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount) { CALLGL32(PFNGLDRAWARRAYSINSTANCEDPROC, "glDrawArraysInstanced", mode, first, count, primcount); }

inline void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices, GLsizei primcount)
	{ CALLGL32(PFNGLDRAWELEMENTSINSTANCEDPROC, "glDrawElementsInstanced", mode, count, type, indices, primcount); }

inline void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLint basevertex)
	{ CALLGL32(PFNGLDRAWELEMENTSBASEVERTEXPROC, "glDrawElementsBaseVertex", mode, count, type, indices, basevertex); }

inline void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid * indices, GLint basevertex)
	{ CALLGL32(PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC, "glDrawRangeElementsBaseVertex", mode, start, end, count, type, indices, basevertex); }

inline void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLsizei primcount, GLint basevertex)
	{ CALLGL32(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC, "glDrawElementsInstancedBaseVertex", mode, count, type, indices, primcount, basevertex); }

inline void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei * count, GLenum type, const GLvoid * const * indices, GLsizei drawcount, const GLint * basevertex)
	{ CALLGL32(PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC, "glMultiDrawElementsBaseVertex", mode, count, type, indices, drawcount, basevertex); }

inline void glGenBuffers(GLsizei n, GLuint * buffers) { CALLGL32(PFNGLGENBUFFERSPROC, "glGenBuffers", n, buffers); }

inline void glDeleteBuffers(GLsizei n, const GLuint * buffers) { CALLGL32(PFNGLDELETEBUFFERSPROC, "glDeleteBuffers", n, buffers); }

inline void glBindBuffer(GLenum target, GLuint buffer) { CALLGL32(PFNGLBINDBUFFERPROC, "glBindBuffer", target, buffer); }

inline void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
	{ CALLGL32(PFNGLBINDBUFFERRANGEPROC, "glBindBufferRange", target, index, buffer, offset, size); }

inline void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) { CALLGL32(PFNGLBINDBUFFERBASEPROC, "glBindBufferBase", target, index, buffer); }

inline void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) { CALLGL32(PFNGLBUFFERDATAPROC, "glBufferData", target, size, data, usage); }

inline void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) { CALLGL32(PFNGLBUFFERSUBDATAPROC, "glBufferSubData", target, offset, size, data); }

inline void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) { CALLGL32(PFNGLMAPBUFFERRANGEPROC, "glMapBufferRange", target, offset, length, access); }

inline void * glMapBuffer(GLenum target, GLenum access) { CALLGL32(PFNGLMAPBUFFERPROC, "glMapBuffer", target, access); }

inline void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) { CALLGL32(PFNGLFLUSHMAPPEDBUFFERRANGEPROC, "glFlushMappedBufferRange", target, offset, length); }

inline GLboolean glUnmapBuffer(GLenum target) { CALLGL32(PFNGLUNMAPBUFFERPROC, "glUnmapBuffer", target); }

inline void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
	{ CALLGL32(PFNGLCOPYBUFFERSUBDATAPROC, "glCopyBufferSubData", readTarget, writeTarget, readOffset, writeOffset, size); }

inline void glGenVertexArrays(GLsizei n, GLuint *arrays) { CALLGL32(PFNGLGENVERTEXARRAYSPROC, "glGenVertexArrays", n, arrays); }

inline void glDeleteVertexArrays(GLsizei n, const GLuint *arrays) { CALLGL32(PFNGLDELETEVERTEXARRAYSPROC, "glDeleteVertexArrays", n, arrays); }

inline void glBindVertexArray(GLuint array) { CALLGL32(PFNGLBINDVERTEXARRAYPROC, "glBindVertexArray", array); }

inline GLboolean glIsBuffer(GLuint buffer) { CALLGL32(PFNGLISBUFFERPROC, "glIsBuffer", buffer); }

inline void glGetBufferParameteriv(GLenum target, GLenum value, GLint * data) { CALLGL32(PFNGLGETBUFFERPARAMETERIVPROC, "glGetBufferParameteriv", target, value, data); }

inline void glGetBufferParameteri64v(GLenum target, GLenum value, GLint64 * data) { CALLGL32(PFNGLGETBUFFERPARAMETERI64VPROC, "glGetBufferParameteri64v", target, value, data); }

inline void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) { CALLGL32(PFNGLGETBUFFERSUBDATAPROC, "glGetBufferSubData", target, offset, size, data); }

inline void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params) { CALLGL32(PFNGLGETBUFFERPOINTERVPROC, "glGetBufferPointerv", target, pname, params); }

inline GLboolean glIsVertexArray(GLuint array) { CALLGL32(PFNGLISVERTEXARRAYPROC, "glIsVertexArray", array); }

inline void glDepthRange(GLdouble nearVal, GLdouble farVal) { CALLGL32(PFNGLDEPTHRANGEPROC, "glDepthRange", nearVal, farVal); }

inline void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) { CALLGL32(PFNGLVIEWPORTPROC, "glViewport", x, y, width, height); }

inline void glClampColor(GLenum target, GLenum clamp) { CALLGL32(PFNGLCLAMPCOLORPROC, "glClampColor", target, clamp); }

inline void glProvokingVertex(GLenum provokeMode) { CALLGL32(PFNGLPROVOKINGVERTEXPROC, "glProvokingVertex", provokeMode); }

inline void glBeginConditionalRender(GLuint id, GLenum mode) { CALLGL32(PFNGLBEGINCONDITIONALRENDERPROC, "glBeginConditionalRender", id, mode); }

inline void glEndConditionalRender() { CALLGL32(PFNGLENDCONDITIONALRENDERPROC, "glEndConditionalRender"); }

inline void glBeginTransformFeedback(GLenum primitiveMode) { CALLGL32(PFNGLBEGINTRANSFORMFEEDBACKPROC, "glBeginTransformFeedback", primitiveMode); }

inline void glEndTransformFeedback() { CALLGL32(PFNGLENDTRANSFORMFEEDBACKPROC, "glEndTransformFeedback"); }

inline void glBeginQuery(GLenum target, GLuint id) { CALLGL32(PFNGLBEGINQUERYPROC, "glBeginQuery", target, id); }

inline void glEndQuery(GLenum target) { CALLGL32(PFNGLENDQUERYPROC, "glEndQuery", target); }

inline void glGenQueries(GLsizei n, GLuint * ids) { CALLGL32(PFNGLGENQUERIESPROC, "glGenQueries", n, ids); }

inline void glDeleteQueries(GLsizei n, const GLuint * ids) { CALLGL32(PFNGLDELETEQUERIESPROC, "glDeleteQueries", n, ids); }

inline GLboolean glIsQuery(GLuint id) { CALLGL32(PFNGLISQUERYPROC, "glIsQuery", id); }

inline void glGetQueryiv(GLenum target, GLenum pname, GLint * params) { CALLGL32(PFNGLGETQUERYIVPROC, "glGetQueryiv", target, pname, params); }

inline void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) { CALLGL32(PFNGLGETQUERYOBJECTIVPROC, "glGetQueryObjectiv", id, pname, params); }

inline void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) { CALLGL32(PFNGLGETQUERYOBJECTUIVPROC, "glGetQueryObjectuiv", id, pname, params); }

inline void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params) { CALLGL32(PFNGLGETQUERYOBJECTI64VPROC, "glGetQueryObjecti64v", id, pname, params); }

inline void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params) { CALLGL32(PFNGLGETQUERYOBJECTUI64VPROC, "glGetQueryObjectui64v", id, pname, params); }

inline GLuint glCreateShader(GLenum shaderType) { CALLGL32(PFNGLCREATESHADERPROC, "glCreateShader", shaderType); }

inline void glShaderSource(GLuint shader, GLsizei count, const GLchar **string, const GLint *length) { CALLGL32(PFNGLSHADERSOURCEPROC, "glShaderSource", shader, count, string, length); }

inline void glCompileShader(GLuint shader) { CALLGL32(PFNGLCOMPILESHADERPROC, "glCompileShader", shader); }

inline void glDeleteShader(GLuint shader) { CALLGL32(PFNGLDELETESHADERPROC, "glDeleteShader", shader); }

inline GLuint glCreateProgram() { CALLGL32(PFNGLCREATEPROGRAMPROC, "glCreateProgram"); }

inline void glAttachShader(GLuint program, GLuint shader) { CALLGL32(PFNGLATTACHSHADERPROC, "glAttachShader", program, shader); }

inline void glDetachShader(GLuint program, GLuint shader) { CALLGL32(PFNGLDETACHSHADERPROC, "glDetachShader", program, shader); }

inline void glLinkProgram(GLuint program) { CALLGL32(PFNGLLINKPROGRAMPROC, "glLinkProgram", program); }

inline void glUseProgram(GLuint program) { CALLGL32(PFNGLUSEPROGRAMPROC, "glUseProgram", program); }

inline void glDeleteProgram(GLuint program) { CALLGL32(PFNGLDELETEPROGRAMPROC, "glDeleteProgram", program); }

inline void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
	{ CALLGL32(PFNGLGETACTIVEATTRIBPROC, "glGetActiveAttrib", program, index, bufSize, length, size, type, name); }

inline GLint glGetAttribLocation(GLuint program, const GLchar *name) { CALLGL32(PFNGLGETATTRIBLOCATIONPROC, "glGetAttribLocation", program, name); }

inline void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) { CALLGL32(PFNGLBINDATTRIBLOCATIONPROC, "glBindAttribLocation", program, index, name); }

inline GLint glGetUniformLocation(GLuint program, const GLchar *name) { CALLGL32(PFNGLGETUNIFORMLOCATIONPROC, "glGetUniformLocation", program, name); }

inline GLuint glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) { CALLGL32(PFNGLGETUNIFORMBLOCKINDEXPROC, "glGetUniformBlockIndex", program, uniformBlockName); }

inline void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName)
	{ CALLGL32(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC, "glGetActiveUniformBlockName", program, uniformBlockIndex, bufSize, length, uniformBlockName); }

inline void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params)
	{ CALLGL32(PFNGLGETACTIVEUNIFORMBLOCKIVPROC, "glGetActiveUniformBlockiv", program, uniformBlockIndex, pname, params); }

inline void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar **uniformNames, GLuint *uniformIndices)
	{ CALLGL32(PFNGLGETUNIFORMINDICESPROC, "glGetUniformIndices", program, uniformCount, uniformNames, uniformIndices); }

inline void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName)
	{ CALLGL32(PFNGLGETACTIVEUNIFORMNAMEPROC, "glGetActiveUniformName", program, uniformIndex, bufSize, length, uniformName); }

inline void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
	{ CALLGL32(PFNGLGETACTIVEUNIFORMPROC, "glGetActiveUniform", program, index, bufSize, length, size, type, name); }

inline void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params)
	{ CALLGL32(PFNGLGETACTIVEUNIFORMSIVPROC, "glGetActiveUniformsiv", program, uniformCount, uniformIndices, pname, params); }

inline void glUniform1f(GLint location, GLfloat v0) { CALLGL32(PFNGLUNIFORM1FPROC, "glUniform1f", location, v0); }

inline void glUniform2f(GLint location, GLfloat v0, GLfloat v1) { CALLGL32(PFNGLUNIFORM2FPROC, "glUniform2f", location, v0, v1); }

inline void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { CALLGL32(PFNGLUNIFORM3FPROC, "glUniform3f", location, v0, v1, v2); }

inline void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { CALLGL32(PFNGLUNIFORM4FPROC, "glUniform4f", location, v0, v1, v2, v3); }

inline void glUniform1i(GLint location, GLint v0) { CALLGL32(PFNGLUNIFORM1IPROC, "glUniform1i", location, v0); }

inline void glUniform2i(GLint location, GLint v0, GLint v1) { CALLGL32(PFNGLUNIFORM2IPROC, "glUniform2i", location, v0, v1); }

inline void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) { CALLGL32(PFNGLUNIFORM3IPROC, "glUniform3i", location, v0, v1, v2); }

inline void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { CALLGL32(PFNGLUNIFORM4IPROC, "glUniform4i", location, v0, v1, v2, v3); }

inline void glUniform1ui(GLint location, GLuint v0) { CALLGL32(PFNGLUNIFORM1UIPROC, "glUniform1ui", location, v0); }

inline void glUniform2ui(GLint location, GLuint v0, GLuint v1) { CALLGL32(PFNGLUNIFORM2UIPROC, "glUniform2ui", location, v0, v1); }

inline void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) { CALLGL32(PFNGLUNIFORM3UIPROC, "glUniform3ui", location, v0, v1, v2); }

inline void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { CALLGL32(PFNGLUNIFORM4UIPROC, "glUniform4ui", location, v0, v1, v2, v3); }

inline void glUniform1fv(GLint location, GLsizei count, const GLfloat *value) { CALLGL32(PFNGLUNIFORM1FVPROC, "glUniform1fv", location, count, value); }

inline void glUniform2fv(GLint location, GLsizei count, const GLfloat *value) { CALLGL32(PFNGLUNIFORM2FVPROC, "glUniform2fv", location, count, value); }

inline void glUniform3fv(GLint location, GLsizei count, const GLfloat *value) { CALLGL32(PFNGLUNIFORM3FVPROC, "glUniform3fv", location, count, value); }

inline void glUniform4fv(GLint location, GLsizei count, const GLfloat *value) { CALLGL32(PFNGLUNIFORM4FVPROC, "glUniform4fv", location, count, value); }

inline void glUniform1iv(GLint location, GLsizei count, const GLint *value) { CALLGL32(PFNGLUNIFORM1IVPROC, "glUniform1iv", location, count, value); }

inline void glUniform2iv(GLint location, GLsizei count, const GLint *value) { CALLGL32(PFNGLUNIFORM2IVPROC, "glUniform2iv", location, count, value); }

inline void glUniform3iv(GLint location, GLsizei count, const GLint *value) { CALLGL32(PFNGLUNIFORM3IVPROC, "glUniform3iv", location, count, value); }

inline void glUniform4iv(GLint location, GLsizei count, const GLint *value) { CALLGL32(PFNGLUNIFORM4IVPROC, "glUniform4iv", location, count, value); }

inline void glUniform1uiv(GLint location, GLsizei count, const GLuint *value) { CALLGL32(PFNGLUNIFORM1UIVPROC, "glUniform1uiv", location, count, value); }

inline void glUniform2uiv(GLint location, GLsizei count, const GLuint *value) { CALLGL32(PFNGLUNIFORM2UIVPROC, "glUniform2uiv", location, count, value); }

inline void glUniform3uiv(GLint location, GLsizei count, const GLuint *value) { CALLGL32(PFNGLUNIFORM3UIVPROC, "glUniform3uiv", location, count, value); }

inline void glUniform4uiv(GLint location, GLsizei count, const GLuint *value) { CALLGL32(PFNGLUNIFORM4UIVPROC, "glUniform4uiv", location, count, value); }

inline void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { CALLGL32(PFNGLUNIFORMMATRIX2FVPROC, "glUniformMatrix2fv", location, count, transpose, value); }

inline void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { CALLGL32(PFNGLUNIFORMMATRIX3FVPROC, "glUniformMatrix3fv", location, count, transpose, value); }

inline void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { CALLGL32(PFNGLUNIFORMMATRIX4FVPROC, "glUniformMatrix4fv", location, count, transpose, value); }

inline void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL32(PFNGLUNIFORMMATRIX2X3FVPROC, "glUniformMatrix2x3fv", location, count, transpose, value); }

inline void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL32(PFNGLUNIFORMMATRIX3X2FVPROC, "glUniformMatrix3x2fv", location, count, transpose, value); }

inline void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL32(PFNGLUNIFORMMATRIX2X4FVPROC, "glUniformMatrix2x4fv", location, count, transpose, value); }

inline void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL32(PFNGLUNIFORMMATRIX4X2FVPROC, "glUniformMatrix4x2fv", location, count, transpose, value); }

inline void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL32(PFNGLUNIFORMMATRIX3X4FVPROC, "glUniformMatrix3x4fv", location, count, transpose, value); }

inline void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL32(PFNGLUNIFORMMATRIX4X3FVPROC, "glUniformMatrix4x3fv", location, count, transpose, value); }

inline void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
	{ CALLGL32(PFNGLUNIFORMBLOCKBINDINGPROC, "glUniformBlockBinding", program, uniformBlockIndex, uniformBlockBinding); }

inline void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar **varyings, GLenum bufferMode)
	{ CALLGL32(PFNGLTRANSFORMFEEDBACKVARYINGSPROC, "glTransformFeedbackVaryings", program, count, varyings, bufferMode); }

inline void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)
	{ CALLGL32(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC, "glGetTransformFeedbackVarying", program, index, bufSize, length, size, type, name); }

inline void glValidateProgram(GLuint program) { CALLGL32(PFNGLVALIDATEPROGRAMPROC, "glValidateProgram", program); }

inline void glGetProgramiv(GLuint program, GLenum pname, GLint *params) { CALLGL32(PFNGLGETPROGRAMIVPROC, "glGetProgramiv", program, pname, params); }

inline void glBindFragDataLocation(GLuint program, GLuint colorNumber, const GLchar * name) { CALLGL32(PFNGLBINDFRAGDATALOCATIONPROC, "glBindFragDataLocation", program, colorNumber, name); }

inline GLint glGetFragDataLocation(GLuint program, const GLchar * name) { CALLGL32(PFNGLGETFRAGDATALOCATIONPROC, "glGetFragDataLocation", program, name); }

inline GLboolean glIsShader(GLuint shader) { CALLGL32(PFNGLISSHADERPROC, "glIsShader", shader); }

inline void glGetShaderiv(GLuint shader, GLenum pname, GLint *params) { CALLGL32(PFNGLGETSHADERIVPROC, "glGetShaderiv", shader, pname, params); }

inline void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) { CALLGL32(PFNGLGETATTACHEDSHADERSPROC, "glGetAttachedShaders", program, maxCount, count, shaders); }

inline void glGetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog) { CALLGL32(PFNGLGETSHADERINFOLOGPROC, "glGetShaderInfoLog", shader, maxLength, length, infoLog); }

inline void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) { CALLGL32(PFNGLGETSHADERSOURCEPROC, "glGetShaderSource", shader, bufSize, length, source); }

inline void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params) { CALLGL32(PFNGLGETVERTEXATTRIBDVPROC, "glGetVertexAttribdv", index, pname, params); }

inline void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) { CALLGL32(PFNGLGETVERTEXATTRIBFVPROC, "glGetVertexAttribfv", index, pname, params); }

inline void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) { CALLGL32(PFNGLGETVERTEXATTRIBIVPROC, "glGetVertexAttribiv", index, pname, params); }

inline void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params) { CALLGL32(PFNGLGETVERTEXATTRIBIIVPROC, "glGetVertexAttribIiv", index, pname, params); }

inline void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params) { CALLGL32(PFNGLGETVERTEXATTRIBIUIVPROC, "glGetVertexAttribIuiv", index, pname, params); }

inline void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer) { CALLGL32(PFNGLGETVERTEXATTRIBPOINTERVPROC, "glGetVertexAttribPointerv", index, pname, pointer); }

inline void glGetUniformfv(GLuint program, GLint location, GLfloat *params) { CALLGL32(PFNGLGETUNIFORMFVPROC, "glGetUniformfv", program, location, params); }

inline void glGetUniformiv(GLuint program, GLint location, GLint *params) { CALLGL32(PFNGLGETUNIFORMIVPROC, "glGetUniformiv", program, location, params); }

inline void glGetUniformuiv(GLuint program, GLint location, GLuint *params) { CALLGL32(PFNGLGETUNIFORMUIVPROC, "glGetUniformuiv", program, location, params); }

inline GLboolean glIsProgram(GLuint program) { CALLGL32(PFNGLISPROGRAMPROC, "glIsProgram", program); }

inline void glGetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei *length, GLchar *infoLog) { CALLGL32(PFNGLGETPROGRAMINFOLOGPROC, "glGetProgramInfoLog", program, maxLength, length, infoLog); }

inline void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val) { CALLGL32(PFNGLGETMULTISAMPLEFVPROC, "glGetMultisamplefv", pname, index, val); }

inline void glPointSize(GLfloat size) { CALLGL32(PFNGLPOINTSIZEPROC, "glPointSize", size); }

inline void glPointParameterf(GLenum pname, GLfloat param) { CALLGL32(PFNGLPOINTPARAMETERFPROC, "glPointParameterf", pname, param); }

inline void glPointParameteri(GLenum pname, GLint param) { CALLGL32(PFNGLPOINTPARAMETERIPROC, "glPointParameteri", pname, param); }

inline void glPointParameterfv(GLenum pname, const GLfloat * params) { CALLGL32(PFNGLPOINTPARAMETERFVPROC, "glPointParameterfv", pname, params); }

inline void glPointParameteriv(GLenum pname, const GLint * params) { CALLGL32(PFNGLPOINTPARAMETERIVPROC, "glPointParameteriv", pname, params); }

inline void glLineWidth(GLfloat width) { CALLGL32(PFNGLLINEWIDTHPROC, "glLineWidth", width); }

inline void glFrontFace(GLenum mode) { CALLGL32(PFNGLFRONTFACEPROC, "glFrontFace", mode); }

inline void glCullFace(GLenum mode) { CALLGL32(PFNGLCULLFACEPROC, "glCullFace", mode); }

inline void glPolygonMode(GLenum face, GLenum mode) { CALLGL32(PFNGLPOLYGONMODEPROC, "glPolygonMode", face, mode); }

inline void glPolygonOffset(GLfloat factor, GLfloat units) { CALLGL32(PFNGLPOLYGONOFFSETPROC, "glPolygonOffset", factor, units); }

inline void glPixelStoref(GLenum pname, GLfloat param) { CALLGL32(PFNGLPIXELSTOREFPROC, "glPixelStoref", pname, param); }

inline void glPixelStorei(GLenum pname, GLint param) { CALLGL32(PFNGLPIXELSTOREIPROC, "glPixelStorei", pname, param); }

inline void glActiveTexture(GLenum texture) { CALLGL32(PFNGLACTIVETEXTUREPROC, "glActiveTexture", texture); }

inline void glTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL32(PFNGLTEXIMAGE3DPROC, "glTexImage3D", target, level, internalFormat, width, height, depth, border, format, type, data); }

inline void glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL32(PFNGLTEXIMAGE2DPROC, "glTexImage2D", target, level, internalFormat, width, height, border, format, type, data); }

inline void glTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL32(PFNGLTEXIMAGE1DPROC, "glTexImage1D", target, level, internalFormat, width, border, format, type, data); }

inline void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
	{ CALLGL32(PFNGLCOPYTEXIMAGE2DPROC, "glCopyTexImage2D", target, level, internalformat, x, y, width, height, border); }

inline void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
	{ CALLGL32(PFNGLCOPYTEXIMAGE1DPROC, "glCopyTexImage1D", target, level, internalformat, x, y, width, border); }

inline void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels)
	{ CALLGL32(PFNGLTEXSUBIMAGE3DPROC, "glTexSubImage3D", target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }

inline void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels)
	{ CALLGL32(PFNGLTEXSUBIMAGE2DPROC, "glTexSubImage2D", target, level, xoffset, yoffset, width, height, format, type, pixels); }

inline void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels)
	{ CALLGL32(PFNGLTEXSUBIMAGE1DPROC, "glTexSubImage1D", target, level, xoffset, width, format, type, pixels); }

inline void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
	{ CALLGL32(PFNGLCOPYTEXSUBIMAGE3DPROC, "glCopyTexSubImage3D", target, level, xoffset, yoffset, zoffset, x, y, width, height); }

inline void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
	{ CALLGL32(PFNGLCOPYTEXSUBIMAGE2DPROC, "glCopyTexSubImage2D", target, level, xoffset, yoffset, x, y, width, height); }

inline void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) 
	{ CALLGL32(PFNGLCOPYTEXSUBIMAGE1DPROC, "glCopyTexSubImage1D", target, level, xoffset, x, y, width); }

inline void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data)
	{ CALLGL32(PFNGLCOMPRESSEDTEXIMAGE3DPROC, "glCompressedTexImage3D", target, level, internalformat, width, height, depth, border, imageSize, data); }

inline void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data)
	{ CALLGL32(PFNGLCOMPRESSEDTEXIMAGE2DPROC, "glCompressedTexImage2D", target, level, internalformat, width, height, border, imageSize, data); }

inline void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data)
	{ CALLGL32(PFNGLCOMPRESSEDTEXIMAGE1DPROC, "glCompressedTexImage1D", target, level, internalformat, width, border, imageSize, data); }

inline void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, 
										const GLvoid * data) 
	{ CALLGL32(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC, "glCompressedTexSubImage3D", target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }

inline void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) 
	{ CALLGL32(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC, "glCompressedTexSubImage2D", target, level, xoffset, yoffset, width, height, format, imageSize, data); }

inline void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data)
	{ CALLGL32(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC, "glCompressedTexSubImage1D", target, level, xoffset, width, format, imageSize, data); }

inline void glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
	{ CALLGL32(PFNGLTEXIMAGE3DMULTISAMPLEPROC, "glTexImage3DMultisample", target, samples, internalformat, width, height, depth, fixedsamplelocations); }

inline void glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
	{ CALLGL32(PFNGLTEXIMAGE2DMULTISAMPLEPROC, "glTexImage2DMultisample", target, samples, internalformat, width, height, fixedsamplelocations); }

inline void glTexBuffer(GLenum target, GLenum internalFormat, GLuint buffer) { CALLGL32(PFNGLTEXBUFFERPROC, "glTexBuffer", target, internalFormat, buffer); }

inline void glTexParameterf(GLenum target, GLenum pname, GLfloat param) { CALLGL32(PFNGLTEXPARAMETERFPROC, "glTexParameterf", target, pname, param); }

inline void glTexParameteri(GLenum target, GLenum pname, GLint param) { CALLGL32(PFNGLTEXPARAMETERIPROC, "glTexParameteri", target, pname, param); }

inline void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) { CALLGL32(PFNGLTEXPARAMETERFVPROC, "glTexParameterfv", target, pname, params); }

inline void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) { CALLGL32(PFNGLTEXPARAMETERIVPROC, "glTexParameteriv", target, pname, params); }

inline void glTexParameterIiv(GLenum target, GLenum pname, const GLint * params) { CALLGL32(PFNGLTEXPARAMETERIIVPROC, "glTexParameterIiv", target, pname, params); }

inline void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint * params) { CALLGL32(PFNGLTEXPARAMETERIUIVPROC, "glTexParameterIuiv", target, pname, params); }

inline void glGenerateMipmap(GLenum target) { CALLGL32(PFNGLGENERATEMIPMAPPROC, "glGenerateMipmap", target); }

inline void glBindTexture(GLenum target, GLuint texture) { CALLGL32(PFNGLBINDTEXTUREPROC, "glBindTexture", target, texture); }

inline void glDeleteTextures(GLsizei n, const GLuint * textures) { CALLGL32(PFNGLDELETETEXTURESPROC, "glDeleteTextures", n, textures); }

inline void glGenTextures(GLsizei n, GLuint * textures) { CALLGL32(PFNGLGENTEXTURESPROC, "glGenTextures", n, textures); }

inline void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) { CALLGL32(PFNGLGETTEXPARAMETERFVPROC, "glGetTexParameterfv", target, pname, params); }

inline void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) { CALLGL32(PFNGLGETTEXPARAMETERIVPROC, "glGetTexParameteriv", target, pname, params); }

inline void glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params) { CALLGL32(PFNGLGETTEXPARAMETERIIVPROC, "glGetTexParameterIiv", target, pname, params); }

inline void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params) { CALLGL32(PFNGLGETTEXPARAMETERIUIVPROC, "glGetTexParameterIuiv", target, pname, params); }

inline void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) { CALLGL32(PFNGLGETTEXLEVELPARAMETERFVPROC, "glGetTexLevelParameterfv", target, level, pname, params); }

inline void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) { CALLGL32(PFNGLGETTEXLEVELPARAMETERIVPROC, "glGetTexLevelParameteriv", target, level, pname, params); }

inline void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels) { CALLGL32(PFNGLGETTEXIMAGEPROC, "glGetTexImage", target, level, format, type, pixels); }

inline void glGetCompressedTexImage(GLenum target, GLint level, GLvoid * pixels) { CALLGL32(PFNGLGETCOMPRESSEDTEXIMAGEPROC, "glGetCompressedTexImage", target, level, pixels); }

inline GLboolean glIsTexture(GLuint texture) { CALLGL32(PFNGLISTEXTUREPROC, "glIsTexture", texture); }

inline void glHint(GLenum target, GLenum mode) { CALLGL32(PFNGLHINTPROC, "glHint", target, mode); }

inline void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * data)
	{ CALLGL32(PFNGLREADPIXELSPROC, "glReadPixels", x, y, width, height, format, type, data); }

inline void glReadBuffer(GLenum mode) { CALLGL32(PFNGLREADBUFFERPROC, "glReadBuffer", mode); }

inline void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
	{ CALLGL32(PFNGLBLITFRAMEBUFFERPROC, "glBlitFramebuffer", srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }

inline void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) { CALLGL32(PFNGLSCISSORPROC, "glScissor", x, y, width, height); }

inline void glSampleCoverage(GLfloat value, GLboolean invert) { CALLGL32(PFNGLSAMPLECOVERAGEPROC, "glSampleCoverage", value, invert); }

inline void glSampleMaski(GLuint maskNumber, GLbitfield mask) { CALLGL32(PFNGLSAMPLEMASKIPROC, "glSampleMaski", maskNumber, mask); }

inline void glStencilFunc(GLenum func, GLint ref, GLuint mask) { CALLGL32(PFNGLSTENCILFUNCPROC, "glStencilFunc", func, ref, mask); }

inline void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { CALLGL32(PFNGLSTENCILFUNCSEPARATEPROC, "glStencilFuncSeparate", face, func, ref, mask); }

inline void glStencilOp(GLenum sfail, GLenum dpfail, GLenum dppass) { CALLGL32(PFNGLSTENCILOPPROC, "glStencilOp", sfail, dpfail, dppass); }

inline void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) { CALLGL32(PFNGLSTENCILOPSEPARATEPROC, "glStencilOpSeparate", face, sfail, dpfail, dppass); }

inline void glDepthFunc(GLenum func) { CALLGL32(PFNGLDEPTHFUNCPROC, "glDepthFunc", func); }

inline void glBlendEquation(GLenum mode) { CALLGL32(PFNGLBLENDEQUATIONPROC, "glBlendEquation", mode); }

inline void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { CALLGL32(PFNGLBLENDEQUATIONSEPARATEPROC, "glBlendEquationSeparate", modeRGB, modeAlpha); }

inline void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { CALLGL32(PFNGLBLENDFUNCSEPARATEPROC, "glBlendFuncSeparate", srcRGB, dstRGB, srcAlpha, dstAlpha); }

inline void glBlendFunc(GLenum sfactor, GLenum dfactor) { CALLGL32(PFNGLBLENDFUNCPROC, "glBlendFunc", sfactor, dfactor); }

inline void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { CALLGL32(PFNGLBLENDCOLORPROC, "glBlendColor", red, green, blue, alpha); }

inline void glLogicOp(GLenum opcode) { CALLGL32(PFNGLLOGICOPPROC, "glLogicOp", opcode); }

inline void glDrawBuffer(GLenum buf) { CALLGL32(PFNGLDRAWBUFFERPROC, "glDrawBuffer", buf); }

inline void glDrawBuffers(GLsizei n, const GLenum *bufs) { CALLGL32(PFNGLDRAWBUFFERSPROC, "glDrawBuffers", n, bufs); }

inline void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { CALLGL32(PFNGLCOLORMASKPROC, "glColorMask", red, green, blue, alpha); }

inline void glColorMaski(GLuint buf, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { CALLGL32(PFNGLCOLORMASKIPROC, "glColorMaski", buf, red, green, blue, alpha); }

inline void glDepthMask(GLboolean flag) { CALLGL32(PFNGLDEPTHMASKPROC, "glDepthMask", flag); }

inline void glStencilMask(GLuint mask) { CALLGL32(PFNGLSTENCILMASKPROC, "glStencilMask", mask); }

inline void glStencilMaskSeparate(GLenum face, GLuint mask) { CALLGL32(PFNGLSTENCILMASKSEPARATEPROC, "glStencilMaskSeparate", face, mask); }

inline void glClear(GLbitfield mask) { CALLGL32(PFNGLCLEARPROC, "glClear", mask); }

inline void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { CALLGL32(PFNGLCLEARCOLORPROC, "glClearColor", red, green, blue, alpha); }

inline void glClearDepth(GLdouble depth) { CALLGL32(PFNGLCLEARDEPTHPROC, "glClearDepth", depth); }

inline void glClearStencil(GLint s) { CALLGL32(PFNGLCLEARSTENCILPROC, "glClearStencil", s); }

inline void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint * value) { CALLGL32(PFNGLCLEARBUFFERIVPROC, "glClearBufferiv", buffer, drawbuffer, value); }

inline void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint * value) { CALLGL32(PFNGLCLEARBUFFERUIVPROC, "glClearBufferuiv", buffer, drawbuffer, value); }

inline void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat * value) { CALLGL32(PFNGLCLEARBUFFERFVPROC, "glClearBufferfv", buffer, drawbuffer, value); }

inline void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { CALLGL32(PFNGLCLEARBUFFERFIPROC, "glClearBufferfi", buffer, drawbuffer, depth, stencil); }

inline void glBindFramebuffer(GLenum target, GLuint framebuffer) { CALLGL32(PFNGLBINDFRAMEBUFFERPROC, "glBindFramebuffer", target, framebuffer); }

inline void glDeleteFramebuffers(GLsizei n, GLuint *framebuffers) { CALLGL32(PFNGLDELETEFRAMEBUFFERSPROC, "glDeleteFramebuffers", n, framebuffers); }

inline void glGenFramebuffers(GLsizei n, GLuint *ids) { CALLGL32(PFNGLGENFRAMEBUFFERSPROC, "glGenFramebuffers", n, ids); }

inline void glBindRenderbuffer(GLenum target, GLuint renderbuffer) { CALLGL32(PFNGLBINDRENDERBUFFERPROC, "glBindRenderbuffer", target, renderbuffer); }

inline void glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers) { CALLGL32(PFNGLDELETERENDERBUFFERSPROC, "glDeleteRenderbuffers", n, renderbuffers); }

inline void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) { CALLGL32(PFNGLGENRENDERBUFFERSPROC, "glGenRenderbuffers", n, renderbuffers); }

inline void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
	{ CALLGL32(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, "glRenderbufferStorageMultisample", target, samples, internalformat, width, height); }

inline void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
	{ CALLGL32(PFNGLRENDERBUFFERSTORAGEPROC, "glRenderbufferStorage", target, internalformat, width, height); }

inline void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
	{ CALLGL32(PFNGLFRAMEBUFFERRENDERBUFFERPROC, "glFramebufferRenderbuffer", target, attachment, renderbuffertarget, renderbuffer); }

inline void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) { CALLGL32(PFNGLFRAMEBUFFERTEXTUREPROC, "glFramebufferTexture", target, attachment, texture, level); }

inline void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
	{ CALLGL32(PFNGLFRAMEBUFFERTEXTURE1DPROC, "glFramebufferTexture1D", target, attachment, textarget, texture, level); }

inline void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
	{ CALLGL32(PFNGLFRAMEBUFFERTEXTURE2DPROC, "glFramebufferTexture2D", target, attachment, textarget, texture, level); }

inline void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint layer)
	{ CALLGL32(PFNGLFRAMEBUFFERTEXTURE3DPROC, "glFramebufferTexture3D", target, attachment, textarget, texture, level, layer); }

inline void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
	{ CALLGL32(PFNGLFRAMEBUFFERTEXTURELAYERPROC, "glFramebufferTextureLayer", target, attachment, texture, level, layer); }

inline GLenum glCheckFramebufferStatus(GLenum target) { CALLGL32(PFNGLCHECKFRAMEBUFFERSTATUSPROC, "glCheckFramebufferStatus", target); }

inline GLboolean glIsFramebuffer(GLuint framebuffer) { CALLGL32(PFNGLISFRAMEBUFFERPROC, "glIsFramebuffer", framebuffer); }

inline void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params)
	{ CALLGL32(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, "glGetFramebufferAttachmentParameteriv", target, attachment, pname, params); }

inline GLboolean glIsRenderbuffer(GLuint renderbuffer) { CALLGL32(PFNGLISRENDERBUFFERPROC, "glIsRenderbuffer", renderbuffer); }

inline void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) { CALLGL32(PFNGLGETRENDERBUFFERPARAMETERIVPROC, "glGetRenderbufferParameteriv", target, pname, params); }

inline void glFlush() { CALLGL32(PFNGLFLUSHPROC, "glFlush"); }

inline void glFinish() { CALLGL32(PFNGLFINISHPROC, "glFinish"); }

inline GLsync glFenceSync(GLenum condition, GLbitfield flags) { CALLGL32(PFNGLFENCESYNCPROC, "glFenceSync", condition, flags); }

inline void glDeleteSync(GLsync sync) { CALLGL32(PFNGLDELETESYNCPROC, "glDeleteSync", sync); }

inline GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { CALLGL32(PFNGLCLIENTWAITSYNCPROC, "glClientWaitSync", sync, flags, timeout); }

inline void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { CALLGL32(PFNGLWAITSYNCPROC, "glWaitSync", sync, flags, timeout); }

inline void glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) { CALLGL32(PFNGLGETSYNCIVPROC, "glGetSynciv", sync, pname, bufSize, length, values); }

inline GLboolean glIsSync(GLsync sync) { CALLGL32(PFNGLISSYNCPROC, "glIsSync", sync); }

inline void glGetBooleanv(GLenum pname, GLboolean * data) { CALLGL32(PFNGLGETBOOLEANVPROC, "glGetBooleanv", pname, data); }

inline void glGetDoublev(GLenum pname, GLdouble * data) { CALLGL32(PFNGLGETDOUBLEVPROC, "glGetDoublev", pname, data); }

inline void glGetFloatv(GLenum pname, GLfloat * data) { CALLGL32(PFNGLGETFLOATVPROC, "glGetFloatv", pname, data); }

inline void glGetIntegerv(GLenum pname, GLint * data) { CALLGL32(PFNGLGETINTEGERVPROC, "glGetIntegerv", pname, data); }

inline void glGetInteger64v(GLenum pname, GLint64 * data) { CALLGL32(PFNGLGETINTEGER64VPROC, "glGetInteger64v", pname, data); }

inline void glGetBooleani_v(GLenum target, GLuint index, GLboolean * data) { CALLGL32(PFNGLGETBOOLEANI_VPROC, "glGetBooleani_v", target, index, data); }

inline void glGetIntegeri_v(GLenum target, GLuint index, GLint * data) { CALLGL32(PFNGLGETINTEGERI_VPROC, "glGetIntegeri_v", target, index, data); }

inline void glGetInteger64i_v(GLenum target, GLuint index, GLint64 * data) { CALLGL32(PFNGLGETINTEGER64I_VPROC, "glGetInteger64i_v", target, index, data); }

inline GLboolean glIsEnabled(GLenum cap) { CALLGL32(PFNGLISENABLEDPROC, "glIsEnabled", cap); }

inline GLboolean glIsEnabledi(GLenum cap, GLuint index) { CALLGL32(PFNGLISENABLEDIPROC, "glIsEnabledi", cap, index); }

inline const GLubyte *glGetString(GLenum name) { CALLGL32(PFNGLGETSTRINGPROC, "glGetString", name); }

inline const GLubyte *glGetStringi(GLenum name, GLuint index) { CALLGL32(PFNGLGETSTRINGIPROC, "glGetStringi", name, index); }

inline void glQueryCounter(GLuint id, GLenum target) { CALLGL32(PFNGLQUERYCOUNTERPROC, "glQueryCounter", id, target); }

inline void glGenSamplers(GLsizei n, GLuint *samplers) { CALLGL32(PFNGLGENSAMPLERSPROC, "glGenSamplers", n, samplers); }

inline void glBindSampler(GLuint unit, GLuint sampler) { CALLGL32(PFNGLBINDSAMPLERPROC, "glBindSampler", unit, sampler); }

inline void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) { CALLGL32(PFNGLSAMPLERPARAMETERFPROC, "glSamplerParameterf", sampler, pname, param); }

inline void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) { CALLGL32(PFNGLSAMPLERPARAMETERIPROC, "glSamplerParameteri", sampler, pname, param); }

inline void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat * params) { CALLGL32(PFNGLSAMPLERPARAMETERFVPROC, "glSamplerParameterfv", sampler, pname, params); }

inline void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint * params) { CALLGL32(PFNGLSAMPLERPARAMETERIVPROC, "glSamplerParameteriv", sampler, pname, params); }

inline void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *params) { CALLGL32(PFNGLSAMPLERPARAMETERIIVPROC, "glSamplerParameteriv", sampler, pname, params); }

inline void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *params) { CALLGL32(PFNGLSAMPLERPARAMETERIUIVPROC, "glSamplerParameterIuiv", sampler, pname, params); }

inline void glDeleteSamplers(GLsizei n, const GLuint * samplers) { CALLGL32(PFNGLDELETESAMPLERSPROC, "glDeleteSamplers", n, samplers); }

inline GLboolean glIsSampler(GLuint id) { CALLGL32(PFNGLISSAMPLERPROC, "glIsSampler", id); }

inline void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params) { CALLGL32(PFNGLGETSAMPLERPARAMETERFVPROC, "glGetSamplerParameterfv", sampler, pname, params); }

inline void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params) { CALLGL32(PFNGLGETSAMPLERPARAMETERIVPROC, "glGetSamplerParameteriv", sampler, pname, params); }

inline void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params) { CALLGL32(PFNGLGETSAMPLERPARAMETERIIVPROC, "glGetSamplerParameterIiv", sampler, pname, params); }

inline void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params) { CALLGL32(PFNGLGETSAMPLERPARAMETERIUIVPROC, "glGetSamplerParameterIuiv", sampler, pname, params); }

inline void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name)
	{ CALLGL32(PFNGLBINDFRAGDATALOCATIONINDEXEDPROC, "glBindFragDataLocationIndexed", program, colorNumber, index, name); }

inline GLint glGetFragDataIndex(GLuint program, const GLchar * name) { CALLGL32(PFNGLGETFRAGDATAINDEXPROC, "glGetFragDataIndex", program, name); }