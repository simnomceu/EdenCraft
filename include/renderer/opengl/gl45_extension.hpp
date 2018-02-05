#ifndef GL45_EXTENSION_HPP
#define GL45_EXTENSION_HPP

#include <GL/glcorearb.h>

void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index);
void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index);
void glNamedBufferData(GLuint buffer, GLsizei size, const void *data, GLenum usage);
void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizei size, const void *data);
void * glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizei length, GLbitfield access);
void * glMapNamedBuffer(GLuint buffer, GLenum access);
void glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizei length);
GLboolean glUnmapNamedBuffer(GLuint buffer);
void glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizei size);
void glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint * params);
void glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 * params);
void glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizei size, void *data);
void glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void ** params);
void glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
void glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint *params);
void glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
void glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
void glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
void glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
void glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
void glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
void glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
void glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
void glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer);
void glTextureParameterf(GLuint texture, GLenum pname, GLfloat param);
void glTextureParameteri(GLuint texture, GLenum pname, GLint param);
void glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat *param);
void glTextureParameteriv(GLuint texture, GLenum pname, const GLint *param);
void glTextureParameterIiv(GLuint texture, GLenum pname, const GLint *params);
void glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint *params);
void glGenerateTextureMipmap(GLuint texture);
void glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat *params);
void glGetTextureParameteriv(GLuint texture, GLenum pname, GLint *params);
void glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint *params);
void glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint *params);
void glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat *params);
void glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint *params);
void glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
void glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
void glGetnCompressedTexImage(GLenum target, GLint level, GLsizei bufSize, void *pixels);
void glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
void glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
void glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum mode);
void glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
void glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf);
void glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum *bufs);
void glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
void glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
void glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
void glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
void glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
void glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
void glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLenum glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target);
void glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
void glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint *params);

#endif // GL45_EXTENSION_HPP