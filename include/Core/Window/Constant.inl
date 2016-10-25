#ifndef CONSTANT_INL
#define CONSTANT_INL


#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#pragma warning(pop)

namespace ece
{
	// TODO change to remove GLFW couple
	const int GL_CLIENT_API_ECE = GLFW_OPENGL_API;
	const int GL_CONTEXT_CREATION_API_ECE = GLFW_NATIVE_CONTEXT_API;
	const unsigned short int GL_MAJOR_VERSION_ECE = 4;
	const unsigned short int GL_MINOR_VERSION_ECE = 5;
	const unsigned short int GL_CONTEXT_ROBUSTNESS_ECE = GLFW_NO_ROBUSTNESS;
	const unsigned short int GL_CONTEXT_RELEASE_BEHAVIOR_ECE = GLFW_ANY_RELEASE_BEHAVIOR;
	const unsigned short int GL_OPENGL_FORWARD_COMPAT_ECE = GLFW_FALSE;
	const unsigned short int GL_OPENGL_DEBUG_CONTEXT_ECE = GLFW_FALSE;
	const unsigned short int GL_OPENGL_PROFILE_ECE = GLFW_OPENGL_ANY_PROFILE;
	const unsigned short int DEFAULT_INTERVAL_SWAP_ECE = 0;

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
