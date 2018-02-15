#ifndef GL44_EXTENSION_HPP
#define GL44_EXTENSION_HPP

#include <GL/glcorearb.h>

#include "utility/indexing/version.hpp"
#include "renderer/opengl/extension_loader.hpp"
#include "renderer/opengl/opengl_exception.hpp"

inline void glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLintptr *sizes);
inline void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
inline void glBufferStorage(GLenum target, GLsizeiptr size, const GLvoid * data, GLbitfield flags);
inline void glBindTextures(GLuint first, GLsizei count, const GLuint *textures);
inline void glBindSamplers(GLuint first, GLsizei count, const GLuint *samplers);
inline void glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * data);
inline void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const GLvoid * data);
inline void glBindImageTextures(GLuint first, GLsizei count, const GLuint *textures);
inline void glBindVertexBuffers(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);

#define CALLGL44(SIGNATURE, NAME, ...) \
	static auto proxy = ece::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 4 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy(__VA_ARGS__);

#include "renderer/opengl/gl44_extension.inl"

#endif // GL44_EXTENSION_HPP