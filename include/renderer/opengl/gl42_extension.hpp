#ifndef GL42_EXTENSION_HPP
#define GL42_EXTENSION_HPP

#include <GL/glcorearb.h>

void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
void glMemoryBarrier(GLbitfield barriers);
void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance);
void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices, GLsizei primcount, GLuint baseinstance);
void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, GLvoid *indices, GLsizei primcount, GLint basevertex, GLuint baseinstance);
void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei primcount);
void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei primcount);
void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);

#include "renderer/opengl/gl42_extension.inl"

#endif // GL42_EXTENSION_HPP