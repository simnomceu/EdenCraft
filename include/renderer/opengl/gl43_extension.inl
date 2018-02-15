inline void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL43(PFNGLCLEARBUFFERSUBDATAPROC, "glClearBufferSubData", target, internalformat, offset, size, format, type, data); }

inline void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL43(PFNGLCLEARBUFFERDATAPROC, "glClearBufferData", target, internalformat, format, type, data); }

inline void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) { CALLGL43(PFNGLINVALIDATEBUFFERSUBDATAPROC, "glInvalidateBufferSubData", buffer, offset, length); }

inline void glInvalidateBufferData(GLuint buffer) { CALLGL43(PFNGLINVALIDATEBUFFERDATAPROC, "glInvalidateBufferData", buffer); }

inline void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint * params)
	{ CALLGL43(PFNGLGETPROGRAMINTERFACEIVPROC, "glGetProgramInterfaceiv", program, programInterface, pname, params); }

inline GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar * name)
	{ CALLGL43(PFNGLGETPROGRAMRESOURCEINDEXPROC, "glGetProgramResourceIndex", program, programInterface, name); }

inline void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name)
	{ CALLGL43(PFNGLGETPROGRAMRESOURCENAMEPROC, "glGetProgramResourceName", program, programInterface, index, bufSize, length, name); }

inline void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params)
	{ CALLGL43(PFNGLGETPROGRAMRESOURCEIVPROC, "glGetProgramResourceiv", program, programInterface, index, propCount, props, bufSize, length, params); }

inline GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar * name)
	{ CALLGL43(PFNGLGETPROGRAMRESOURCELOCATIONPROC, "glGetProgramResourceLocation", program, programInterface, name); }

inline GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar * name)
	{ CALLGL43(PFNGLGETPROGRAMRESOURCELOCATIONPROC, "glGetProgramResourceLocationIndex", program, programInterface, name); }

inline void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding)
	{ CALLGL43(PFNGLSHADERSTORAGEBLOCKBINDINGPROC, "glShaderStorageBlockBinding", program, storageBlockIndex, storageBlockBinding); }

inline void glGetPointerv(GLenum pname, GLvoid ** params) { CALLGL43(PFNGLGETPOINTERVPROC, "glGetPointerv", pname, params); }

inline void glTexBufferRange(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size)
	{ CALLGL43(PFNGLTEXBUFFERRANGEPROC, "glTexBufferRange", target, internalFormat, buffer, offset, size); }

inline void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)
	{ CALLGL43(PFNGLTEXTUREVIEWPROC, "glTextureView", texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers); }

inline void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
	{ CALLGL43(PFNGLTEXSTORAGE2DMULTISAMPLEPROC, "glTexStorage2DMultisample", target, samples, internalformat, width, height, fixedsamplelocations); }

inline void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
	{ CALLGL43(PFNGLTEXSTORAGE3DMULTISAMPLEPROC, "glTexStorage3DMultisample", target, samples, internalformat, width, height, depth, fixedsamplelocations); }

inline void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth)
	{ CALLGL43(PFNGLINVALIDATETEXSUBIMAGEPROC, "glInvalidateTexSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth); }

inline void glInvalidateTexImage(GLuint texture, GLint level) { CALLGL43(PFNGLINVALIDATETEXIMAGEPROC, "glInvalidateTexImage", texture, level); }

inline void glFramebufferParameteri(GLenum target, GLenum pname, GLint param) { CALLGL43(PFNGLFRAMEBUFFERPARAMETERIPROC, "glFramebufferParameteri", target, pname, param); }

inline void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params) { CALLGL43(PFNGLGETFRAMEBUFFERPARAMETERIVPROC, "glGetFramebufferParameteriv", target, pname, params); }

inline void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
	{ CALLGL43(PFNGLVERTEXATTRIBFORMATPROC, "glVertexAttribFormat", attribindex, size, type, normalized, relativeoffset); }

inline void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	{ CALLGL43(PFNGLVERTEXATTRIBIFORMATPROC, "glVertexAttribIFormat", attribindex, size, type, relativeoffset); }

inline void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	{ CALLGL43(PFNGLVERTEXATTRIBLFORMATPROC, "glVertexAttribLFormat", attribindex, size, type, relativeoffset); }

inline void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLintptr stride) { CALLGL43(PFNGLBINDVERTEXBUFFERPROC, "glBindVertexBuffer", bindingindex, buffer, offset, stride); }

