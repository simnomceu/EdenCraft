#ifndef WINDOWMANAGERBUILDER_HPP
#define WINDOWMANAGERBUILDER_HPP

#include "Core\Window\WindowManager.hpp"

namespace ece
{
	class WindowManagerBuilder
	{
	public:

		template<class T>
		static WindowManager * makeWindowManager();
	};

	template<class T>
	WindowManager * WindowManagerBuilder::makeWindowManager()
	{
		if (!std::is_base_of<WindowManager, T>()) {
			throw std::exception("This class cannot be instantiate as a WindowManager service. Check again.");
		}
		return new T();
	}
}

#endif // WINDOWMANAGERBUILDER_HPP
