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


inline void glVertexAttribL1d(GLuint index, GLdouble v0) { CALLGL41_V(PFNGLVERTEXATTRIBL1DPROC, "glVertexAttribL1d", index, v0); }

inline void glVertexAttribL2d(GLuint index, GLdouble v0, GLdouble v1) { CALLGL41_V(PFNGLVERTEXATTRIBL2DPROC, "glVertexAttribL2d", index, v0, v1); }

inline void glVertexAttribL3d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2) { CALLGL41_V(PFNGLVERTEXATTRIBL3DPROC, "glVertexAttribL3d", index, v0, v1, v2); }

inline void glVertexAttribL4d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) { CALLGL41_V(PFNGLVERTEXATTRIBL4DPROC, "glVertexAttribL4d", index, v0, v1, v2, v3); }

inline void glVertexAttribL1dv(GLuint index, const GLdouble * v) { CALLGL41_V(PFNGLVERTEXATTRIBL1DVPROC, "glVertexAttribL1dv", index, v); }

inline void glVertexAttribL2dv(GLuint index, const GLdouble * v) { CALLGL41_V(PFNGLVERTEXATTRIBL2DVPROC, "glVertexAttribL2dv", index, v); }

inline void glVertexAttribL3dv(GLuint index, const GLdouble * v) { CALLGL41_V(PFNGLVERTEXATTRIBL3DVPROC, "glVertexAttribL3dv", index, v); }

inline void glVertexAttribL4dv(GLuint index, const GLdouble * v) { CALLGL41_V(PFNGLVERTEXATTRIBL4DVPROC, "glVertexAttribL4dv", index, v); }

inline void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
	{ CALLGL41_V(PFNGLVERTEXATTRIBLPOINTERPROC, "glVertexAttribLPointer", index, size, type, stride, pointer); }

inline void glDepthRangef(GLfloat nearVal, GLfloat farVal) { CALLGL41_V(PFNGLDEPTHRANGEFPROC, "glDepthRangef", nearVal, farVal); }

inline void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params) { CALLGL41_V(PFNGLGETVERTEXATTRIBLDVPROC, "glGetVertexAttribLdv", index, pname, params); }

inline void glClearDepthf(GLfloat depth) { CALLGL41_V(PFNGLCLEARDEPTHFPROC, "glClearDepthf", depth); }

inline void glGetFloati_v(GLenum target, GLuint index, GLfloat * data) { CALLGL41_V(PFNGLGETFLOATI_VPROC, "glGetFloati_v", target, index, data); }

inline void glGetDoublei_v(GLenum target, GLuint index, GLdouble * data) { CALLGL41_V(PFNGLGETDOUBLEI_VPROC, "glGetDoublei_v", target, index, data); }

inline void glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const GLvoid *binary, GLsizei length)
	{ CALLGL41_V(PFNGLSHADERBINARYPROC, "glShaderBinary", count, shaders, binaryFormat, binary, length); }

inline void glReleaseShaderCompiler() { CALLGL41(PFNGLRELEASESHADERCOMPILERPROC, "glReleaseShaderCompiler"); }

inline GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar **strings) { CALLGL41_V(PFNGLCREATESHADERPROGRAMVPROC, "glCreateShaderProgramv", type, count, strings); }

inline void glProgramParameteri(GLuint program, GLenum pname, GLint value) { CALLGL41_V(PFNGLPROGRAMPARAMETERIPROC, "glProgramParameteri", program, pname, value); }

inline void glGenProgramPipelines(GLsizei n, GLuint *pipelines) { CALLGL41_V(PFNGLGENPROGRAMPIPELINESPROC, "glGenProgramPipelines", n, pipelines); }

inline void glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines) { CALLGL41_V(PFNGLDELETEPROGRAMPIPELINESPROC, "glDeleteProgramPipelines", n, pipelines); }

inline GLboolean glIsProgramPipeline(GLuint pipeline) { CALLGL41_V(PFNGLISPROGRAMPIPELINEPROC, "glIsProgramPipeline", pipeline); }

