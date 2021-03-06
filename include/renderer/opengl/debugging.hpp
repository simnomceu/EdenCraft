#ifndef DEBUGGING_HPP
#define DEBUGGING_HPP

#include "GL/glcorearb.h"

namespace ece
{
	/**
	 * @fn checkErrors(func)
	 * @param[in] func The OpenGL call to check.
	 * @brief Carry out an opengl call and check possible errors.
	 * @throw
	 */
	#define checkErrors(func) \
		func; \
		checkErrors_(__FILE__, __LINE__, #func);

	/**
	 * @fn void checkErrors_(const char * file, const int line, const char * function)
	 * @param[in] file The source code file that do the opengl call.
	 * @param[in] line The line in the source code file that do the opengl call.
	 * @param[in] function The signature of the OpenGL call to check.
	 * @brief Carry out an opengl call and check possible errors.
	 * @throw
	 */
	void checkErrors_(const char * file, const int line, const char * function);

	/**
	 * @fn void APIENTRY glDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
	 * @param[in] source The source of the message.
	 * @param[in] type The type of message.
	 * @param[in] id The id of the message.
	 * @param[in] severity The severity of the message.
	 * @param[in] length The size of the message.
	 * @param[in] message The content of the message.
	 * @param[in] userParam Some additionals informations.
	 * @brief Callback use by OpenGL when a debug message is caught.
	 * @throw
	 */
	void APIENTRY glDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);

}

#endif // DEBUGGING_HPP
