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
		return std::shared_ptr<BaseEventManager>(new T());
	}
}

#endif // EVENTMANAGERBUILDER_HPP
