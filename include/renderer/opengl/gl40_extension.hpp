#ifndef GL40_EXTENSION_HPP
#define GL40_EXTENSION_HPP

#include <GL/glcorearb.h>

void glGetUniformdv(GLuint program, GLint location, GLdouble *params);
void glBlendEquationi(GLuint buf, GLenum mode);
void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glBlendFunci(GLuint buf, GLenum sfactor, GLenum dfactor);

#endif // GL40_EXTENSION_HPP