#ifndef GL46_EXTENSION_HPP
#define GL46_EXTENSION_HPP

#include <GL/glcorearb.h>

#include "utility/indexing/version.hpp"
#include "renderer/opengl/extension_loader.hpp"
#include "renderer/opengl/opengl_exception.hpp"

inline void glSpecializeShader(GLuint shader, const GLchar *pEntryPoint​, GLuint numSpecializationConstants​, const GLuint *pConstantIndex​, const GLuint *pConstantValue​);
inline void glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp);

#define CALLGL46(SIGNATURE, NAME, ...) \
	static auto proxy = ece::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 6 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy(__VA_ARGS__);

#include "renderer/opengl/gl46_extension.inl"

#endif // GL46_EXTENSION_HPP