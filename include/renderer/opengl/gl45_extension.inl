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


inline void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index) { CALLGL45(PFNGLENABLEVERTEXARRAYATTRIBPROC, "glEnableVertexArrayAttrib", vaobj, index); }

inline void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index) { CALLGL45(PFNGLDISABLEVERTEXARRAYATTRIBPROC, "glDisableVertexArrayAttrib", vaobj, index); }

inline void glNamedBufferData(GLuint buffer, GLsizei size, const GLvoid * data, GLenum usage) { CALLGL45(PFNGLNAMEDBUFFERDATAPROC, "glNamedBufferData", buffer, size, data, usage); }

inline void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizei size, const GLvoid * data) { CALLGL45(PFNGLNAMEDBUFFERSUBDATAPROC, "glNamedBufferSubData", buffer, offset, size, data); }

inline void * glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizei length, GLbitfield access) { CALLGL45(PFNGLMAPNAMEDBUFFERRANGEPROC, "glMapNamedBufferRange", buffer, offset, length, access); }

inline void * glMapNamedBuffer(GLuint buffer, GLenum access) { CALLGL45(PFNGLMAPNAMEDBUFFERPROC, "glMapNamedBuffer", buffer, access); }

inline void glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizei length) { CALLGL45(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC, "glFlushMappedNamedBufferRange", buffer, offset, length); }

inline GLboolean glUnmapNamedBuffer(GLuint buffer) { CALLGL45(PFNGLUNMAPNAMEDBUFFERPROC, "glUnmapNamedBuffer", buffer); }

inline void glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizei size) 
	{ CALLGL45(PFNGLCOPYNAMEDBUFFERSUBDATAPROC, "glCopyNamedBufferSubData", readBuffer, writeBuffer, readOffset, writeOffset, size); }

inline void glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint * params) { CALLGL45(PFNGLGETNAMEDBUFFERPARAMETERIVPROC, "glGetNamedBufferParameteriv", buffer, pname, params); }

inline void glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 * params) { CALLGL45(PFNGLGETNAMEDBUFFERPARAMETERI64VPROC, "glGetNamedBufferParameteri64v", buffer, pname, params); }

inline void glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizei size, GLvoid * data) { CALLGL45(PFNGLGETNAMEDBUFFERSUBDATAPROC, "glGetNamedBufferSubData", buffer, offset, size, data); }

inline void glGetNamedBufferPointerv(GLuint buffer, GLenum pname, GLvoid ** params) { CALLGL45(PFNGLGETNAMEDBUFFERPOINTERVPROC, "glGetNamedBufferPointerv", buffer, pname, params); }

inline void glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat * params) { CALLGL45(PFNGLGETNUNIFORMFVPROC, "glGetnUniformfv", program, location, bufSize, params); }

inline void glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint * params) { CALLGL45(PFNGLGETNUNIFORMIVPROC, "glGetnUniformiv", program, location, bufSize, params); }

inline void glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint * params) { CALLGL45(PFNGLGETNUNIFORMUIVPROC, "glGetnUniformuiv", program, location, bufSize, params); }

inline void glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble * params) { CALLGL45(PFNGLGETNUNIFORMDVPROC, "glGetnUniformdv", program, location, bufSize, params); }

inline void glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels)
	{ CALLGL45(PFNGLTEXTURESUBIMAGE3DPROC, "glTextureSubImage3D", texture, level, xoffset, yoffset, zoffset, width ,height, depth, format, type, pixels); }

inline void glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels)
	{ CALLGL45(PFNGLTEXTURESUBIMAGE2DPROC, "glTextureSubImage2D", texture, level, xoffset, yoffset, width, height, format, type, pixels); }

inline void glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels)
	{ CALLGL45(PFNGLTEXTURESUBIMAGE1DPROC, "glTextureSubImage1D", texture, level, xoffset, width, format, type, pixels); }

inline void glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
	{ CALLGL45(PFNGLCOPYTEXTURESUBIMAGE3DPROC, "glCopyTextureSubImage3D", texture, level, xoffset, yoffset, zoffset, x, y, width, height); }

inline void glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
	{ CALLGL45(PFNGLCOPYTEXTURESUBIMAGE2DPROC, "glCopyTextureSubImage2D", texture, level, xoffset, yoffset, x, y, width, height); }

inline void glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
	{ CALLGL45(PFNGLCOPYTEXTURESUBIMAGE1DPROC, "glCopyTextureSubImage1D", texture, level, xoffset, x, y, width); }

inline void glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, 
											const GLvoid * data)
	{ CALLGL45(PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC, "glCompressedTextureSubImage3D", texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }

inline void glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) 
	{ CALLGL45(PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC, "glCompressedTextureSubImage2D", texture, level, xoffset, yoffset, width, height, format, imageSize, data); }

