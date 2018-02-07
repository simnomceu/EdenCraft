#ifndef GL44_EXTENSION_HPP
#define GL44_EXTENSION_HPP

#include <GL/glcorearb.h>

void glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLintptr *sizes);
void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
void glBufferStorage(GLenum target, GLsizeiptr size, const GLvoid * data, GLbitfield flags);
void glBindTextures(GLuint first, GLsizei count, const GLuint *textures);
void glBindSamplers(GLuint first, GLsizei count, const GLuint *samplers);
void glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * data);
void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const GLvoid * data);
void glBindImageTextures(GLuint first, GLsizei count, const GLuint *textures);
void glBindVertexBuffers(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);

#include "renderer/opengl/gl44_extension.inl"

#endif // GL44_EXTENSION_HPP