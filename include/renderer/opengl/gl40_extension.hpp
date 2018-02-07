#ifndef GL40_EXTENSION_HPP
#define GL40_EXTENSION_HPP

#include <GL/glcorearb.h>

void glGetUniformdv(GLuint program, GLint location, GLdouble *params);
void glBlendEquationi(GLuint buf, GLenum mode);
void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glBlendFunci(GLuint buf, GLenum sfactor, GLenum dfactor);
void glDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid *indirect);
void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id);
void glEndQueryIndexed(GLenum target, GLuint index);
void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint * params);
GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name);
GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name);
void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices);
void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *values);
void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
void glPatchParameteri(GLenum pname, GLint value);
 void glPatchParameterfv(GLenum pname, const GLfloat *values);
 void glDrawArraysIndirect(GLenum mode, const void *indirect);
 void glGenTransformFeedbacks(GLsizei n, GLuint *ids);
 void glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids);
 GLboolean glIsTransformFeedback(GLuint id);
 void glBindTransformFeedback(GLenum target, GLuint id);
 void glPauseTransformFeedback();
 void glResumeTransformFeedback();
 void glDrawTransformFeedback(GLenum mode, GLuint id);
 void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
 void glMinSampleShading(GLfloat value);

#include "renderer/opengl/gl40_extension.inl"

#endif // GL40_EXTENSION_HPP