inline void glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data)
	{ CALLGL45(PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC, "glCompressedTextureSubImage1D", texture, level, xoffset, width, format, imageSize, data); }

inline void glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) { CALLGL45(PFNGLTEXTUREBUFFERPROC, "glTextureBuffer", texture, internalformat, buffer); }

inline void glTextureParameterf(GLuint texture, GLenum pname, GLfloat param) { CALLGL45(PFNGLTEXTUREPARAMETERFPROC, "glTextureParameterf", texture, pname, param); }

inline void glTextureParameteri(GLuint texture, GLenum pname, GLint param) { CALLGL45(PFNGLTEXTUREPARAMETERIPROC, "glTextureParameteri", texture, pname, param); }

inline void glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat * param) { CALLGL45(PFNGLTEXTUREPARAMETERFVPROC, "glTextureParameterfv", texture, pname, param); }

inline void glTextureParameteriv(GLuint texture, GLenum pname, const GLint * param) { CALLGL45(PFNGLTEXTUREPARAMETERIVPROC, "glTextureParameteriv", texture, pname, param); }

inline void glTextureParameterIiv(GLuint texture, GLenum pname, const GLint * params) { CALLGL45(PFNGLTEXTUREPARAMETERIIVPROC, "glTextureParameterIiv", texture, pname, params); }

inline void glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint * params) { CALLGL45(PFNGLTEXTUREPARAMETERIUIVPROC, "glTextureParameterIuiv", texture, pname, params); }

inline void glGenerateTextureMipmap(GLuint texture) { CALLGL45(PFNGLGENERATETEXTUREMIPMAPPROC, "glGenerateTextureMipmap", texture); }

inline void glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat * params) { CALLGL45(PFNGLGETTEXTUREPARAMETERFVPROC, "glGetTextureParameterfv", texture, pname, params); }

inline void glGetTextureParameteriv(GLuint texture, GLenum pname, GLint * params) { CALLGL45(PFNGLGETTEXTUREPARAMETERIVPROC, "glGetTextureParameteriv", texture, pname, params); }

inline void glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint * params) { CALLGL45(PFNGLGETTEXTUREPARAMETERIIVPROC, "glGetTextureParameterIiv", texture, pname, params); }

inline void glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint * params) { CALLGL45(PFNGLGETTEXTUREPARAMETERIUIVPROC, "glGetTextureParameterIuiv", texture, pname, params); }

inline void glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat * params)
	{ CALLGL45(PFNGLGETTEXTURELEVELPARAMETERFVPROC, "glGetTextureLevelParameterfv", texture, level, pname, params); }

inline void glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint * params)
	{ CALLGL45(PFNGLGETTEXTURELEVELPARAMETERIVPROC, "glGetTextureLevelParameteriv", texture, level, pname, params); }

inline void glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid * pixels)
	{ CALLGL45(PFNGLGETNTEXIMAGEPROC, "glGetnTexImage", target, level, format, type, bufSize, pixels); }

inline void glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid * pixels)
	{ CALLGL45(PFNGLGETTEXTUREIMAGEPROC, "glGetTextureImage", texture, level, format, type, bufSize, pixels); }

inline void glGetnCompressedTexImage(GLenum target, GLint level, GLsizei bufSize, GLvoid * pixels)
	{ CALLGL45(PFNGLGETNCOMPRESSEDTEXIMAGEPROC, "glGetnCompressedTexImage", target, level, bufSize, pixels); }

inline void glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, GLvoid * pixels)
	{ CALLGL45(PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC, "glGetCompressedTextureImage", texture, level, bufSize, pixels); }

inline void glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid * data)
	{ CALLGL45(PFNGLREADNPIXELSPROC, "glReadnPixels", x, y, width, height, format, type, bufSize, data); }

inline void glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum mode) { CALLGL45(PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC, "glNamedFramebufferReadBuffer", framebuffer, mode); }

inline void glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, 
									GLbitfield mask, GLenum filter)
	{ CALLGL45(PFNGLBLITNAMEDFRAMEBUFFERPROC, "glBlitNamedFramebuffer", readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }

inline void glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) { CALLGL45(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC, "glNamedFramebufferDrawBuffer", framebuffer, buf); }

inline void glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum * bufs) { CALLGL45(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC, "glNamedFramebufferDrawBuffers", framebuffer, n, bufs); }

inline void glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint * value)
	{ CALLGL45(PFNGLCLEARNAMEDFRAMEBUFFERIVPROC, "glClearNamedFramebufferiv", framebuffer, buffer, drawbuffer, value); }

inline void glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint * value)
	{ CALLGL45(PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC, "glClearNamedFramebufferuiv", framebuffer, buffer, drawbuffer, value); }

