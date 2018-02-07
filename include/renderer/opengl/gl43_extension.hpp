#ifndef GL43_EXTENSION_HPP
#define GL43_EXTENSION_HPP

#include <GL/glcorearb.h>

void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid * data);
void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const GLvoid * data);
void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length);
void glInvalidateBufferData(GLuint buffer);
void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint * params);
GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar * name);
void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params);
GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar * name);
GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar * name);
void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
void glGetPointerv(GLenum pname, GLvoid ** params);
void glTexBufferRange(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
void glInvalidateTexImage(GLuint texture, GLint level);
void glFramebufferParameteri(GLenum target, GLenum pname, GLint param);
void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params);
void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLintptr stride);
void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex);
void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor);
void glMultiDrawArraysIndirect(GLenum mode, const GLvoid *indirect, GLsizei drawcount, GLsizei stride);
void glMultiDrawArraysIndirectCount(GLenum mode, const GLvoid *indirect, GLintptr drawcount, GLintptr maxdrawcount, GLsizei stride);
void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid *indirect, GLsizei drawcount, GLsizei stride);
void glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const GLvoid *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
void glDispatchComputeIndirect(GLintptr indirect);
void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLint width, GLint height);
void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments);
void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
void glDebugMessageCallback(GLDEBUGPROC callback, const GLvoid * userParam);
void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message);
void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar * message);
void glPopDebugGroup();
void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar * label);
void glObjectPtrLabel(GLvoid * ptr, GLsizei length, const GLchar * label);
GLuint glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bifSize, GLsizei * length, GLchar * label);
void glGetObjectPtrLabel(GLvoid * ptr, GLsizei bifSize, GLsizei * length, GLchar * label);
void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);

#include "renderer/opengl/gl43_extension.inl"

#endif // GL43_EXTENSION_HPP