inline void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) { CALLGL43(PFNGLVERTEXATTRIBBINDINGPROC, "glVertexAttribBinding", attribindex, bindingindex); }

inline void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) { CALLGL43(PFNGLVERTEXBINDINGDIVISORPROC, "glVertexBindingDivisor", bindingindex, divisor); }

inline void glMultiDrawArraysIndirect(GLenum mode, const GLvoid *indirect, GLsizei drawcount, GLsizei stride)
	{ CALLGL43(PFNGLMULTIDRAWARRAYSINDIRECTPROC, "glMultiDrawArraysIndirect", mode, indirect, drawcount, stride); }

inline void glMultiDrawArraysIndirectCount(GLenum mode, const GLvoid *indirect, GLintptr drawcount, GLintptr maxdrawcount, GLsizei stride)
	{ CALLGL43(PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC, "glMultiDrawArraysIndirectCount", mode, indirect, drawcount, maxdrawcount, stride); }

inline void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid *indirect, GLsizei drawcount, GLsizei stride)
	{ CALLGL43(PFNGLMULTIDRAWELEMENTSINDIRECTPROC, "glMultiDrawElementsIndirect", mode, type, indirect, drawcount, stride); }

inline void glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const GLvoid *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
	{ CALLGL43(PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC, "glMultiDrawElementsIndirectCount", mode, type, indirect, drawcount, maxdrawcount, stride); }

inline void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) { CALLGL43(PFNGLDISPATCHCOMPUTEPROC, "glDispatchCompute", num_groups_x, num_groups_y, num_groups_z); }

inline void glDispatchComputeIndirect(GLintptr indirect) { CALLGL43(PFNGLDISPATCHCOMPUTEINDIRECTPROC, "glDispatchComputeIndirect", indirect); }

inline void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLint width, GLint height)
	{ CALLGL43(PFNGLINVALIDATESUBFRAMEBUFFERPROC, "glInvalidateSubFramebuffer", target, numAttachments, attachments,x , y, width, height); }

inline void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments)
	{ CALLGL43(PFNGLINVALIDATEFRAMEBUFFERPROC, "glInvalidateFramebuffer", target, numAttachments, attachments); }

inline void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY,
								GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)
	{ CALLGL43(PFNGLCOPYIMAGESUBDATAPROC, "glCopyImageSubData", srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth); }

inline void glDebugMessageCallback(GLDEBUGPROC callback, const GLvoid * userParam) { CALLGL43(PFNGLDEBUGMESSAGECALLBACKPROC, "glDebugMessageCallback", callback, userParam); }

inline void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)
	{ CALLGL43(PFNGLDEBUGMESSAGECONTROLPROC, "glDebugMessageControl", source, type, severity, count, ids, enabled); }

inline void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message)
	{ CALLGL43(PFNGLDEBUGMESSAGEINSERTPROC, "glDebugMessageInsert", source, type, id, severity, length, message); }

inline void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar * message) { CALLGL43(PFNGLPUSHDEBUGGROUPPROC, "glPushDebugGroup", source, id, length, message); }

inline void glPopDebugGroup() { CALLGL43(PFNGLPOPDEBUGGROUPPROC, "glPopDebugGroup"); }

inline void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar * label) { CALLGL43(PFNGLOBJECTLABELPROC, "glObjectLabel", identifier, name, length, label); }

inline void glObjectPtrLabel(GLvoid * ptr, GLsizei length, const GLchar * label) { CALLGL43(PFNGLOBJECTPTRLABELPROC, "glObjectPtrLabel", ptr, length, label); }

inline GLuint glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog)
	{ CALLGL43(PFNGLGETDEBUGMESSAGELOGPROC, "glGetDebugMessageLog", count, bufSize, sources, types, ids, severities, lengths, messageLog); }

inline void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bifSize, GLsizei * length, GLchar * label)
	{ CALLGL43(PFNGLGETOBJECTLABELPROC, "glGetObjectLabel", identifier, name, bifSize, length, label); }

inline void glGetObjectPtrLabel(GLvoid * ptr, GLsizei bifSize, GLsizei * length, GLchar * label) { CALLGL43(PFNGLGETOBJECTPTRLABELPROC, "glGetObjectPtrLabel", ptr, bifSize, length, label); }

inline void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params)
	{ CALLGL43(PFNGLGETINTERNALFORMATI64VPROC, "glGetInternalformati64v", target, internalformat, pname, bufSize, params); }