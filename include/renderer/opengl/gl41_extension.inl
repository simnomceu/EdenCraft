inline void glVertexAttribL1d(GLuint index, GLdouble v0) { CALLGL41(PFNGLVERTEXATTRIBL1DPROC, "glVertexAttribL1d", index, v0); }

inline void glVertexAttribL2d(GLuint index, GLdouble v0, GLdouble v1) { CALLGL41(PFNGLVERTEXATTRIBL2DPROC, "glVertexAttribL2d", index, v0, v1); }

inline void glVertexAttribL3d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2) { CALLGL41(PFNGLVERTEXATTRIBL3DPROC, "glVertexAttribL3d", index, v0, v1, v2); }

inline void glVertexAttribL4d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) { CALLGL41(PFNGLVERTEXATTRIBL4DPROC, "glVertexAttribL4d", index, v0, v1, v2, v3); }

inline void glVertexAttribL1dv(GLuint index, const GLdouble * v) { CALLGL41(PFNGLVERTEXATTRIBL1DVPROC, "glVertexAttribL1dv", index, v); }

inline void glVertexAttribL2dv(GLuint index, const GLdouble * v) { CALLGL41(PFNGLVERTEXATTRIBL2DVPROC, "glVertexAttribL2dv", index, v); }

inline void glVertexAttribL3dv(GLuint index, const GLdouble * v) { CALLGL41(PFNGLVERTEXATTRIBL3DVPROC, "glVertexAttribL3dv", index, v); }

inline void glVertexAttribL4dv(GLuint index, const GLdouble * v) { CALLGL41(PFNGLVERTEXATTRIBL4DVPROC, "glVertexAttribL4dv", index, v); }

inline void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
	{ CALLGL41(PFNGLVERTEXATTRIBLPOINTERPROC, "glVertexAttribLPointer", index, size, type, stride, pointer); }

inline void glDepthRangef(GLfloat nearVal, GLfloat farVal) { CALLGL41(PFNGLDEPTHRANGEFPROC, "glDepthRangef", nearVal, farVal); }

inline void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params) { CALLGL41(PFNGLGETVERTEXATTRIBLDVPROC, "glGetVertexAttribLdv", index, pname, params); }

inline void glClearDepthf(GLfloat depth) { CALLGL41(PFNGLCLEARDEPTHFPROC, "glClearDepthf", depth); }

inline void glGetFloati_v(GLenum target, GLuint index, GLfloat * data) { CALLGL41(PFNGLGETFLOATI_VPROC, "glGetFloati_v", target, index, data); }

inline void glGetDoublei_v(GLenum target, GLuint index, GLdouble * data) { CALLGL41(PFNGLGETDOUBLEI_VPROC, "glGetDoublei_v", target, index, data); }

inline void glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const GLvoid *binary, GLsizei length)
	{ CALLGL41(PFNGLSHADERBINARYPROC, "glShaderBinary", count, shaders, binaryFormat, binary, length); }

inline void glReleaseShaderCompiler() { CALLGL41(PFNGLRELEASESHADERCOMPILERPROC, "glReleaseShaderCompiler"); }

inline GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar **strings) { CALLGL41(PFNGLCREATESHADERPROGRAMVPROC, "glCreateShaderProgramv", type, count, strings); }

inline void glProgramParameteri(GLuint program, GLenum pname, GLint value) { CALLGL41(PFNGLPROGRAMPARAMETERIPROC, "glProgramParameteri", program, pname, value); }

inline void glGenProgramPipelines(GLsizei n, GLuint *pipelines) { CALLGL41(PFNGLGENPROGRAMPIPELINESPROC, "glGenProgramPipelines", n, pipelines); }

inline void glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines) { CALLGL41(PFNGLDELETEPROGRAMPIPELINESPROC, "glDeleteProgramPipelines", n, pipelines); }

inline GLboolean glIsProgramPipeline(GLuint pipeline) { CALLGL41(PFNGLISPROGRAMPIPELINEPROC, "glIsProgramPipeline", pipeline); }

