inline void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params)
	{ CALLGL42(PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC, "glGetActiveAtomicCounterBufferiv", program, bufferIndex, pname, params); }

inline void glMemoryBarrier(GLbitfield barriers) { CALLGL42(PFNGLMEMORYBARRIERPROC, "glMemoryBarrier", barriers); }

inline void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) { CALLGL42(PFNGLTEXSTORAGE1DPROC, "glTexStorage1D", target, levels, internalformat, width); }

inline void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
	{ CALLGL42(PFNGLTEXSTORAGE2DPROC, "glTexStorage2D", target, levels, internalformat, width, height); }

inline void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
	{ CALLGL42(PFNGLTEXSTORAGE3DPROC, "glTexStorage3D", target, levels, internalformat, width, height, depth); }

inline void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)
	{ CALLGL42(PFNGLBINDIMAGETEXTUREPROC, "glBindImageTexture", unit, texture, level, layered, layer, access, format); }

inline void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance)
	{ CALLGL42(PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC, "glDrawArraysInstancedBaseInstance", mode, first, count, primcount, baseinstance); }

inline void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices, GLsizei primcount, GLuint baseinstance)
	{ CALLGL42(PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC, "glDrawElementsInstancedBaseInstance", mode, count, type, indices, primcount, baseinstance); }

inline void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, GLvoid *indices, GLsizei primcount, GLint basevertex, GLuint baseinstance)
	{ CALLGL42(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC, "glDrawElementsInstancedBaseVertexBaseInstance", mode, count, type, indices, primcount, basevertex, baseinstance); }

inline void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei primcount) { CALLGL42(PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC, "glDrawTransformFeedbackInstanced", mode, id, primcount); }

inline void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei primcount)
	{ CALLGL42(PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC, "glDrawTransformFeedbackStreamInstanced", mode, id, stream, primcount); }

inline void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params)
	{ CALLGL42(PFNGLGETINTERNALFORMATIVPROC, "glGetInternalformativ", target, internalformat, pname, bufSize, params); }