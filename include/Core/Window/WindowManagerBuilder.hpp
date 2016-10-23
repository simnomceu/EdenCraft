#ifndef WINDOWMANAGERBUILDER_HPP
#define WINDOWMANAGERBUILDER_HPP

#include "Core\Window\WindowManagerNone.hpp"
#include "Core\Window\WindowManagerGLFW.hpp"

namespace Utils
{
	class WindowManagerBuilder
	{
	public:

		template<class T, typename std::enable_if<std::is_base_of<WindowManager, T>::value>::type>
		static WindowManager * makeWindowManager();
	};
}

#endif // WINDOWMANAGERBUILDER_HPP
