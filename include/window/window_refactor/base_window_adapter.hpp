#ifndef BASE_WINDOW_ADAPTER_HPP
#define BASE_WINDOW_ADAPTER_HPP

#include <memory>
#include <string>

namespace ece
{
	class BaseWindowAdapter
	{
	public:
		BaseWindowAdapter() = default;
		BaseWindowAdapter(const BaseWindowAdapter & copy) = default;
		BaseWindowAdapter(BaseWindowAdapter && move) = default;

		virtual ~BaseWindowAdapter() = 0;

		BaseWindowAdapter & operator=(const BaseWindowAdapter & copy) = default;
		BaseWindowAdapter & operator=(BaseWindowAdapter && move) = default;

		virtual void createWindow() = 0;
		virtual void deleteWindow() = 0;
		virtual bool isWindowCreated() const = 0;

		virtual void setTitle(const std::string & title) = 0;
	private:
	};
}

#endif // BASE_WINDOW_ADAPTER_HPP
