#ifndef GL46_EXTENSION_HPP
#define GL46_EXTENSION_HPP

#include <GL/glcorearb.h>

void glSpecializeShader(GLuint shader​, const GLchar *pEntryPoint​, GLuint numSpecializationConstants​, const GLuint *pConstantIndex​, const GLuint *pConstantValue​);

#endif // GL46_EXTENSION_HPP