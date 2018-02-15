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