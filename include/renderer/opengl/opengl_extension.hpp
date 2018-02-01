#ifndef OPENGL_EXTENSION_HPP
#define OPENGL_EXTENSION_HPP

#include <string>
#include "GL/glcorearb.h"
#include "GL/glext.h"

inline GLenum glGetError();
inline const GLubyte * glGetString(GLenum name);

#include "renderer/opengl/opengl_extension.inl"

#endif // OPENGL_EXTENSION_HPP
