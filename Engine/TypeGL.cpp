#include "TypeGL.hpp"



template<class T>
int TypeGL::whatIsIt()
{
	std::cerr << "This type of data cannot be recognized for now." << std::endl;
	return -1;
}

template<>
int TypeGL::whatIsIt<GLint>()
{
	return GL_INT;
}

template<>
int TypeGL::whatIsIt<GLuint>()
{
	return GL_UNSIGNED_INT;
}

template<>
int TypeGL::whatIsIt<GLfloat>()
{
	return GL_FLOAT;
}

template<>
int TypeGL::whatIsIt<GLdouble>()
{
	return GL_DOUBLE;
}