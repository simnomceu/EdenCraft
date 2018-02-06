#ifndef GL44_EXTENSION_HPP
#define GL44_EXTENSION_HPP

#include <GL/glcorearb.h>

void glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLintptr *sizes);
void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
void glBufferStorage(GLenum target, GLsizeiptr size, const GLvoid * data, GLbitfield flags);

#endif // GL44_EXTENSION_HPP