inline void glBindProgramPipeline(GLuint pipeline) { CALLGL41_V(PFNGLBINDPROGRAMPIPELINEPROC, "glBindProgramPipeline", pipeline); }

inline void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) { CALLGL41_V(PFNGLUSEPROGRAMSTAGESPROC, "glUseProgramStages", pipeline, stages, program); }

inline void glActiveShaderProgram(GLuint pipeline, GLuint program) { CALLGL41_V(PFNGLACTIVESHADERPROGRAMPROC, "glActiveShaderProgram", pipeline, program); }

inline void glGetProgramBinary(GLuint program, GLsizei bufsize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary)
	{ CALLGL41_V(PFNGLGETPROGRAMBINARYPROC, "glGetProgramBinary", program, bufsize, length, binaryFormat, binary); }

inline void glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length) { CALLGL41_V(PFNGLPROGRAMBINARYPROC, "glProgramBinary", program, binaryFormat, binary, length); }

inline void glProgramUniform1f(GLuint program, GLint location, GLfloat v0) { CALLGL41_V(PFNGLPROGRAMUNIFORM1FPROC, "glProgramUniform1f", program, location, v0); }

inline void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) { CALLGL41_V(PFNGLPROGRAMUNIFORM2FPROC, "glProgramUniform2f", program, location, v0, v1); }

inline void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { CALLGL41_V(PFNGLPROGRAMUNIFORM3FPROC, "glProgramUniform3f", program, location, v0, v1, v2); }

inline void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
	{ CALLGL41_V(PFNGLPROGRAMUNIFORM4FPROC, "glProgramUniform4f", program, location, v0, v1, v2, v3); }

inline void glProgramUniform1i(GLuint program, GLint location, GLint v0) { CALLGL41_V(PFNGLPROGRAMUNIFORM1IPROC, "glProgramUniform1i", program, location, v0); }

inline void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) { CALLGL41_V(PFNGLPROGRAMUNIFORM2IPROC, "glProgramUniform2i", program, location, v0, v1); }

inline void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) { CALLGL41_V(PFNGLPROGRAMUNIFORM3IPROC, "glProgramUniform3i", program, location, v0, v1, v2); }

inline void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
	{ CALLGL41_V(PFNGLPROGRAMUNIFORM4IPROC, "glProgramUniform4i", program, location, v0, v1, v2, v3); }

inline void glProgramUniform1ui(GLuint program, GLint location, GLuint v0) { CALLGL41_V(PFNGLPROGRAMUNIFORM1UIPROC, "glProgramUniform1ui", program, location, v0); }

inline void glProgramUniform2ui(GLuint program, GLint location, GLint v0, GLuint v1) { CALLGL41_V(PFNGLPROGRAMUNIFORM2UIPROC, "glProgramUniform2ui", program, location, v0, v1); }

inline void glProgramUniform3ui(GLuint program, GLint location, GLint v0, GLint v1, GLuint v2) { CALLGL41_V(PFNGLPROGRAMUNIFORM3UIPROC, "glProgramUniform3ui", program, location, v0, v1, v2); }

inline void glProgramUniform4ui(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLuint v3)
	{ CALLGL41_V(PFNGLPROGRAMUNIFORM4UIPROC, "glProgramUniform4ui", program, location, v0, v1, v2, v3); }

inline void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { CALLGL41_V(PFNGLPROGRAMUNIFORM1FVPROC, "glProgramUniform1fv", program, location, count, value); }

inline void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { CALLGL41_V(PFNGLPROGRAMUNIFORM2FVPROC, "glProgramUniform2fv", program, location, count, value); }

inline void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { CALLGL41_V(PFNGLPROGRAMUNIFORM3FVPROC, "glProgramUniform3fv", program, location, count, value); }

inline void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { CALLGL41_V(PFNGLPROGRAMUNIFORM4FVPROC, "glProgramUniform4fv", program, location, count, value); }

inline void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) { CALLGL41_V(PFNGLPROGRAMUNIFORM1IVPROC, "glProgramUniform1iv", program, location, count, value); }

inline void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) { CALLGL41_V(PFNGLPROGRAMUNIFORM2IVPROC, "glProgramUniform2iv", program, location, count, value); }

