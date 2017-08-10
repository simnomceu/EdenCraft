#ifndef CONSTANT_INL
#define CONSTANT_INL


#pragma warning(push)
#pragma warning(disable : 4505)
#include "gl/glew.h"
#include "glfw/glfw3.h"
#pragma warning(pop)

namespace ece
{
	// TODO change to remove GLFW couple

	const unsigned short int DEFAULT_REFRESH_RATE_ECE = 60;
	const unsigned short int DEFAULT_RED_BITS_ECE = GL_RED_BITS;
	const unsigned short int DEFAULT_GREEN_BITS_ECE = GL_GREEN_BITS;
	const unsigned short int DEFAULT_BLUE_BITS_ECE = GL_BLUE_BITS;
	const unsigned short int DEFAULT_ALPHA_BITS_ECE = GL_ALPHA_BITS;
	const unsigned short int DEFAULT_DEPTH_BITS_ECE = GL_DEPTH_BITS;
	const unsigned short int DEFAULT_STENCIL_BITS_ECE = GL_STENCIL_BITS;
	const unsigned short int DEFAULT_SAMPLES_ECE = GL_NONE;
	const unsigned short int DEFAULT_STEREO_ECE = GL_FALSE;
	const bool DEFAULT_DOUBLE_BUFFERING_ECE = GL_TRUE;
	const bool DEFAULT_SRGB_CAPABLE_ECE = GL_FALSE;
}

#endif
