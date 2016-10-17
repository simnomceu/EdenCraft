#include "Core\WindowManagerBuilder.hpp"

namespace Utils
{
	template<class T, typename std::enable_if<std::is_base_of_v<WindowManager, T>>::type>
	WindowManager * WindowManagerBuilder::makeWindowManager()
	{
		return new T();
	}
}