inline void glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value)
	{ CALLGL45(PFNGLCLEARNAMEDFRAMEBUFFERFVPROC, "glClearNamedFramebufferfv", framebuffer, buffer, drawbuffer, value); }

inline void glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
	{ CALLGL45(PFNGLCLEARNAMEDFRAMEBUFFERFIPROC, "glClearNamedFramebufferfi", framebuffer, buffer, drawbuffer, depth, stencil); }

inline void glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
	{ CALLGL45(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC, "glNamedRenderbufferStorageMultisample", renderbuffer, samples, internalformat, width, height); }

inline void glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height)
	{ CALLGL45(PFNGLNAMEDRENDERBUFFERSTORAGEPROC, "glNamedRenderbufferStorage", renderbuffer, internalformat, width, height); }

inline void glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
	{ CALLGL45(PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC, "glNamedFramebufferRenderbuffer", framebuffer, attachment, renderbuffertarget, renderbuffer); }

inline void glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level)
	{ CALLGL45(PFNGLNAMEDFRAMEBUFFERTEXTUREPROC, "glNamedFramebufferTexture", framebuffer, attachment, texture, level); }

inline void glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer)
	{ CALLGL45(PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC, "glNamedFramebufferTextureLayer", framebuffer, attachment, texture, level, layer); }

inline GLenum glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) { CALLGL45(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC, "glCheckNamedFramebufferStatus", framebuffer, target); }

inline void glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params)
	{ CALLGL45(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC, "glGetNamedFramebufferAttachmentParameteriv", framebuffer, attachment, pname, params); }

inline void glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint * params)
	{ CALLGL45(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC, "glGetNamedRenderbufferParameteriv", renderbuffer, pname, params); }

inline GLenum glGetGraphicsResetStatus() { CALLGL45(PFNGLGETGRAPHICSRESETSTATUSPROC, "glGetGraphicsResetStatus"); }

inline void glCreateBuffers(GLsizei n, GLuint * buffers) { CALLGL45(PFNGLCREATEBUFFERSPROC, "glCreateBuffers", n, buffers); }

inline void glNamedBufferStorage(GLuint buffer, GLsizei size, const GLvoid * data, GLbitfield flags) { CALLGL45(PFNGLNAMEDBUFFERSTORAGEPROC, "glNamedBufferStorage", buffer, size, data, flags); }

inline void glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL45(PFNGLCLEARNAMEDBUFFERDATAPROC, "glClearNamedBufferData", buffer, internalformat, format, type, data); }

inline void glCreateProgramPipelines(GLsizei n, GLuint * pipelines) { CALLGL45(PFNGLCREATEPROGRAMPIPELINESPROC, "glCreateProgramPipelines", n, pipelines); }

inline void glMemoryBarrierByRegion(GLbitfield barriers) { CALLGL45(PFNGLMEMORYBARRIERBYREGIONPROC, "glMemoryBarrierByRegion", barriers); }

inline void glBindTextureUnit(GLuint unit, GLuint texture) { CALLGL45(PFNGLBINDTEXTUREUNITPROC, "glBindTextureUnit", unit, texture); }

inline void glCreateTextures(GLenum target, GLsizei n, GLuint * textures) { CALLGL45(PFNGLCREATETEXTURESPROC, "glCreateTextures", target, n, textures); }

inline void glCreateSamplers(GLsizei n, GLuint * samplers) { CALLGL45(PFNGLCREATESAMPLERSPROC, "glCreateSamplers", n, samplers); }

inline void glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizei size)
	{ CALLGL45(PFNGLTEXTUREBUFFERRANGEPROC, "glTextureBufferRange", texture, internalformat, buffer, offset, size); }

inline void glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, 
								GLsizei bufSize, GLvoid * pixels)
	{ CALLGL45(PFNGLGETTEXTURESUBIMAGEPROC, "glGetTextureSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels); }

inline void glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, GLvoid * pixels) 
	{ CALLGL45(PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC, "glGetCompressedTextureSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels); }

inline void glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width)
	{ CALLGL45(PFNGLTEXTURESTORAGE1DPROC, "glTextureStorage1D", texture, levels, internalformat, width); }

inline void glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
	{ CALLGL45(PFNGLTEXTURESTORAGE2DPROC, "glTextureStorage2D", texture, levels, internalformat, width, height); }

inline void glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
	{ CALLGL45(PFNGLTEXTURESTORAGE3DPROC, "glTextureStorage3D", texture, levels, internalformat, width, height, depth); }

inline void glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
	{ CALLGL45(PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC, "glTextureStorage2DMultisample", texture, samples, internalformat, width, height, fixedsamplelocations); }

inline void glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
	{ CALLGL45(PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC, "glTextureStorage3DMultisample", texture, samples, internalformat, width, height, depth, fixedsamplelocations); }

inline void glCreateFramebuffers(GLsizei n, GLuint * ids) { CALLGL45(PFNGLCREATEFRAMEBUFFERSPROC, "glCreateFramebuffers", n, ids); }

inline void glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) { CALLGL45(PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC, "glNamedFramebufferParameteri", framebuffer, pname, param); }

inline void glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint * param)
	{ CALLGL45(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC, "glGetNamedFramebufferParameteriv", framebuffer, pname, param); }

