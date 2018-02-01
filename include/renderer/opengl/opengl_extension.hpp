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

inline GLuint glCreateProgram();

inline void glEnable(GLenum cap);
inline void glDisable(GLenum cap);
inline void glEnablei(GLenum cap, GLuint index);
inline void glDisablei(GLenum cap, GLuint index);

inline void glCullFace(GLenum mode);
inline void glFrontFace(GLenum mode);
inline void glDepthFunc(GLenum func);

#include "renderer/opengl/opengl_extension.inl"

#endif // OPENGL_EXTENSION_HPP