inline void glBindProgramPipeline(GLuint pipeline) { CALLGL41(PFNGLBINDPROGRAMPIPELINEPROC, "glBindProgramPipeline", pipeline); }

inline void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) { CALLGL41(PFNGLUSEPROGRAMSTAGESPROC, "glUseProgramStages", pipeline, stages, program); }

inline void glActiveShaderProgram(GLuint pipeline, GLuint program) { CALLGL41(PFNGLACTIVESHADERPROGRAMPROC, "glActiveShaderProgram", pipeline, program); }

inline void glGetProgramBinary(GLuint program, GLsizei bufsize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary)
	{ CALLGL41(PFNGLGETPROGRAMBINARYPROC, "glGetProgramBinary", program, bufsize, length, binaryFormat, binary); }

inline void glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length) { CALLGL41(PFNGLPROGRAMBINARYPROC, "glProgramBinary", program, binaryFormat, binary, length); }

inline void glProgramUniform1f(GLuint program, GLint location, GLfloat v0) { CALLGL41(PFNGLPROGRAMUNIFORM1FPROC, "glProgramUniform1f", program, location, v0); }

inline void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) { CALLGL41(PFNGLPROGRAMUNIFORM2FPROC, "glProgramUniform2f", program, location, v0, v1); }

inline void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { CALLGL41(PFNGLPROGRAMUNIFORM3FPROC, "glProgramUniform3f", program, location, v0, v1, v2); }

inline void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
	{ CALLGL41(PFNGLPROGRAMUNIFORM4FPROC, "glProgramUniform4f", program, location, v0, v1, v2, v3); }

inline void glProgramUniform1i(GLuint program, GLint location, GLint v0) { CALLGL41(PFNGLPROGRAMUNIFORM1IPROC, "glProgramUniform1i", program, location, v0); }

inline void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) { CALLGL41(PFNGLPROGRAMUNIFORM2IPROC, "glProgramUniform2i", program, location, v0, v1); }

inline void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) { CALLGL41(PFNGLPROGRAMUNIFORM3IPROC, "glProgramUniform3i", program, location, v0, v1, v2); }

inline void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
	{ CALLGL41(PFNGLPROGRAMUNIFORM4IPROC, "glProgramUniform4i", program, location, v0, v1, v2, v3); }

inline void glProgramUniform1ui(GLuint program, GLint location, GLuint v0) { CALLGL41(PFNGLPROGRAMUNIFORM1UIPROC, "glProgramUniform1ui", program, location, v0); }

inline void glProgramUniform2ui(GLuint program, GLint location, GLint v0, GLuint v1) { CALLGL41(PFNGLPROGRAMUNIFORM2UIPROC, "glProgramUniform2ui", program, location, v0, v1); }

inline void glProgramUniform3ui(GLuint program, GLint location, GLint v0, GLint v1, GLuint v2) { CALLGL41(PFNGLPROGRAMUNIFORM3UIPROC, "glProgramUniform3ui", program, location, v0, v1, v2); }

inline void glProgramUniform4ui(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLuint v3)
	{ CALLGL41(PFNGLPROGRAMUNIFORM4UIPROC, "glProgramUniform4ui", program, location, v0, v1, v2, v3); }

inline void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { CALLGL41(PFNGLPROGRAMUNIFORM1FVPROC, "glProgramUniform1fv", program, location, count, value); }

inline void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { CALLGL41(PFNGLPROGRAMUNIFORM2FVPROC, "glProgramUniform2fv", program, location, count, value); }

inline void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { CALLGL41(PFNGLPROGRAMUNIFORM3FVPROC, "glProgramUniform3fv", program, location, count, value); }

inline void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { CALLGL41(PFNGLPROGRAMUNIFORM4FVPROC, "glProgramUniform4fv", program, location, count, value); }

inline void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) { CALLGL41(PFNGLPROGRAMUNIFORM1IVPROC, "glProgramUniform1iv", program, location, count, value); }