inline void glCreateRenderbuffers(GLsizei n, GLuint * renderbuffers) { CALLGL45(PFNGLCREATERENDERBUFFERSPROC, "glCreateRenderbuffers", n, renderbuffers); }

inline void glTextureBarrier() { CALLGL45(PFNGLTEXTUREBARRIERPROC, "glTextureBarrier"); }

inline void glCreateVertexArrays(GLsizei n, GLuint * arrays) { CALLGL45(PFNGLCREATEVERTEXARRAYSPROC, "glCreateVertexArrays", n, arrays); }

inline void glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) { CALLGL45(PFNGLVERTEXARRAYELEMENTBUFFERPROC, "glVertexArrayElementBuffer", vaobj, buffer); }

inline void glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
	{ CALLGL45(PFNGLVERTEXARRAYATTRIBFORMATPROC, "glVertexArrayAttribFormat", vaobj, attribindex, size, type, normalized, relativeoffset); }

inline void glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	{ CALLGL45(PFNGLVERTEXARRAYATTRIBIFORMATPROC, "glVertexArrayAttribIFormat", vaobj, attribindex, size, type, relativeoffset); }

inline void glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	{ CALLGL45(PFNGLVERTEXARRAYATTRIBLFORMATPROC, "glVertexArrayAttribLFormat", vaobj, attribindex, size, type, relativeoffset); }

inline void glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
	{ CALLGL45(PFNGLVERTEXARRAYVERTEXBUFFERPROC, "glVertexArrayVertexBuffer", vaobj, bindingindex, buffer, offset, stride); }

inline void glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides) 
	{ CALLGL45(PFNGLVERTEXARRAYVERTEXBUFFERSPROC, "glVertexArrayVertexBuffers", vaobj, first, count, buffers, offsets, strides); }

inline void glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex)
	{ CALLGL45(PFNGLVERTEXARRAYATTRIBBINDINGPROC, "glVertexArrayAttribBinding", vaobj, attribindex, bindingindex); }

inline void glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) { CALLGL45(PFNGLVERTEXARRAYBINDINGDIVISORPROC, "glVertexArrayBindingDivisor", vaobj, bindingindex, divisor); }

inline void glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint * param) { CALLGL45(PFNGLGETVERTEXARRAYIVPROC, "glGetVertexArrayiv", vaobj, pname, param); }

inline void glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param)
	{ CALLGL45(PFNGLGETVERTEXARRAYINDEXED64IVPROC, "glGetVertexArrayIndexed64iv", vaobj, index, pname, param); }

inline void glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint * param)
	{ CALLGL45(PFNGLGETVERTEXARRAYINDEXEDIVPROC, "glGetVertexArrayIndexediv", vaobj, index, pname, param); }

inline void glCreateTransformFeedbacks(GLsizei n, GLuint * ids) { CALLGL45(PFNGLCREATETRANSFORMFEEDBACKSPROC, "glCreateTransformFeedbacks", n, ids); }

inline void glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizei size)
	{ CALLGL45(PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC, "glTransformFeedbackBufferRange", xfb, index, buffer, offset, size); }

inline void glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) { CALLGL45(PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC, "glTransformFeedbackBufferBase", xfb, index, buffer); }

inline void glClipControl(GLenum origin, GLenum depth) { CALLGL45(PFNGLCLIPCONTROLPROC, "glClipControl", origin, depth); }

inline void glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height)
	{ CALLGL45(PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC, "glInvalidateNamedFramebufferSubData", framebuffer, numAttachments, attachments, x, y, width, height); }

inline void glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments)
	{ CALLGL45(PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC, "glInvalidateNamedFramebufferData", framebuffer, numAttachments, attachments); }

inline void glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint * param) { CALLGL45(PFNGLGETTRANSFORMFEEDBACKIVPROC, "glGetTransformFeedbackiv", xfb, pname, param); }

inline void glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint * param) { CALLGL45(PFNGLGETTRANSFORMFEEDBACKI_VPROC, "glGetTransformFeedbacki_v", xfb, pname, index, param); }

inline void glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 *param) { CALLGL45(PFNGLGETTRANSFORMFEEDBACKI64_VPROC, "glGetTransformFeedbacki64_v", xfb, pname, index, param); }