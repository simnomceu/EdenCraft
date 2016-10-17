#ifndef WINDOWMANAGERBUILDER_HPP
#define WINDOWMANAGERBUILDER_HPP

#include "Core\WindowManagerNone.hpp"
#include "Core\WindowManagerGLFW.hpp"

namespace Utils
{
	class WindowManagerBuilder
	{
	public:

		template<class T, typename std::enable_if<std::is_base_of_v<WindowManager, T>>::type>
		static WindowManager * makeWindowManager();
	};
}

#endif // WINDOWMANAGERBUILDER_HPP
