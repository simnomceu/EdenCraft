/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/


inline void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL43_V(PFNGLCLEARBUFFERSUBDATAPROC, "glClearBufferSubData", target, internalformat, offset, size, format, type, data); }

inline void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL43_V(PFNGLCLEARBUFFERDATAPROC, "glClearBufferData", target, internalformat, format, type, data); }

inline void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) { CALLGL43_V(PFNGLINVALIDATEBUFFERSUBDATAPROC, "glInvalidateBufferSubData", buffer, offset, length); }

inline void glInvalidateBufferData(GLuint buffer) { CALLGL43_V(PFNGLINVALIDATEBUFFERDATAPROC, "glInvalidateBufferData", buffer); }

inline void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint * params)
	{ CALLGL43_V(PFNGLGETPROGRAMINTERFACEIVPROC, "glGetProgramInterfaceiv", program, programInterface, pname, params); }

inline GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar * name)
	{ CALLGL43_V(PFNGLGETPROGRAMRESOURCEINDEXPROC, "glGetProgramResourceIndex", program, programInterface, name); }

inline void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name)
	{ CALLGL43_V(PFNGLGETPROGRAMRESOURCENAMEPROC, "glGetProgramResourceName", program, programInterface, index, bufSize, length, name); }

inline void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params)
	{ CALLGL43_V(PFNGLGETPROGRAMRESOURCEIVPROC, "glGetProgramResourceiv", program, programInterface, index, propCount, props, bufSize, length, params); }

inline GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar * name)
	{ CALLGL43_V(PFNGLGETPROGRAMRESOURCELOCATIONPROC, "glGetProgramResourceLocation", program, programInterface, name); }

inline GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar * name)
	{ CALLGL43_V(PFNGLGETPROGRAMRESOURCELOCATIONPROC, "glGetProgramResourceLocationIndex", program, programInterface, name); }

inline void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding)
	{ CALLGL43_V(PFNGLSHADERSTORAGEBLOCKBINDINGPROC, "glShaderStorageBlockBinding", program, storageBlockIndex, storageBlockBinding); }

inline void glGetPointerv(GLenum pname, GLvoid ** params) { CALLGL43_V(PFNGLGETPOINTERVPROC, "glGetPointerv", pname, params); }

inline void glTexBufferRange(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size)
	{ CALLGL43_V(PFNGLTEXBUFFERRANGEPROC, "glTexBufferRange", target, internalFormat, buffer, offset, size); }

inline void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)
	{ CALLGL43_V(PFNGLTEXTUREVIEWPROC, "glTextureView", texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers); }

inline void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
	{ CALLGL43_V(PFNGLTEXSTORAGE2DMULTISAMPLEPROC, "glTexStorage2DMultisample", target, samples, internalformat, width, height, fixedsamplelocations); }

inline void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
	{ CALLGL43_V(PFNGLTEXSTORAGE3DMULTISAMPLEPROC, "glTexStorage3DMultisample", target, samples, internalformat, width, height, depth, fixedsamplelocations); }

inline void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth)
	{ CALLGL43_V(PFNGLINVALIDATETEXSUBIMAGEPROC, "glInvalidateTexSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth); }

inline void glInvalidateTexImage(GLuint texture, GLint level) { CALLGL43_V(PFNGLINVALIDATETEXIMAGEPROC, "glInvalidateTexImage", texture, level); }

inline void glFramebufferParameteri(GLenum target, GLenum pname, GLint param) { CALLGL43_V(PFNGLFRAMEBUFFERPARAMETERIPROC, "glFramebufferParameteri", target, pname, param); }

inline void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params) { CALLGL43_V(PFNGLGETFRAMEBUFFERPARAMETERIVPROC, "glGetFramebufferParameteriv", target, pname, params); }

inline void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
	{ CALLGL43_V(PFNGLVERTEXATTRIBFORMATPROC, "glVertexAttribFormat", attribindex, size, type, normalized, relativeoffset); }

inline void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	{ CALLGL43_V(PFNGLVERTEXATTRIBIFORMATPROC, "glVertexAttribIFormat", attribindex, size, type, relativeoffset); }

inline void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	{ CALLGL43_V(PFNGLVERTEXATTRIBLFORMATPROC, "glVertexAttribLFormat", attribindex, size, type, relativeoffset); }

inline void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLintptr stride) { CALLGL43_V(PFNGLBINDVERTEXBUFFERPROC, "glBindVertexBuffer", bindingindex, buffer, offset, stride); }

