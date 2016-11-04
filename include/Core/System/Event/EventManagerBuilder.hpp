#ifndef EVENTMANAGERBUILDER_HPP
#define EVENTMANAGERBUILDER_HPP

#include <memory>

namespace ece
{
	class EventManagerBuilder
	{
	public:
		template <class T>
		static std::shared_ptr<BaseEventManager> makeEventManager();
	};

	template <class T>
	std::shared_ptr<BaseEventManager> EventManagerBuilder::makeEventManager()
	{
		if (!std::is_base_of<BaseEventManager, T>()) {
			throw std::exception("This class cannot be instantiate as a BaseEventManager service. Check again.");
		}
		return std::shared_ptr<BaseEventManager>(new T());
	}
}

#endif // EVENTMANAGERBUILDER_HPP
