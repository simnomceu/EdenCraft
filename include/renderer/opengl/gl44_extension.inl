inline void glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLintptr *sizes)
	{ CALLGL44(PFNGLBINDBUFFERSRANGEPROC, "glBindBuffersRange", target, first, count, buffers, offsets, sizes); }

inline void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint *buffers) { CALLGL44(PFNGLBINDBUFFERSBASEPROC, "glBindBuffersBase", target, first, count, buffers); }

inline void glBufferStorage(GLenum target, GLsizeiptr size, const GLvoid * data, GLbitfield flags) { CALLGL44(PFNGLBUFFERSTORAGEPROC, "glBufferStorage", target, size, data, flags); }

inline void glBindTextures(GLuint first, GLsizei count, const GLuint *textures) { CALLGL44(PFNGLBINDTEXTURESPROC, "glBindTextures", first, count, textures); }

inline void glBindSamplers(GLuint first, GLsizei count, const GLuint *samplers) { CALLGL44(PFNGLBINDSAMPLERSPROC, "glBindSamplers", first, count, samplers); }

inline void glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL44(PFNGLCLEARTEXSUBIMAGEPROC, "glClearTexSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data); }

inline void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const GLvoid * data) { CALLGL44(PFNGLCLEARTEXIMAGEPROC, "glClearTexImage", texture, level, format, type, data); }

inline void glBindImageTextures(GLuint first, GLsizei count, const GLuint *textures) { CALLGL44(PFNGLBINDIMAGETEXTURESPROC, "glBindImageTextures", first, count, textures); }

inline void glBindVertexBuffers(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides)
	{ CALLGL44(PFNGLBINDVERTEXBUFFERSPROC, "glBindVertexBuffers", first, count, buffers, offsets, strides); }