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

		std::string _title;
		IntVertex2u _position;
		IntVertex2u _minimumSize;
		IntVertex2u _maximumSize;
	};
}

#endif // WINDOW_SETTING_HPP
