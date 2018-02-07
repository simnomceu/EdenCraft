#ifndef GL46_EXTENSION_HPP
#define GL46_EXTENSION_HPP

#include <GL/glcorearb.h>

inline void glSpecializeShader(GLuint shader​, const GLchar *pEntryPoint​, GLuint numSpecializationConstants​, const GLuint *pConstantIndex​, const GLuint *pConstantValue​);
inline void glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp);

#include "renderer/opengl/gl46_extension.inl"

#endif // GL46_EXTENSION_HPP