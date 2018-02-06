#ifndef OPENGL_EXTENSION_HPP
#define OPENGL_EXTENSION_HPP

#include <string>
#include "GL/glcorearb.h"
#include "GL/glext.h"

inline GLenum glGetError();
inline void glClear(GLbitfield mask);
inline void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
inline const GLubyte * glGetString(GLenum name);
inline void glGetIntegerv(GLenum pname, GLint * data);
inline void glGenBuffers(GLsizei n, GLuint * buffers);
inline void glBindBuffer(GLenum target, GLuint buffer);
inline void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);

inline GLuint glCreateProgram();

inline void glEnable(GLenum cap);
inline void glDisable(GLenum cap);
inline void glEnablei(GLenum cap, GLuint index);
inline void glDisablei(GLenum cap, GLuint index);

inline void glCullFace(GLenum mode);
inline void glFrontFace(GLenum mode);
inline void glDepthFunc(GLenum func);

inline GLuint glCreateShader(GLenum shaderType);
inline void glShaderSource(GLuint shader, GLsizei count, const GLchar ** string, const GLint * length);
inline void glCompileShader(GLuint shader);
inline void glDeleteShader(GLuint shader);
inline void glAttachShader(GLuint program, GLuint shader);
inline void glLinkProgram(GLuint program);
inline void glUseProgram(GLuint program);

inline void glGenVertexArrays(GLsizei n, GLuint *arrays);
inline void glBindVertexArray(GLuint array);
inline void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
inline void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
inline void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
inline void glEnableVertexAttribArray(GLuint index);
inline void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);

#include "renderer/opengl/opengl_extension.inl"

#endif // OPENGL_EXTENSION_HPP
