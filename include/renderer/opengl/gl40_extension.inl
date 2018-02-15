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


inline void glGetUniformdv(GLuint program, GLint location, GLdouble *params) { CALLGL40(PFNGLGETUNIFORMDVPROC, "glGetUniformdv", program, location, params); }

inline void glBlendEquationi(GLuint buf, GLenum mode) { CALLGL40(PFNGLBLENDEQUATIONIPROC, "glBlendEquationi", buf, mode); }

inline void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) { CALLGL40(PFNGLBLENDEQUATIONSEPARATEIPROC, "glBlendEquationSeparatei", buf, modeRGB, modeAlpha); }

inline void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { CALLGL40(PFNGLBLENDFUNCSEPARATEIPROC, "glBlendFuncSeparatei", buf, srcRGB, dstRGB, srcAlpha, dstAlpha); }

inline void glBlendFunci(GLuint buf, GLenum sfactor, GLenum dfactor) { CALLGL40(PFNGLBLENDFUNCIPROC, "glBlendFunci", buf, sfactor, dfactor); }

inline void glDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid *indirect) { CALLGL40(PFNGLDRAWELEMENTSINDIRECTPROC, "glDrawElementsIndirect", mode, type, indirect); }

inline void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) { CALLGL40(PFNGLBEGINQUERYINDEXEDPROC, "glBeginQueryIndexed", target, index, id); }

inline void glEndQueryIndexed(GLenum target, GLuint index) { CALLGL40(PFNGLENDQUERYINDEXEDPROC, "glEndQueryIndexed", target, index); }

inline void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint * params) { CALLGL40(PFNGLGETQUERYINDEXEDIVPROC, "glGetQueryIndexediv", target, index, pname, params); }

inline GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name)
	{ CALLGL40(PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC, "glGetSubroutineUniformLocation", program, shadertype, name); }

inline GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name) { CALLGL40(PFNGLGETSUBROUTINEINDEXPROC, "glGetSubroutineIndex", program, shadertype, name); }

inline void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name)
	{ CALLGL40(PFNGLGETACTIVESUBROUTINENAMEPROC, "glGetActiveSubroutineName", program, shadertype, index, bufsize, length, name); }

inline void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name)
	{ CALLGL40(PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC, "glGetActiveSubroutineUniformName", program, shadertype, index, bufsize, length, name); }

inline void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values)
	{ CALLGL40(PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC, "glGetActiveSubroutineUniformiv", program, shadertype, index, pname, values); }

inline void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices) { CALLGL40(PFNGLUNIFORMSUBROUTINESUIVPROC, "glUniformSubroutinesuiv", shadertype, count, indices); }

inline void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint * values) { CALLGL40(PFNGLGETUNIFORMSUBROUTINEUIVPROC, "glGetUniformSubroutineuiv", shadertype, location, values); }

inline void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values) { CALLGL40(PFNGLGETPROGRAMSTAGEIVPROC, "glGetProgramStageiv", program, shadertype, pname, values); }

inline void glPatchParameteri(GLenum pname, GLint value) { CALLGL40(PFNGLPATCHPARAMETERIPROC, "glPatchParameteri", pname, value); }

inline  void glPatchParameterfv(GLenum pname, const GLfloat *values) { CALLGL40(PFNGLPATCHPARAMETERFVPROC, "glPatchParameterfv", pname, values); }

inline  void glDrawArraysIndirect(GLenum mode, const void * indirect) { CALLGL40(PFNGLDRAWARRAYSINDIRECTPROC, "glDrawArraysIndirect", mode, indirect); }

inline  void glGenTransformFeedbacks(GLsizei n, GLuint *ids) { CALLGL40(PFNGLGENTRANSFORMFEEDBACKSPROC, "glGenTransformFeedbacks", n, ids); }

inline  void glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids) { CALLGL40(PFNGLDELETETRANSFORMFEEDBACKSPROC, "glDeleteTransformFeedbacks", n, ids); }

inline  GLboolean glIsTransformFeedback(GLuint id) { CALLGL40(PFNGLISTRANSFORMFEEDBACKPROC, "glIsTransformFeedback", id); }

inline  void glBindTransformFeedback(GLenum target, GLuint id) { CALLGL40(PFNGLBINDTRANSFORMFEEDBACKPROC, "glBindTransformFeedback", target, id); }

inline  void glPauseTransformFeedback() { CALLGL40(PFNGLPAUSETRANSFORMFEEDBACKPROC, "glPauseTransformFeedback"); }

inline  void glResumeTransformFeedback() { CALLGL40(PFNGLRESUMETRANSFORMFEEDBACKNVPROC, "glResumeTransformFeedback"); }

inline  void glDrawTransformFeedback(GLenum mode, GLuint id) { CALLGL40(PFNGLDRAWTRANSFORMFEEDBACKPROC, "glDrawTransformFeedback", mode, id); }

inline  void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) { CALLGL40(PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC, "glDrawTransformFeedbackStream", mode, id, stream); }

inline  void glMinSampleShading(GLfloat value) { CALLGL40(PFNGLMINSAMPLESHADINGPROC, "glMinSampleShading", value); }