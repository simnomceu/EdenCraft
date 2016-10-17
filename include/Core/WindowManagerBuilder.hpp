#ifndef WINDOWMANAGERBUILDER_HPP
#define WINDOWMANAGERBUILDER_HPP

#include "Core\WindowManagerNone.hpp"
#include "Core\WindowManagerGLFW.hpp"

namespace Utils
{
	class WindowManagerBuilder
	{
	public:
		enum ManagerType : unsigned short int
		{
			NONE = 0,
			GLFW = 1
		};

		static WindowManager * makeWindowManager(const ManagerType & type);
	};
}

#endif // WINDOWMANAGERBUILDER_HPP