inline void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) { CALLGL41_V(PFNGLPROGRAMUNIFORM3IVPROC, "glProgramUniform3iv", program, location, count, value); }

inline void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) { CALLGL41_V(PFNGLPROGRAMUNIFORM4IVPROC, "glProgramUniform4iv", program, location, count, value); }

inline void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { CALLGL41_V(PFNGLPROGRAMUNIFORM1UIVPROC, "glProgramUniform1uiv", program, location, count, value); }

inline void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { CALLGL41_V(PFNGLPROGRAMUNIFORM2UIVPROC, "glProgramUniform2uiv", program, location, count, value); }

inline void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { CALLGL41_V(PFNGLPROGRAMUNIFORM3UIVPROC, "glProgramUniform3uiv", program, location, count, value); }

inline void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { CALLGL41_V(PFNGLPROGRAMUNIFORM4UIVPROC, "glProgramUniform4uiv", program, location, count, value); }

inline void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41_V(PFNGLPROGRAMUNIFORMMATRIX2FVPROC, "glProgramUniformMatrix2fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41_V(PFNGLPROGRAMUNIFORMMATRIX3FVPROC, "glProgramUniformMatrix3fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41_V(PFNGLPROGRAMUNIFORMMATRIX4FVPROC, "glProgramUniformMatrix4fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41_V(PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC, "glProgramUniformMatrix2x3fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41_V(PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC, "glProgramUniformMatrix3x2fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41_V(PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC, "glProgramUniformMatrix2x4fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41_V(PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC, "glProgramUniformMatrix4x2fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41_V(PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC, "glProgramUniformMatrix3x4fv", program, location, count, transpose, value); }

inline void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	{ CALLGL41_V(PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC, "glProgramUniformMatrix4x3fv", program, location, count, transpose, value); }

inline void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params) { CALLGL41_V(PFNGLGETPROGRAMPIPELINEIVPROC, "glGetProgramPipelineiv", pipeline, pname, params); }

inline void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
	{ CALLGL41_V(PFNGLGETPROGRAMPIPELINEINFOLOGPROC, "glGetProgramPipelineInfoLog", pipeline, bufSize, length, infoLog); }

inline void glGetShaderPrecisionFormat(GLenum shaderType, GLenum precisionType, GLint *range, GLint *precision)
	{ CALLGL41_V(PFNGLGETSHADERPRECISIONFORMATPROC, "glGetShaderPrecisionFormat", shaderType, precisionType, range, precision); }

inline void glValidateProgramPipeline(GLuint pipeline) { CALLGL41_V(PFNGLVALIDATEPROGRAMPIPELINEPROC, "glValidateProgramPipeline", pipeline); }

inline void glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble *v) { CALLGL41_V(PFNGLDEPTHRANGEARRAYVPROC, "glDepthRangeArrayv", first, count, v); }

inline void glDepthRangeIndexed(GLuint index, GLdouble nearVal, GLdouble farVal) { CALLGL41_V(PFNGLDEPTHRANGEINDEXEDPROC, "glDepthRangeIndexed", index, nearVal, farVal); }

inline void glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v) { CALLGL41_V(PFNGLVIEWPORTARRAYVPROC, "glViewportArrayv", first, count, v); }

inline void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) { CALLGL41_V(PFNGLVIEWPORTINDEXEDFPROC, "glViewportIndexedf", index, x, y, w, h); }

inline void glViewportIndexedfv(GLuint index, const GLfloat *v) { CALLGL41_V(PFNGLVIEWPORTINDEXEDFVPROC, "glViewportIndexedfv", index, v); }

inline void glScissorArrayv(GLuint first, GLsizei count, const GLint *v) { CALLGL41_V(PFNGLSCISSORARRAYVPROC, "glScissorArrayv", first, count, v); }

inline void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) { CALLGL41_V(PFNGLSCISSORINDEXEDPROC, "glScissorIndexed", index, left, bottom, width, height); }

inline void glScissorIndexedv(GLuint index, const GLint *v) { CALLGL41_V(PFNGLSCISSORINDEXEDVPROC, "glScissorIndexedv", index, v); }
