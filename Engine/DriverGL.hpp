#pragma once

#include <memory>

#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#include "GLFW\glfw3.h"
#pragma warning(pop)

namespace Utils
{
	class DriverGL
	{
	public:
		static std::shared_ptr<DriverGL> getInstance();
		~DriverGL();

		void initGLFW();
		void initGlew();
		void parametrizeContextGL();

		void terminateGLFW();

	private:

		bool glfwInitialized;
		bool glewInitialized;
		bool glParametrized;

		DriverGL();
		DriverGL(const DriverGL & copy) = delete;
		DriverGL(DriverGL && copy) = default;

		DriverGL & operator=(const DriverGL & rightOperand) = delete;
		DriverGL & operator=(DriverGL && rightOperand) = default;
	};
}