inline void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) { CALLGL43_V(PFNGLVERTEXATTRIBBINDINGPROC, "glVertexAttribBinding", attribindex, bindingindex); }

inline void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) { CALLGL43_V(PFNGLVERTEXBINDINGDIVISORPROC, "glVertexBindingDivisor", bindingindex, divisor); }

inline void glMultiDrawArraysIndirect(GLenum mode, const GLvoid *indirect, GLsizei drawcount, GLsizei stride)
	{ CALLGL43_V(PFNGLMULTIDRAWARRAYSINDIRECTPROC, "glMultiDrawArraysIndirect", mode, indirect, drawcount, stride); }

inline void glMultiDrawArraysIndirectCount(GLenum mode, const GLvoid *indirect, GLintptr drawcount, GLintptr maxdrawcount, GLsizei stride)
	{ CALLGL43_V(PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC, "glMultiDrawArraysIndirectCount", mode, indirect, drawcount, maxdrawcount, stride); }

inline void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid *indirect, GLsizei drawcount, GLsizei stride)
	{ CALLGL43_V(PFNGLMULTIDRAWELEMENTSINDIRECTPROC, "glMultiDrawElementsIndirect", mode, type, indirect, drawcount, stride); }

inline void glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const GLvoid *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
	{ CALLGL43_V(PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC, "glMultiDrawElementsIndirectCount", mode, type, indirect, drawcount, maxdrawcount, stride); }

inline void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) { CALLGL43_V(PFNGLDISPATCHCOMPUTEPROC, "glDispatchCompute", num_groups_x, num_groups_y, num_groups_z); }

inline void glDispatchComputeIndirect(GLintptr indirect) { CALLGL43_V(PFNGLDISPATCHCOMPUTEINDIRECTPROC, "glDispatchComputeIndirect", indirect); }

inline void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLint width, GLint height)
	{ CALLGL43_V(PFNGLINVALIDATESUBFRAMEBUFFERPROC, "glInvalidateSubFramebuffer", target, numAttachments, attachments,x , y, width, height); }

inline void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments)
	{ CALLGL43_V(PFNGLINVALIDATEFRAMEBUFFERPROC, "glInvalidateFramebuffer", target, numAttachments, attachments); }

inline void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY,
								GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)
	{ CALLGL43_V(PFNGLCOPYIMAGESUBDATAPROC, "glCopyImageSubData", srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth); }

inline void glDebugMessageCallback(GLDEBUGPROC callback, const GLvoid * userParam) { CALLGL43_V(PFNGLDEBUGMESSAGECALLBACKPROC, "glDebugMessageCallback", callback, userParam); }

inline void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)
	{ CALLGL43_V(PFNGLDEBUGMESSAGECONTROLPROC, "glDebugMessageControl", source, type, severity, count, ids, enabled); }

inline void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message)
	{ CALLGL43_V(PFNGLDEBUGMESSAGEINSERTPROC, "glDebugMessageInsert", source, type, id, severity, length, message); }

inline void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar * message) { CALLGL43_V(PFNGLPUSHDEBUGGROUPPROC, "glPushDebugGroup", source, id, length, message); }

inline void glPopDebugGroup() { CALLGL43(PFNGLPOPDEBUGGROUPPROC, "glPopDebugGroup"); }

inline void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar * label) { CALLGL43_V(PFNGLOBJECTLABELPROC, "glObjectLabel", identifier, name, length, label); }

inline void glObjectPtrLabel(GLvoid * ptr, GLsizei length, const GLchar * label) { CALLGL43_V(PFNGLOBJECTPTRLABELPROC, "glObjectPtrLabel", ptr, length, label); }

inline GLuint glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog)
	{ CALLGL43_V(PFNGLGETDEBUGMESSAGELOGPROC, "glGetDebugMessageLog", count, bufSize, sources, types, ids, severities, lengths, messageLog); }

inline void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bifSize, GLsizei * length, GLchar * label)
	{ CALLGL43_V(PFNGLGETOBJECTLABELPROC, "glGetObjectLabel", identifier, name, bifSize, length, label); }

inline void glGetObjectPtrLabel(GLvoid * ptr, GLsizei bifSize, GLsizei * length, GLchar * label) { CALLGL43_V(PFNGLGETOBJECTPTRLABELPROC, "glGetObjectPtrLabel", ptr, bifSize, length, label); }

inline void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params)
	{ CALLGL43_V(PFNGLGETINTERNALFORMATI64VPROC, "glGetInternalformati64v", target, internalformat, pname, bufSize, params); }
