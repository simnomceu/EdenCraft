#ifndef GL41_EXTENSION_HPP
#define GL41_EXTENSION_HPP

#include <GL/glcorearb.h>

void glVertexAttribL1d(GLuint index, GLdouble v0);
void glVertexAttribL2d(GLuint index, GLdouble v0, GLdouble v1);
void glVertexAttribL3d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2);
void glVertexAttribL4d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
void glVertexAttribL1dv(GLuint index, const GLdouble * v);
void glVertexAttribL2dv(GLuint index, const GLdouble * v);
void glVertexAttribL3dv(GLuint index, const GLdouble * v);
void glVertexAttribL4dv(GLuint index, const GLdouble * v);
void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
void glDepthRangef(GLfloat nearVal, GLfloat farVal);
void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params);
void glClearDepthf(GLfloat depth);
void glGetFloati_v(GLenum target, GLuint index, GLfloat * data);
void glGetDoublei_v(GLenum target, GLuint index, GLdouble * data);

#endif // GL41_EXTENSION_HPP