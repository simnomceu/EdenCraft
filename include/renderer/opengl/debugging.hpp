#ifndef DEBUGGING_HPP
#define DEBUGGING_HPP

#include "GL/glcorearb.h"

namespace ece
{
#define checkErrors(func) \
	func; \
	checkErrors_(__FILE__, __LINE__, #func);

	void checkErrors_(const char * file, const int line, const char * function);
	void APIENTRY glDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);

}

#endif // DEBUGGING_HPP
