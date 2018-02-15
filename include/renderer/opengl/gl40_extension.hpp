#ifndef GL40_EXTENSION_HPP
#define GL40_EXTENSION_HPP

#include <GL/glcorearb.h>

#include "utility/indexing/version.hpp"
#include "renderer/opengl/extension_loader.hpp"
#include "renderer/opengl/opengl_exception.hpp"

inline void glGetUniformdv(GLuint program, GLint location, GLdouble *params);
inline void glBlendEquationi(GLuint buf, GLenum mode);
inline void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
inline void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
inline void glBlendFunci(GLuint buf, GLenum sfactor, GLenum dfactor);
inline void glDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid *indirect);
inline void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id);
inline void glEndQueryIndexed(GLenum target, GLuint index);
inline void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint * params);
inline GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name);
inline GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name);
inline void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
inline void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
inline void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
inline void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices);
inline void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *values);
inline void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
inline void glPatchParameteri(GLenum pname, GLint value);
inline  void glPatchParameterfv(GLenum pname, const GLfloat *values);
inline  void glDrawArraysIndirect(GLenum mode, const void *indirect);
inline  void glGenTransformFeedbacks(GLsizei n, GLuint *ids);
inline  void glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids);
inline  GLboolean glIsTransformFeedback(GLuint id);
inline  void glBindTransformFeedback(GLenum target, GLuint id);
inline  void glPauseTransformFeedback();
inline  void glResumeTransformFeedback();
inline  void glDrawTransformFeedback(GLenum mode, GLuint id);
inline  void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
inline  void glMinSampleShading(GLfloat value);

#define CALLGL40(SIGNATURE, NAME, ...) \
	static auto proxy = ece::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 0 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy(__VA_ARGS__);

#include "renderer/opengl/gl40_extension.inl"

#endif // GL40_EXTENSION_HPP