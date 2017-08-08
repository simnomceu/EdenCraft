#ifndef GLFW_HPP
#define GLFW_HPP

#include "glfw\glfw3.h"

namespace ece
{
	const int GL_CLIENT_API_ECE = GLFW_OPENGL_API;
	const int GL_CONTEXT_CREATION_API_ECE = GLFW_NATIVE_CONTEXT_API;
	const unsigned short int GL_MAJOR_VERSION_ECE = 4;
	const unsigned short int GL_MINOR_VERSION_ECE = 3;
	const unsigned short int GL_CONTEXT_ROBUSTNESS_ECE = GLFW_NO_ROBUSTNESS;
	const unsigned short int GL_CONTEXT_RELEASE_BEHAVIOR_ECE = GLFW_ANY_RELEASE_BEHAVIOR;
	const unsigned short int GL_OPENGL_FORWARD_COMPAT_ECE = GLFW_FALSE;
	const unsigned short int GL_OPENGL_DEBUG_CONTEXT_ECE = GLFW_FALSE;
	const unsigned short int GL_OPENGL_PROFILE_ECE = GLFW_OPENGL_ANY_PROFILE;
	const unsigned short int DEFAULT_INTERVAL_SWAP_ECE = 0;

	class GLFW
	{
	public:
		GLFW();
		GLFW(const GLFW & copy) = delete;
		GLFW(GLFW && move) = delete;

		~GLFW();

		GLFW & operator=(const GLFW & copy) = delete;
		GLFW & operator=(GLFW && move) = delete;

		void init();
		bool isInit();

		void parametrizeContext();

	private:
		bool initialized;
	};
}

#endif // GLFW_HPP