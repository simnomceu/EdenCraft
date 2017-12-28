#ifndef WINDOW_SETTING_HPP
#define WINDOW_SETTING_HPP

#include <string>

#include "utility/mathematics/vector2u.hpp"

namespace ece
{
	class WindowSetting
	{
	public:
		WindowSetting() = default;
		WindowSetting(const WindowSetting & copy) = default;
		WindowSetting(WindowSetting && move) = default;

		~WindowSetting() = default;

		WindowSetting & operator=(const WindowSetting & copy) = default;
		WindowSetting & operator=(WindowSetting && move) = default;

		std::string title;
		IntVertex2u position;
		IntVertex2u minimumSize;
		IntVertex2u maximumSize;
	};
}

#endif // WINDOW_SETTING_HPP
