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


inline void glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLintptr *sizes)
	{ CALLGL44_V(PFNGLBINDBUFFERSRANGEPROC, "glBindBuffersRange", target, first, count, buffers, offsets, sizes); }

inline void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint *buffers) { CALLGL44_V(PFNGLBINDBUFFERSBASEPROC, "glBindBuffersBase", target, first, count, buffers); }

inline void glBufferStorage(GLenum target, GLsizeiptr size, const GLvoid * data, GLbitfield flags) { CALLGL44_V(PFNGLBUFFERSTORAGEPROC, "glBufferStorage", target, size, data, flags); }

inline void glBindTextures(GLuint first, GLsizei count, const GLuint *textures) { CALLGL44_V(PFNGLBINDTEXTURESPROC, "glBindTextures", first, count, textures); }

inline void glBindSamplers(GLuint first, GLsizei count, const GLuint *samplers) { CALLGL44_V(PFNGLBINDSAMPLERSPROC, "glBindSamplers", first, count, samplers); }

inline void glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * data)
	{ CALLGL44_V(PFNGLCLEARTEXSUBIMAGEPROC, "glClearTexSubImage", texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data); }

inline void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const GLvoid * data) { CALLGL44_V(PFNGLCLEARTEXIMAGEPROC, "glClearTexImage", texture, level, format, type, data); }

inline void glBindImageTextures(GLuint first, GLsizei count, const GLuint *textures) { CALLGL44_V(PFNGLBINDIMAGETEXTURESPROC, "glBindImageTextures", first, count, textures); }

inline void glBindVertexBuffers(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides)
	{ CALLGL44_V(PFNGLBINDVERTEXBUFFERSPROC, "glBindVertexBuffers", first, count, buffers, offsets, strides); }