inline void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) { CALLGL41(PFNGLPROGRAMUNIFORM2IVPROC, "glProgramUniform2iv", program, location, count, value); }

inline void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) { CALLGL41(PFNGLPROGRAMUNIFORM3IVPROC, "glProgramUniform3iv", program, location, count, value); }

inline void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) { CALLGL41(PFNGLPROGRAMUNIFORM4IVPROC, "glProgramUniform4iv", program, location, count, value); }

inline void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { CALLGL41(PFNGLPROGRAMUNIFORM1UIVPROC, "glProgramUniform1uiv", program, location, count, value); }

inline void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { CALLGL41(PFNGLPROGRAMUNIFORM2UIVPROC, "glProgramUniform2uiv", program, location, count, value); }

inline void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { CALLGL41(PFNGLPROGRAMUNIFORM3UIVPROC, "glProgramUniform3uiv", program, location, count, value); }

inline void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { CALLGL41(PFNGLPROGRAMUNIFORM4UIVPROC, "glProgramUniform4uiv", program, location, count, value); }

inline void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41(PFNGLPROGRAMUNIFORMMATRIX2FVPROC, "glProgramUniformMatrix2fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41(PFNGLPROGRAMUNIFORMMATRIX3FVPROC, "glProgramUniformMatrix3fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41(PFNGLPROGRAMUNIFORMMATRIX4FVPROC, "glProgramUniformMatrix4fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41(PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC, "glProgramUniformMatrix2x3fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41(PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC, "glProgramUniformMatrix3x2fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41(PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC, "glProgramUniformMatrix2x4fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41(PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC, "glProgramUniformMatrix4x2fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41(PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC, "glProgramUniformMatrix3x4fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41(PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC, "glProgramUniformMatrix4x3fv", program, location, count, transpose, value); }

inline void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params) { CALLGL41(PFNGLGETPROGRAMPIPELINEIVPROC, "glGetProgramPipelineiv", pipeline, pname, params); }

inline void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
	{ CALLGL41(PFNGLGETPROGRAMPIPELINEINFOLOGPROC, "glGetProgramPipelineInfoLog", pipeline, bufSize, length, infoLog); }

inline void glGetShaderPrecisionFormat(GLenum shaderType, GLenum precisionType, GLint *range, GLint *precision)
	{ CALLGL41(PFNGLGETSHADERPRECISIONFORMATPROC, "glGetShaderPrecisionFormat", shaderType, precisionType, range, precision); }

inline void glValidateProgramPipeline(GLuint pipeline) { CALLGL41(PFNGLVALIDATEPROGRAMPIPELINEPROC, "glValidateProgramPipeline", pipeline); }

inline void glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble *v) { CALLGL41(PFNGLDEPTHRANGEARRAYVPROC, "glDepthRangeArrayv", first, count, v); }

inline void glDepthRangeIndexed(GLuint index, GLdouble nearVal, GLdouble farVal) { CALLGL41(PFNGLDEPTHRANGEINDEXEDPROC, "glDepthRangeIndexed", index, nearVal, farVal); }

inline void glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v) { CALLGL41(PFNGLVIEWPORTARRAYVPROC, "glViewportArrayv", first, count, v); }

inline void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) { CALLGL41(PFNGLVIEWPORTINDEXEDFPROC, "glViewportIndexedf", index, x, y, w, h); }

inline void glViewportIndexedfv(GLuint index, const GLfloat *v) { CALLGL41(PFNGLVIEWPORTINDEXEDFVPROC, "glViewportIndexedfv", index, v); }

inline void glScissorArrayv(GLuint first, GLsizei count, const GLint *v) { CALLGL41(PFNGLSCISSORARRAYVPROC, "glScissorArrayv", first, count, v); }

inline void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) { CALLGL41(PFNGLSCISSORINDEXEDPROC, "glScissorIndexed", index, left, bottom, width, height); }

inline void glScissorIndexedv(GLuint index, const GLint *v) { CALLGL41(PFNGLSCISSORINDEXEDVPROC, "glScissorIndexedv", index, v); }