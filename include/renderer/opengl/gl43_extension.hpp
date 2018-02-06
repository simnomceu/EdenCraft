#ifndef GL43_EXTENSION_HPP
#define GL43_EXTENSION_HPP

#include <GL/glcorearb.h>

void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data);
void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length);
void glInvalidateBufferData(GLuint buffer);
void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint * params);
GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, const char * name);
void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, char * name);
void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params);
GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, const char * name);
GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const char * name);
void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
void glGetPointerv(GLenum pname, GLvoid ** params);

#endif // GL43_EXTENSION_HPP